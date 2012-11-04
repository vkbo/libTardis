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
    d1PFac    *= 1.0/(iParticles-1);

    return;
}

/*
** Public :: Functions
*/

double Lanczos::Run(int iCoeffMode) {

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

    /*
    ** Initializing Lanczos
    */

    #ifdef OPENMP
        int iMaxThreads = omp_get_max_threads();
        #ifdef OPENMPLOWMEM
            iMaxThreads = ceil(iMaxThreads/2.0);
        #endif
    #else
        int iMaxThreads = 1;
    #endif

    // Lanczos vectors
    if(LANCZOS_SEED) srand(time(NULL));
    vector<vector<double> > vT(iMaxThreads);
    mLzV.zeros(iBasisDim);
    mLzW.randu(iBasisDim);
    mLzW = mLzW/norm(mLzW,2);

    // Runtime variables
    double dTemp, dO, dConv=1.0, dConvPrev=1.0;
    mLzA.ones(1);
    mLzB.ones(1);
    mLzE.zeros(1);

    // Eigenvector variables
    Mat<double>    mTemp;
    Col<cx_double> mHEigVal;
    Mat<cx_double> mHEigVec;

    /*
    ** The Lanczos algorithm
    ** Source: Golub/Van Loan - Matrix Computations Third Edition, Page 480
    */

    if(iCoeffMode == LZ_COEFF_CALC || iCoeffMode == LZ_COEFF_CALC_CH) mFullLz.set_size(iBasisDim,1);

    iLzIt = 0;
    while(abs(mLzB(iLzIt)) > LANCZOS_ZERO && iLzIt < iBasisDim && iLzIt < LANCZOS_MAX_IT) {

        if(iLzIt > 0) {
            for(int i=0; i<iBasisDim; i++) {
                dTemp   = mLzW(i);
                mLzW(i) = mLzV(i)/mLzB(iLzIt);
                mLzV(i) = -mLzB(iLzIt)*dTemp;
            }
            if(iCoeffMode == LZ_COEFF_CALC || iCoeffMode == LZ_COEFF_CALC_CH) mFullLz.insert_cols(iLzIt,1);
        }
        if(iCoeffMode == LZ_COEFF_CALC  || iCoeffMode == LZ_COEFF_CALC_CH) mFullLz.col(iLzIt) = mLzW;
        if(iCoeffMode == LZ_COEFF_CACHE || iCoeffMode == LZ_COEFF_CALC_CH) {
            stringstream ssFile;
            ssFile << "LanczosVec" << setfill('0') << setw(3) << iLzIt << ".arma";
            mLzW.save(ssFile.str());
        }

        // Applying the Hamiltonian
        for(int i=0; i<iMaxThreads; i++) vT[i].resize(iBasisDim,0);
        fMatrixVector(mLzW, vT, d1PFac, d2PFac, 0, iBasisDim);
        for(int i=0; i<iMaxThreads; i++) mLzV += conv_to< colvec >::from(vT[i]);
        for(int i=0; i<iMaxThreads; i++) vT[i].clear();

        // Prepare next iteration
        iLzIt++;
        mLzA.insert_cols(iLzIt,1);
        mLzB.insert_cols(iLzIt,1);
        mLzE.insert_cols(iLzIt,1);
        mLzA(iLzIt) = dot(mLzW,mLzV);
        mLzV       -= mLzA(iLzIt)*mLzW;
        mLzB(iLzIt) = norm(mLzV,2);

        // Re-ortonomalization of the Lanczos vectors
        dO = dot(mLzV,mLzW);
        if(abs(dO) > 2e-13) {
            mLzV -= (dO/dot(mLzW,mLzW))*mLzW;
            mLzV/norm(mLzV,2);
            mLzW/norm(mLzW,2);
            #ifndef MINIMAL
                #ifdef PROGRESS
                    cout  << "\r                         \r";
                #endif
                ssOut << "Re-ortonormalizing. V·W = " << setprecision(3) << dO << endl;
                oOut->Output(&ssOut);
            #endif
        }

        // Building the tri-diagonal matrix
        mTemp.zeros(iLzIt,iLzIt);
        for(int i=0; i<iLzIt; i++) {
            mTemp(i,i) = mLzA(i+1);
            if(i<iLzIt-1) {
                mTemp(i,i+1) = mLzB(i+1);
                mTemp(i+1,i) = mLzB(i+1);
            }
        }

        // Calculating eigenvalues
        eig_gen(mHEigVal, mHEigVec, mTemp);
        mEnergy = sort(real(mHEigVal));
        mLzE(iLzIt) = mEnergy(0);

        // Checking for energy convergence
        dConvPrev = dConv;
        dConv     = abs(abs(mLzE(iLzIt-1)/mLzE(iLzIt))-1);

        #ifndef MINIMAL
            fflush(stdout);
            #ifdef PROGRESS
                cout  << "\r                              \r";
            #endif
            ssOut << "Lanczos Iteration " << setw(2) << iLzIt;
            ssOut << " : Energy = " << showpoint << setw(11) << setprecision(10) << mLzE(iLzIt);
            ssOut << " : Convergence = " << setprecision(3) << dConv << endl;
            oOut->Output(&ssOut);
        #else
            fflush(stdout);
            #ifdef PROGRESS
                cout << "\r                                                                        \r";
            #endif
            cout << "Lanczos Iteration " << setw(2) << iLzIt;
            cout << " : Energy = " << showpoint << setw(11) << setprecision(10) << mLzE(iLzIt);
            cout << " : Convergence = " << setprecision(3) << dConv;
        #endif

        if(dConv < LANCZOS_CONVERGE) break;
        if(LANCZOS_STRICT && iLzIt > 1 && dConv > dConvPrev && abs(dConv/dConvPrev) > LANCZOS_DIVERGE) {
            ssOut << "Warning: Lanczos Divergence > " << floor(LANCZOS_DIVERGE*100) << "%. Breaking ..." << endl;
            oOut->Output(&ssOut);
            break;
        }
    }

    #ifndef MINIMAL
        ssOut << endl;
        ssOut << "Eigenvalues:" << endl;
        ssOut << mEnergy << endl;
        oOut->Output(&ssOut);
    #else
        cout << endl;
    #endif

    if(iCoeffMode == LZ_COEFF_CALC || iCoeffMode == LZ_COEFF_CALC_CH) {
        Col<unsigned int> mIndex = sort_index(real(mHEigVal));
        Col<double>       mEigen = real(mHEigVec.col(mIndex(0)));
        Col<double>       mCoeff = mFullLz*mEigen;
        oBasis->SetCoefficients(mCoeff);
    }

    mLzW.clear();
    mLzV.clear();
    mLzA.clear();
    mLzB.clear();
    mLzC.clear();
    mLzE.clear();
    mFullLz.clear();

    return mEnergy(0);
}

int Lanczos::RunSlave(Col<double> &mInput, vector<double> &vReturn, int iLStart, int iLStop) {

    #ifdef OPENMP
        int iMaxThreads = omp_get_max_threads();
        #ifdef OPENMPLOWMEM
            iMaxThreads = ceil(iMaxThreads/2.0);
        #endif
    #else
        int iMaxThreads = 1;
    #endif
    for(int i=0; i<iBasisDim; i++) vReturn[i] = 0.0;

    vector<vector<double> > vT(iMaxThreads);
    for(int i=0; i<iMaxThreads; i++) vT[i].resize(iBasisDim,0);

    fMatrixVector(mInput, vT, d1PFac, d2PFac, iLStart, iLStop);

    for(int i=0; i<iMaxThreads; i++) {
        for(int j=0; j<iBasisDim; j++) vReturn[j] += vT[i][j];
    }
    for(int i=0; i<iMaxThreads; i++) vT[i].clear();

    return 0;
}

int Lanczos::RunInit() {

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

    // Init Lanczos Variables
    if(LANCZOS_SEED) srand(time(NULL));
    mLzV.zeros(iBasisDim);
    mLzW.randu(iBasisDim);
    mLzW = mLzW/norm(mLzW,2);
    mLzA.ones(1);
    mLzB.ones(1);
    mLzC.ones(1);
    mLzE.zeros(1);

    iLzIt = 0;

    return 0;
}

int Lanczos::RunMaster() {

    // Runtime variables
    bool           bDone = false;
    double         dTemp, dO;
    Mat<double>    mTemp;
    Col<cx_double> mHEigVal;
    Mat<cx_double> mHEigVec;

    // Prepare next iteration
    iLzIt++;
    mLzA.insert_cols(iLzIt,1);
    mLzB.insert_cols(iLzIt,1);
    mLzC.insert_cols(iLzIt,1);
    mLzE.insert_cols(iLzIt,1);
    mLzA(iLzIt) = dot(mLzW,mLzV);
    mLzV       -= mLzA(iLzIt)*mLzW;
    mLzB(iLzIt) = norm(mLzV,2);

    // Re-ortonomalization of the Lanczos vectors
    dO = dot(mLzV,mLzW);
    if(abs(dO) > 2e-13) {
        mLzV -= (dO/dot(mLzW,mLzW))*mLzW;
        mLzV/norm(mLzV,2);
        mLzW/norm(mLzW,2);
        #ifndef MINIMAL
            #ifdef PROGRESS
                cout  << "\r                         \r";
            #endif
            ssOut << "Re-ortonormalizing. V·W = " << setprecision(3) << dO << endl;
            oOut->Output(&ssOut);
        #endif
    }

    // Building the tri-diagonal matrix
    mTemp.zeros(iLzIt,iLzIt);
    for(int i=0; i<iLzIt; i++) {
        mTemp(i,i) = mLzA(i+1);
        if(i<iLzIt-1) {
            mTemp(i,i+1) = mLzB(i+1);
            mTemp(i+1,i) = mLzB(i+1);
        }
    }

    // Calculating eigenvalues
    eig_gen(mHEigVal, mHEigVec, mTemp);
    mEnergy = sort(real(mHEigVal));
    mLzE(iLzIt) = mEnergy(0);

    // Checking for energy convergence
    mLzC(iLzIt) = abs(abs(mLzE(iLzIt-1)/mLzE(iLzIt))-1);

    #ifndef MINIMAL
        #ifdef PROGRESS
            fflush(stdout);
            cout  << "\r                              \r";
        #endif
        ssOut << "Lanczos Iteration " << setw(2) << iLzIt;
        ssOut << " : Energy = " << showpoint << setw(11) << setprecision(10) << mLzE(iLzIt);
        ssOut << " : Convergence = " << setprecision(3) << mLzC(iLzIt) << endl;
        oOut->Output(&ssOut);
    #else
        #ifdef PROGRESS
            fflush(stdout);
            cout << "\r                                                                        \r";
            cout << "Lanczos Iteration " << setw(2) << iLzIt;
            cout << " : Energy = " << showpoint << setw(11) << setprecision(10) << mLzE(iLzIt);
            cout << " : Convergence = " << setprecision(3) << mLzC(iLzIt);
        #endif
    #endif

    // Stop if converged
    if(mLzC(iLzIt) < LANCZOS_CONVERGE) bDone = true;

    // Stop if diverging
    if(LANCZOS_STRICT && iLzIt > 1 && mLzC(iLzIt) > mLzC(iLzIt-1) && abs(mLzC(iLzIt)/mLzC(iLzIt-1)) > LANCZOS_DIVERGE) {
        ssOut << "Warning: Lanczos Divergence > " << floor(LANCZOS_DIVERGE*100) << "%. Breaking ..." << endl;
        oOut->Output(&ssOut);
        bDone = true;
    }

    // Stop if Dim(Lanczos) >= Dim(Basis)
    if(iLzIt >= iBasisDim) {
        ssOut << "Warning: Dim(Lanczos) >= Dim(Basis). Breaking ..." << endl;
        oOut->Output(&ssOut);
        bDone = true;
    }

    // Stop if reached max iterations
    if(iLzIt >= LANCZOS_MAX_IT) {
        ssOut << "Warning: Reached maximum number of Lanczos iterations. Breaking ..." << endl;
        oOut->Output(&ssOut);
        bDone = true;
    }

    if(bDone) {
        mLzW.clear();
        oBasis->SetCoefficients(mLzV);
        mLzV.clear();
        return 1;
    } else {
        for(int i=0; i<iBasisDim; i++) {
            dTemp   = mLzW(i);
            mLzW(i) = mLzV(i)/mLzB(iLzIt);
            mLzV(i) = -mLzB(iLzIt)*dTemp;
        }
        return 0;
    }
}

/*
** Matrix-Vector multiplication section of the Lanczos algorithm
*/

void Lanczos::fMatrixVector(Col<double> &mInput, vector<vector<double> > &vReturn, double d1PFac, double d2PFac, int iStart, int iStop) {

    int    i, p, q, r, s;
    int    iS1, iS2, iS3, iS4, iL=0;
    double dV;
    Slater sdPhiPQRS, sdPhiQRS, sdPhiSR, sdPhiR;

    #ifdef OPENMP
        #pragma omp parallel for private(p,q,r,s,iS1,iS2,iS3,iS4,sdPhiPQRS,sdPhiQRS,sdPhiSR,sdPhiR,iL,dV) schedule(dynamic,1)
    #endif
    for(i=iStart; i<iStop; i++) {
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
                                #ifdef OPENMPLOWMEM
                                    #pragma omp critical
                                    vReturn[floor(omp_get_thread_num()/2.0)][iL] += iS1*iS2*iS3*iS4*dV*mInput(i);
                                #else
                                    vReturn[omp_get_thread_num()][iL] += iS1*iS2*iS3*iS4*dV*mInput(i);
                                #endif
                            #else
                                vReturn[0][iL] += iS1*iS2*iS3*iS4*dV*mInput(i);
                            #endif
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
                    cout << "\r                                              ";
                    cout << "\rCalculating SD: " << i+1 << " of " << iBasisDim << " ";
                }
            #ifdef OPENMP
            }
            #endif
        #endif
    }

    return;
}
