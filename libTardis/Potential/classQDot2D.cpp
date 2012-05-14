/*
** ~ libTardis ~
**
** Class :: QDot2D
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;
using namespace quantumdot;

#include "modQDot2D.cpp"

/*
** Public :: Constructor
*/

QDot2D::QDot2D(int iNumShells, Log *oLog) : Potential(iNumShells, oLog) {

    iShells    = iNumShells;
    iStates    = iShells*(iShells+1);
    bEnergyCut = false;
    dLambda    = 1.0;
    oOut       = oLog;
    bCache     = false;

    int iIndex=0;

    mStates.set_size(iStates,3);
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

    return;
}

/*
** Public :: Load or Generate
*/

void QDot2D::LoadOrGenerate(int iType) {
    Load(iType);
    if(bCache) return;
    Generate(iType);
    return;
}

/*
** Public :: Loader
*/

void QDot2D::Load(int iType) {

    if(ssCache.str().length() == 0) return;

    stringstream sFileNameC, sFileNameH, sFileNameM;

    switch(iType) {
        case Q2D_ANALYTIC:
            sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockConfig.dat";
            sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockDiag.dat";
            sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockMap.dat";
            break;
        case Q2D_NORMAL:
            sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockConfig.dat";
            sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockDiag.dat";
            sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockMap.dat";
            break;
        case Q2D_EFFECTIVE:
            sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockConfig.dat";
            sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockDiag_L" << setprecision(5) << dLambda << ".dat";
            sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockMap.dat";
            break;
    }

    bool bFC = mConfig.quiet_load(sFileNameC.str());
    bool bFH = mBlHam.quiet_load(sFileNameH.str());
    bool bFM = mMap.quiet_load(sFileNameM.str());

    bCache = bFC & bFH & bFM;

    if(bCache) {
        ssOut << "Hamiltonian found in cache and loaded into memory" << endl;
        oOut->Output(&ssOut);
    }

    return;
}

/*
** Public :: Generator
*/

void QDot2D::Generate(int iType) {

    int    i, j, k;
    int    iM, iMs, iLambda, iMu;
    int    iCount = 12*iShells-9;
    int    iDim;
    double dSize = 0.0;

    // Precalculate LogFac and LGamma values for analytic Coulomb
    if(iType == Q2D_ANALYTIC) {
        vLogFac.resize(MAX_FAC+1);
        vLogFac[0] = 0.0;
        vLogFac[1] = 0.0;
        for(int i = 2; i <= MAX_FAC; i++) {
            vLogFac[i] = vLogFac[i-1] + log(i);
        }

        vLGamma.resize(2*MAX_LGAMMA+1);
        for(double dX = 0.0; dX <= MAX_LGAMMA; dX += 0.5) {
            vLGamma[(int)(dX*2)] = fLGamma(dX);
        }
    }

    //
    //  Building vector of configurations
    //

    ssOut << "Generating configurations ..." << endl;
    oOut->Output(&ssOut);

    mMap.zeros(iStates*iStates,2);
    mBlHam.set_size(1,iCount+1);
    mConfig.set_size(1,iCount);
    vector<vector<int> > vConfig(iCount);

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

    // Estimating size of file/memory
    for(k=0; k<=iCount; k++) {
        iDim = vConfig[k-1].size()/2;
        dSize += iDim*iDim*sizeof(double);
    }

    if(dSize > GBYTE) {
        ssOut << "Estimated size: " << setprecision(4) << dSize/GBYTE << " Gb" << endl;
    } else if(dSize > MBYTE) {
        ssOut << "Estimated size: " << setprecision(4) << dSize/MBYTE << " Mb" << endl;
    } else if(dSize > KBYTE) {
        ssOut << "Estimated size: " << setprecision(4) << dSize/KBYTE << " kb" << endl;
    } else {
        ssOut << "Estimated size: " << setprecision(4) << dSize << " bytes" << endl;
    }
    oOut->Output(&ssOut);

    mBlHam(0).zeros(iStates,iStates);
    for(i=0; i<iStates; i++) {
        for(j=0; j<iStates; j++) {
            mBlHam(0)(i,j) = (1+2*mStates(i,0)+abs(mStates(i,1))) + (1+2*mStates(j,0)+abs(mStates(j,1)));
        }
    }

    // Generating 2-p Hamiltonian
    if(iType == Q2D_NORMAL || iType == Q2D_EFFECTIVE) {
        oOFCI = new QdotInteraction();
        oOFCI->setR(iShells-1);
    }

    if(iType == Q2D_NORMAL) {
        ssOut << "Building interaction CoM Blocks ..." << endl;
        oOut->Output(&ssOut);
        oOFCI->setLambda(1.0);
        oOFCI->buildInteractionComBlocks();
    }

    if(iType == Q2D_EFFECTIVE) {
        ssOut << "Building effective interaction CoM Blocks ..." << endl;
        oOut->Output(&ssOut);
        oOFCI->setLambda(dLambda);
        oOFCI->buildEffectiveInteractionComBlocks(2);
    }

    for(k=1; k<=iCount; k++) {
        iDim = vConfig[k-1].size()/2;
        #ifdef PROGRESS
            cout << "\r                                                                                   ";
            cout << "\rGenerating 2-particle Hamiltonian, block " << k << " of " << iCount << " ";
            cout << "(Dim: " << iDim << "x" << iDim << ")" << flush;
        #endif

        if(iDim > 0) {
            mBlHam(k).zeros(iDim,iDim);
            mConfig(k-1).zeros(2,iDim);
            switch(iType) {

                case Q2D_ANALYTIC:
                    #ifdef OPENMP
                        #pragma omp parallel for private(j) schedule(dynamic,1)
                    #endif
                    for(i=0; i<iDim; i++) {
                        mConfig(k-1)(0,i) = vConfig[k-1][2*i];
                        mConfig(k-1)(1,i) = vConfig[k-1][2*i+1];
                        for(j=i; j<iDim; j++) {
                            mBlHam(k)(i,j) = fCalcElementQ2D(vConfig[k-1][2*i],
                                                             vConfig[k-1][2*i+1],
                                                             vConfig[k-1][2*j],
                                                             vConfig[k-1][2*j+1]);
                            mBlHam(k)(j,i) = mBlHam(k)(i,j);
                        }
                    }
                    break;

                case Q2D_NORMAL:
                case Q2D_EFFECTIVE:
                    for(i=0; i<iDim; i++) {
                        mConfig(k-1)(0,i) = vConfig[k-1][2*i];
                        mConfig(k-1)(1,i) = vConfig[k-1][2*i+1];
                        for(j=i; j<iDim; j++) {
                            mBlHam(k)(i,j) = fCalcElementQ2DOpenFCI(vConfig[k-1][2*i],
                                                                    vConfig[k-1][2*i+1],
                                                                    vConfig[k-1][2*j],
                                                                    vConfig[k-1][2*j+1]);
                            mBlHam(k)(j,i) = mBlHam(k)(i,j);
                        }
                    }
                    break;
            }
        } else {
            mBlHam(k).zeros(1,1);
        }
    }

    #ifdef PROGRESS
        cout << "\r                                                                                   \r";
    #endif

    if(ssCache.str().length() > 0) {
        stringstream sFileNameC, sFileNameH, sFileNameM;

        switch(iType) {
            case Q2D_ANALYTIC:
                sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockConfig.dat";
                sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockDiag.dat";
                sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_AnalyticBlockMap.dat";
                break;
            case Q2D_NORMAL:
                sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockConfig.dat";
                sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockDiag.dat";
                sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_NormalBlockMap.dat";
                break;
            case Q2D_EFFECTIVE:
                sFileNameC << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockConfig.dat";
                sFileNameH << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockDiag_L" << setprecision(5) << dLambda << ".dat";
                sFileNameM << ssCache.str() << "QDot2D_" << iShells << "Sh_EffectiveBlockMap.dat";
                break;
        }

        mConfig.save(sFileNameC.str());
        mBlHam.save(sFileNameH.str());
        mMap.save(sFileNameM.str());
        ssOut << "Done and saved to cache" << endl << endl;
    } else {
        ssOut << "Done" << endl << endl;
    }
    oOut->Output(&ssOut);

    bCache = true;

    return;
}

/*
** Public :: Getters :: Elements
*/

double QDot2D::Get1PElement(int p, int q) {
    if(bCache) return mBlHam(0)(p,q);
    return (1 + 2*mStates(p,0) + abs(mStates(p,1))) + (1 + 2*mStates(q,0) + abs(mStates(q,1)));
}

double QDot2D::Get2PElement(int p, int q, int r, int s) {

    if(!bCache) return fCalcElementQ2D(p, q, r, s);

    int iLambda1 = mMap(p*iStates+q,0);
    int iLambda2 = mMap(r*iStates+s,0);
    if(iLambda1 == iLambda2) {
        return mBlHam(iLambda1)(mMap(p*iStates+q,1),mMap(r*iStates+s,1));
    } else {
        return 0.0;
    }

}

const Mat<int>* QDot2D::GetConfig(int iM, int iMs) {
    unsigned int iIndex = fMapLambda(iM, iMs);
    if(iIndex <= mConfig.n_cols) return &mConfig(iIndex);
    return NULL;
}

/*
** Public :: Getters :: Pointers
*/

const Col<double>* QDot2D::Get1PHam(int iM, int iMs) {

    unsigned int iIndex = fMapLambda(iM, iMs);

    if(mBlHam.n_elem > 0) {
        m1PHam.zeros(mConfig(iIndex).n_cols);
        for(unsigned int i=0; i<mConfig(iIndex).n_cols; i++) {
            m1PHam(i) = Get1PElement(mConfig(iIndex)(0,i),mConfig(iIndex)(1,i));
        }
        return &m1PHam;
    }

    return NULL;
}

const Mat<double>* QDot2D::Get2PHam(int iM, int iMs) {
    unsigned int iIndex = fMapLambda(iM, iMs)+1;
    if(iIndex <= mBlHam.n_elem) return &mBlHam(iIndex);
    return NULL;
}
