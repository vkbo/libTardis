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

Lanczos::Lanczos(System *oSys, Basis *oBas) {

    oSystem = oSys;
    oBasis  = oBas;

    iStates    = oSystem->GetStates();
    iParticles = oSystem->GetParticles();

    iBasisDim  = oBasis->GetSize();

    return;
}

/*
** Public :: Functions
*/

double Lanczos::Run(int iM, int iMs, double dOmega, double dLambda, const char* sOutput) {

    // Log file
    ofstream oLog;
    bool     bLog = false;

    if(strlen(sOutput) > 0) bLog = true;
    if(bLog) oLog.open(sOutput, ios::app);

    // Lambda or Omega values
    double d1PFac, d2PFac;

    if(dOmega != 0.0) {
        d1PFac = dOmega;
        d2PFac = sqrt(dOmega);
    } else {
        if(dLambda != 0.0) {
            d1PFac = 1.0;
            d2PFac = dLambda;
        } else {
            d1PFac = 1.0;
            d2PFac = 0.0;
        }
    }

    iM  = abs(iM);  // iM  = -iM
    iMs = abs(iMs); // iMs = -iMs

    if(iBasisDim == 0) {
        cout          << "Basis has dimension 0 ..." << endl;
        if(bLog) oLog << "Basis has dimension 0 ..." << endl;
        return -1.0;
    }

    if(iStates > SLATER_WORD) {
        cout          << "Error: SLATER_WORD in libTardis.hpp too small, must be at least " << (ceil(iStates/64.0)*64) << " ..." << endl;
        if(bLog) oLog << "Error: SLATER_WORD in libTardis.hpp too small, must be at least " << (ceil(iStates/64.0)*64) << " ..." << endl;
        return -1.0;
    }

    cout          << "Dimension of basis: " << iBasisDim << endl << endl;
    if(bLog) oLog << "Dimension of basis: " << iBasisDim << endl << endl;

    /*
    ** Initializing
    */

    // Lanczos vectors
    if(USE_RAND_SEED) srand(time(NULL));
    Col<double> mV;
    Col<double> mW;
    mV.zeros(iBasisDim);
    mW.randu(iBasisDim);
    mW = mW/norm(mW,2);

    // Runtime variables
    int    i, k, p, q, r, s;
    int    iS1, iS2, iS3, iS4, iL=0;
    //long   lCCount = 0;
    double dTemp, dV, dO;
    Slater sdPhiPQRS, sdPhiQRS, sdPhiSR, sdPhiR;
    Row<double> mA;
    Row<double> mB;
    Row<double> mE;
    mA.ones(1);
    mB.ones(1);
    mE.zeros(1);
    k = 0;

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
        #pragma omp parallel for private(p,q,r,s) \
                                 private(iS1,iS2,iS3,iS4) \
                                 private(sdPhiPQRS,sdPhiQRS,sdPhiSR,sdPhiR) \
                                 private(iL,dV) \
                                 schedule(dynamic,1)

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
                                if(p == r && q == s) dV += oSystem->Get1PElement(p,s)*d1PFac; // 1-particle interaction
                                dV += oSystem->Get2PElement(p,q,r,s)*d2PFac;                  // 2-particle interaction
                                #pragma omp critical
                                mV(iL) += iS1*iS2*iS3*iS4*dV*mW(i);
                            }
                        }
                    }
                }
            }

            if(omp_get_thread_num() == 0) {
                if(iBasisDim > 100 && i%10 == 9) {
                    fflush(stdout);
                    cout << "\r                                ";
                    cout << "\rCalculating SD: " << i+1;
                }
            }
        }

        // Prepere next iteration
        k++;
        mA.insert_cols(k,1);
        mB.insert_cols(k,1);
        mE.insert_cols(k,1);
        mA(k) = dot(mW,mV);
        mV   -= mA(k)*mW;
        mB(k) = norm(mV,2);

        // Ortonomalization of the Lanczos vectors
        dO = dot(mV,mW);
        if(abs(dO) > 2e-13) {
            mV -= (dO/dot(mW,mW))*mW;
            mV/norm(mV,2);
            mW/norm(mW,2);
            cout          << "\r                         ";
            cout          << "\rRe-ortonormalizing. V·W = " << setprecision(3) << dO << endl;
            if(bLog) oLog <<   "Re-ortonormalizing. V·W = " << setprecision(3) << dO << endl;
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
        if(abs(mE(k-1) - mE(k)) < LANCZOS_CONVERGE) break;

        fflush(stdout);
        cout          << "\r                         ";
        cout          << "\rLanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl;
        if(bLog) oLog <<   "Lanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl;
    }

    cout          << "\r                         ";
    cout          << "\rLanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl << endl;
    if(bLog) oLog <<   "Lanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl << endl;

    cout          << "Eigenvalues:" << endl;
    if(bLog) oLog << "Eigenvalues:" << endl;
    cout          << mEnergy << endl;
    if(bLog) oLog << mEnergy << endl;

    if(bLog) oLog.close();

    return mEnergy(0);
}

/*
** Public :: Getters, Setters and Output
*/

/*
** Private :: Functions
*/
