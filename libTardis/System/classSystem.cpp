/*
** ~ libTardis ~
**
** Class :: System
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

#include "modQDot2D.cpp"

/*
** Public :: Constructor and Destructor
*/

System::System(int iSh, int iP, int iSysType) {

    int iIndex;

    iShells     = iSh;
    iParticles  = iP;
    iSystemType = iSysType;

    bCache = false;

    switch(iSystemType) {
        case ATOM:
            iStates = 0;
            break;

        case QDOT2D:
            iStates = iShells*(iShells+1);
            mStates.set_size(iStates,3);
            iIndex = 0;
            for(int iR = 0; iR < iShells; iR++) {
                for(int iM = -iR; iM <= iR; iM += 2) {
                    int iN = (iR - abs(iM))/2;
                    mStates(2*iIndex,0)   = iN;
                    mStates(2*iIndex,1)   = iM;
                    mStates(2*iIndex,2)   = -1;  // 2*Ms
                    mStates(2*iIndex+1,0) = iN;
                    mStates(2*iIndex+1,1) = iM;
                    mStates(2*iIndex+1,2) = 1;   // 2*Ms
                    iIndex++;
                }
            }
            break;

        case QDOT3D:
            iStates = 0;
            break;

        case NUCLEUS:
            iStates = 0;
            break;

        case HNUCLEUS:
            iStates = 0;
            break;
    }

    // Generate array of log(n!)
    vLogFac.resize(MAX_FAC+1);
    vLogFac[0] = 0.0;
    vLogFac[1] = 0.0;
    for(int i = 2; i <= MAX_FAC; i++) {
        vLogFac[i] = vLogFac[i-1] + log(i);
    }

    // Generate array of LGamma
    vLGamma.resize(2*MAX_LGAMMA+1);
    for(double dX = 0.0; dX <= MAX_LGAMMA; dX += 0.5) {
        vLGamma[(int)(dX*2)] = fLGamma(dX);
    }

    return;
}

/*
** Public :: Functions
*/

void System::GenerateH(bool bLoad) {

    stringstream sFileNameC, sFileNameH, sFileNameM;
    bool bCalc = true;

    sFileNameH << ARMA_CACHE_DIR << "QDot2D_CoulombBlock_Sh" << iShells << ".dat";
    sFileNameM << ARMA_CACHE_DIR << "QDot2D_CoulombBlockMap_Sh" << iShells << ".dat";
    sFileNameC << ARMA_CACHE_DIR << "QDot2D_CoulombBlockConfig_Sh" << iShells << ".dat";
    if(bLoad) {
        bool bFH = mHamiltonian.quiet_load(sFileNameH.str());
        bool bFC = mConfig.quiet_load(sFileNameC.str());
        bool bFM = mMap.quiet_load(sFileNameM.str());
        bCalc = !bFH | !bFC | !bFM;
    }

    if(bCalc) {
        int    i, j, k;
        int    iM, iMs, iLambda, iMu;
        int    iCount = 12*iShells-9;
        int    iDim;
        double dSize = 0.0;

        mMap.zeros(iStates*iStates,2);
        mConfig.set_size(1,iCount);
        mHamiltonian.set_size(1,iCount+1);
        vector<vector<int> > vConfig(iCount);

        cout << "Hamiltonian not found in cache, building ..." << endl;
        cout << "Generating configurations ...";
        fflush(stdout);

        for(i=0; i<iStates; i++) {
            for(j=i; j<iStates; j++) {
                iM  = mStates(i,1)+mStates(j,1);
                iMs = mStates(i,2)+mStates(j,2);
                iLambda = fMapLambda(iM, iMs);
                mMap(i*iStates+j,0) = iLambda+1;
                mMap(j*iStates+i,0) = iLambda+1;
                if(j>i) {
                    vConfig[iLambda].push_back(i);
                    vConfig[iLambda].push_back(j);
                    iMu = vConfig[iLambda].size()/2-1;
                    mMap(i*iStates+j,1) = iMu;
                    mMap(j*iStates+i,1) = iMu;
                }
            }
        }

        for(k=0; k<=iCount; k++) {
            iDim = vConfig[k-1].size()/2;
            dSize += iDim*iDim*sizeof(double);
        }

        cout << "\rEstimated size: " << setprecision(4) << dSize/MBYTE << " Mb       " << endl;
        cout << "Generating 1-particle Hamiltonian ...";
        fflush(stdout);

        mHamiltonian(0).zeros(iStates,iStates);
        for(i=0; i<iStates; i++) {
            for(j=0; j<iStates; j++) {
                mHamiltonian(0)(i,j) = (1+2*mStates(i,0)+abs(mStates(i,1))) + (1+2*mStates(j,0)+abs(mStates(j,1)));
            }
        }

        for(k=1; k<=iCount; k++) {
            iDim = vConfig[k-1].size()/2;
            cout << "\r                                                                                   ";
            cout << "\rGenerating 2-particle Hamiltonian, block " << k << " of " << iCount << " (Dim: " << iDim << "x" << iDim << ")";
            fflush(stdout);
            if(iDim > 0) {
                mHamiltonian(k).zeros(iDim,iDim);
                mConfig(k-1).zeros(2,iDim);
                #ifdef OPENMP
                    #pragma omp parallel for private(j) schedule(dynamic,1)
                #endif
                for(i=0; i<iDim; i++) {
                    mConfig(k-1)(0,i) = vConfig[k-1][2*i];
                    mConfig(k-1)(1,i) = vConfig[k-1][2*i+1];
                    for(j=i; j<iDim; j++) {
                        mHamiltonian(k)(i,j) = fCalcElementQ2D(vConfig[k-1][2*i],vConfig[k-1][2*i+1],vConfig[k-1][2*j],vConfig[k-1][2*j+1]);
                        mHamiltonian(k)(j,i) = mHamiltonian(k)(i,j);
                    }
                }
            } else {
                mHamiltonian(k).zeros(1,1);
            }
        }

        cout << "\r                                                                                   ";
        if(bLoad) {
            mHamiltonian.save(sFileNameH.str());
            mConfig.save(sFileNameC.str());
            mMap.save(sFileNameM.str());
            cout << "\rDone and saved to cache";
        } else {
            cout << "\rDone";
        }
        fflush(stdout);
    } else {
        cout << "Hamiltonian found in cache and loaded into memory";
    }

    cout << endl << endl;
    bCache = true;

    return;
}

/*
** Public :: Getters, Setters and Output
*/

int System::GetParticles() {
    return iParticles;
}

int System::GetStates() {
    return iStates;
}

int System::GetState(int iState, int iQN) {
    return mStates(iState, iQN);
}

double System::Get1PElement(int p, int q) {

    if(iSystemType == QDOT2D) {
        if(bCache) {
            return 1.0/(iParticles-1)*mHamiltonian(0)(p,q);
        } else {
            return 1.0/(iParticles-1)*((1 + 2*mStates(p,0) + abs(mStates(p,1))) + (1 + 2*mStates(q,0) + abs(mStates(q,1))));
        }
    }
    return -1.0;
}

double System::Get2PElement(int p, int q, int r, int s) {

    if(iSystemType == QDOT2D) {
        if(bCache) {
            int iLambda1 = mMap(p*iStates+q,0);
            int iLambda2 = mMap(r*iStates+s,0);
            if(iLambda1 == iLambda2) {
                return mHamiltonian(iLambda1)(mMap(p*iStates+q,1),mMap(r*iStates+s,1));
            } else {
                return 0.0;
            }
        } else {
            return fCalcElementQ2D(p, q, r, s);
        }
    }
    return -1.0;
}

const Col<double>* System::Get1PHam(int iM, int iMs) {

    unsigned int iIndex = fMapLambda(iM, iMs);

    if(mHamiltonian.n_elem > 0) {
        m1PHam.zeros(mConfig(iIndex).n_cols);
        for(unsigned int i=0; i<mConfig(iIndex).n_cols; i++) {
            m1PHam(i) = Get1PElement(mConfig(iIndex)(0,i),mConfig(iIndex)(1,i));
        }
        return &m1PHam;
    }

    return NULL;
}

const Mat<double>* System::Get2PHam(int iM, int iMs) {
    unsigned int iIndex = fMapLambda(iM, iMs)+1;
    if(iIndex <= mHamiltonian.n_elem) return &mHamiltonian(iIndex);
    return NULL;
}

int System::GetDim(int iM, int iMs) {
    return mConfig(fMapLambda(iM, iMs)).n_cols;
}

/*
** Private :: Functions
*/

/*
** Returns Lambda map-index from M and Ms
*/

int System::fMapLambda(int iM, int iMs) {
    return (6*iM + 12*iShells + iMs - 10)/2;
}
