/*
** ~ libTardis ~
**
** Class :: Lanczos
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
** Public :: Constructor and Destructor
*/

Lanczos::Lanczos(System *oSys) {

    oSystem = oSys;
    oBasis  = oSystem->GetBasis();
    oPot    = oSystem->GetPotential();
    oOut    = oSystem->GetLog();

    iStates    = oSystem->GetStates();
    iParticles = oSystem->GetParticles();
    iBasisDim  = oBasis->GetSize();
    d1PFac     = oSystem->GetVariable(VAR_1PFAC);
    d2PFac     = oSystem->GetVariable(VAR_2PFAC);

    return;
}

/*
** Public :: Functions
*/

double Lanczos::Run() {

    // Check for illegal values

    if(iBasisDim == 0) {
        ssOut << "Basis has dimension 0 ..." << endl;
        oOut->Output(&ssOut);
        return -1.0;
    }

    if(iStates > SLATER_WORD) {
        ssOut << "Error: SLATER_WORD in libTardis.hpp too small, must be at least " << (ceil(iStates/64.0)*64) << " ..." << endl;
        oOut->Output(&ssOut);
        return -1.0;
    }

    // 1-Particle Hamiltonian scale factor
    d1PFac *= 1.0/(iParticles-1);

    /*
    ** Initializing Lanczos
    */

    // Lanczos vectors
    if(USE_RAND_SEED) srand(time(NULL));
    Col<double> mT;
    Col<double> mV;
    Col<double> mW;
    mV.zeros(iBasisDim);
    mW.randu(iBasisDim);
    mW = mW/norm(mW,2);

    // Runtime variables
    int    i, k=0;
    double dTemp, dO, dConv;
    Row<double> mA;
    Row<double> mB;
    Row<double> mE;
    mA.ones(1);
    mB.ones(1);
    mE.zeros(1);

    // Eigenvector variables
    Mat<double>    mTemp;
    Mat<double>    mHDiag;
    Col<double>    mEnergy;
    Col<cx_double> mHEigVal;
    Mat<cx_double> mHEigVec;

    /*
    ** The Lanczos algorithm
    ** Source: Golub/Van Loan - Matrix Computations Third Edition, Page 480
    */

    while(abs(mB(k)) > 1e-9 && k < iBasisDim && k < 200) {

        if(k > 0) {
            for(i=0; i<iBasisDim; i++) {
                dTemp = mW(i);
                mW(i) = mV(i)/mB(k);
                mV(i) = -mB(k)*dTemp;
            }
        }

        // Applying the Hamiltonian
        mT.zeros(iBasisDim);
        fMatrixVector(mW,mT,d1PFac,d2PFac);
        mV += mT;

        // Prepere next iteration
        k++;
        mA.insert_cols(k,1);
        mB.insert_cols(k,1);
        mE.insert_cols(k,1);
        mA(k) = dot(mW,mV);
        mV   -= mA(k)*mW;
        mB(k) = norm(mV,2);

        // Re-ortonomalization of the Lanczos vectors
        dO = dot(mV,mW);
        if(abs(dO) > 2e-13) {
            mV -= (dO/dot(mW,mW))*mW;
            mV/norm(mV,2);
            mW/norm(mW,2);
            cout  << "\r                         \r";
            ssOut << "Re-ortonormalizing. V·W = " << setprecision(3) << dO << endl;
            oOut->Output(&ssOut);
        }

        // Building the tri-diagonal matrix
        mTemp.zeros(k,k);
        for(i=0; i<k; i++) {
            mTemp(i,i) = mA(i+1);
            if(i<k-1) {
                mTemp(i,i+1) = mB(i+1);
                mTemp(i+1,i) = mB(i+1);
            }
        }

        // Calculating eigenvalues
        eig_gen(mHEigVal, mHEigVec, mTemp);
        mHDiag  = real(inv(mHEigVec)*mTemp*mHEigVec);
        mEnergy = sort(mHDiag.diag());
        mE(k) = mEnergy(0);

        // Checking for energy convergence
        dConv = abs(abs(mE(k-1)/mE(k))-1);

        fflush(stdout);
        cout  << "\r                              \r";
        ssOut << "Lanczos Iteration " << setw(2) << k;
        ssOut << " : Energy = " << showpoint << setw(11) << setprecision(10) << mE(k);
        ssOut << " : Convergence = " << setprecision(3) << dConv << endl;
        oOut->Output(&ssOut);

        if(dConv < LANCZOS_CONVERGE) break;
    }

    ssOut << endl;
    ssOut << "Eigenvalues:" << endl;
    ssOut << mEnergy << endl;
    oOut->Output(&ssOut);

    return mEnergy(0);
}

/*
** Private :: Functions
*/

/*
** Matrix-Vector multiplication section of the Lanczos algorithm
*/

void Lanczos::fMatrixVector(Col<double> &mInput, Col<double> &mReturn, double d1PFac, double d2PFac) {

    int    i, p, q, r, s;
    int    iS1, iS2, iS3, iS4, iL=0;
    double dV;
    Slater sdPhiPQRS, sdPhiQRS, sdPhiSR, sdPhiR;

    #ifdef OPENMP
        #pragma omp parallel for private(p,q,r,s,iS1,iS2,iS3,iS4,sdPhiPQRS,sdPhiQRS,sdPhiSR,sdPhiR,iL,dV) schedule(dynamic,1)
    #endif
    for(i=0; i<iBasisDim; i++) {
        for(r=0; r<iStates; r++) {
            sdPhiR = oBasis->GetSlater(i);
            iS1 = sdPhiR.Annihilate(r);
            if(iS1 == 0) continue;
            for(s=r+1; s<iStates; s++) {
                sdPhiSR = sdPhiR;
                iS2 = sdPhiSR.Annihilate(s);
                if(iS2 == 0) continue;
                for(q=0; q<iStates; q++) {
                    sdPhiQRS = sdPhiSR;
                    iS3 = sdPhiQRS.Create(q);
                    if(iS3 == 0) continue;
                    for(p=0; p<q; p++) {
                        sdPhiPQRS = sdPhiQRS;
                        iS4 = sdPhiPQRS.Create(p);
                        if(iS4 == 0) continue;
                        iL = oBasis->FindSlater(sdPhiPQRS,p,q);
                        if(iL > -1) {
                            dV = 0.0;
                            if(p == r && q == s) dV += oPot->Get1PElement(p,s)*d1PFac; // 1-particle interaction
                            dV += oPot->Get2PElement(p,q,r,s)*d2PFac;                  // 2-particle interaction
                            #ifdef OPENMP
                                #pragma omp critical
                            #endif
                            mReturn(iL) += iS1*iS2*iS3*iS4*dV*mInput(i);
                        }
                    }
                }
            }
        }

        #ifdef PROGRESS
            #ifdef OPENMP
            if(omp_get_thread_num() == 0) {
            #endif
                if(iBasisDim > 100 && i%10 == 9) {
                    fflush(stdout);
                    cout << "\r                                ";
                    cout << "\rCalculating SD: " << i+1;
                }
            #ifdef OPENMP
            }
            #endif
        #endif
    }

    return;
}
