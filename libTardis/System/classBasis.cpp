/*
** ~ libTardis ~
**
** Class :: Basis
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
** Public :: Constructor and Destructor
*/

Basis::Basis(Potential *oPotential, Log *oLog, int iNumParticles, int iNumStates) {

    oPot       = oPotential;
    oOut       = oLog;
    iParticles = iNumParticles;
    iStates    = iNumStates;

    // Qunatum Numbers
    iM  = 0;
    iMs = 0;

    if(iStates > SLATER_WORD) {
        ssOut << "Warning: SLATER_WORD not large enough for this configuration." << endl;
        ssOut << "         SLATER_WORD must be at least " << (floor(iStates/64)+1)*64 << " bit" << endl;
        oOut->Output(&ssOut);
    }

    // Using binary search
    #ifndef INDEX_BASIS
        mIndex.set_size(iStates+1,2);
        mIndex.fill(-1);
    #endif

    return;
}

/*
** Public :: Functions
*/

int Basis::BuildBasis() {

    Slater      sdTest;
    int         iTM = 0, iTMs = 0;
    int         iBasisDim = 0;
    int         i,j,iOut,iExp;
    long        lConfMax;
    double      d, dX = 1.0;
    vector<int> vTemp(iParticles,0);

    vBasis.clear();
    #ifndef INDEX_BASIS
        int iPrev = -1;
    #endif

    for(d=0.0; d<iParticles; d++) dX *= (iStates-d)/(iParticles-d);
    lConfMax = (long)dX;
    iExp     = floor(log10(lConfMax));
    ssOut << "Possible configurations: " << lConfMax << " ";
    ssOut << "(~" << round(lConfMax/pow(10,iExp)) << "e" << iExp << ")" << endl;

    #ifdef PROGRESS
        long lCount = 0;

        cout << showpoint;
        cout << setw(5);
        cout << setprecision(3);
    #else
        ssOut << "Building Basis ... " << endl;
    #endif

    oOut->Output(&ssOut);

    for(int i=0; i<iParticles; i++) {
        vTemp[i] = i;
        iTM  += oPot->GetState(i,1);
        iTMs += 2*(i%2)-1;
    }
    if(iTMs == iMs && iTM == iM) {
        sdTest.Zero();
        for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
        vBasis.push_back(sdTest);
        #ifndef INDEX_BASIS
            if(vTemp[0] != iPrev) {
                if(iPrev >= 0) mIndex(iPrev,1)  = vBasis.size()-2;
                mIndex(vTemp[0],0) = vBasis.size()-1;
                mIndex(vTemp[0],1) = vBasis.size()-1;
                iPrev = vTemp[0];
            }
        #endif
    }

    iOut = 0;
    while(vTemp[0] < iStates-iParticles) {
        for(i=iParticles-1; i>=0; i--) {
            if(vTemp[i] < iStates-iParticles+i) {
                vTemp[i]++;
                if(i < iParticles-1) {
                    for(j=i+1; j<iParticles; j++) {
                        vTemp[j] = vTemp[j-1] + 1;
                    }
                }
                break;
            }
        }
        iTM  = 0;
        iTMs = 0;
        for(i=0; i<iParticles; i++) {
            iTM  += oPot->GetState(vTemp[i],1);
            iTMs += 2*(vTemp[i]%2)-1;
        }
        if(iTMs == iMs && iTM == iM) {
            sdTest.Zero();
            for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
            vBasis.push_back(sdTest);
            #ifndef INDEX_BASIS
                if(vTemp[0] != iPrev) {
                    if(iPrev >= 0) mIndex(iPrev,1)  = vBasis.size()-2;
                    mIndex(vTemp[0],0) = vBasis.size()-1;
                    mIndex(vTemp[0],1) = vBasis.size()-1;
                    iPrev = vTemp[0];
                }
            #endif
        }

        #ifdef PROGRESS
            if(lConfMax > 100000) {
                lCount++;
                iOut++;
                if(iOut >= lConfMax/1000) {
                    cout << "\rBuilding Basis: " << OUTPUTF(3) << (lCount/double(lConfMax)*100) << "% " << flush;
                    iOut = 0;
                }
            }
        #endif

    }

    iBasisDim = vBasis.size();

    #ifdef PROGRESS
        cout << "\rBuilding Basis: 100.0%" << endl;
    #endif

    iExp = floor(log10(iBasisDim));
    ssOut << "Dimension of Basis: " << iBasisDim << setprecision(1) << " ";
    ssOut << "(~" << round(iBasisDim/pow(10,iExp)) << "e" << iExp << ")" << endl;

    #ifdef INDEX_BASIS

        int p,q;
        int iDim = iStates*iStates;
        vIndex.resize(iDim);

        #ifdef PROGRESS
            cout << "Indexing Basis ... " << flush;
            lCount = 0;
        #endif

        iOut = 0;
        #ifdef OPENMP
            #pragma omp parallel for private(i,q,sdTest) schedule(dynamic,1)
        #endif
        for(p=0; p<iStates; p++) {
            for(q=0; q<iStates; q++) {
                for(i=0; i<iBasisDim; i++) {
                    sdTest = vBasis[i];
                    if(sdTest.Annihilate(p) != 0) {
                        if(sdTest.Annihilate(q) != 0) {
                            #ifdef OPENMP
                                #pragma omp critical
                            #endif
                            vIndex[p*iStates+q].push_back(i);
                        }
                    }
                }

                #ifdef PROGRESS
                    #ifdef OPENMP
                    if(omp_get_thread_num() == 0) {
                    #endif
                        if(iDim > 1000) {
                            lCount = p*iStates+q;
                            iOut++;
                            if(iOut >= iDim/1000) {
                                cout << "\rIndexing Basis: " << OUTPUTF(3) << (lCount/double(iDim)*100) << "% " << flush;
                                iOut = 0;
                            }
                        }
                    #ifdef OPENMP
                    }
                    #endif
                #endif
            }
        }
        #ifdef PROGRESS
            cout << "\rIndexing Basis: 100.0%" << endl;
        #endif

    #endif

    ssOut << endl;
    oOut->Output(&ssOut);

    return iBasisDim;
}

int Basis::FindSlater(Slater sdFind, int p, int q) {

    #ifdef INDEX_BASIS
        // Index-based search
        for(unsigned int i=0; i<vIndex[p*iStates+q].size(); i++) {
            if(vBasis[vIndex[p*iStates+q][i]].Equal(sdFind)) {
                return vIndex[p*iStates+q][i];
            }
        }
    #else
        // Binary search
        int iCheck;
        int iP = sdFind.GetFirst();
        int iMin = mIndex(iP,0);
        int iMax = mIndex(iP,1)+1;

        if(iMin == -1) return -1;

        while(iMax!=iMin) {
            iCheck = iMin+(iMax-iMin)/2;
            switch(vBasis[iCheck].Compare(sdFind)) {
                case  0: return iCheck;
                case -1: iMax = iCheck;   break;
                case  1: iMin = iCheck+1; break;
            }
        }
    #endif

    return -1;
}

/*
** Public :: Getters, Setters and Output
*/

void Basis::Output() {

    int iWidth = ceil(log10(iStates))+1;

    for(unsigned int i=0; i<vBasis.size(); i++) {
        cout << "|" << setw(iWidth) << i << "> : ";
        vBasis[i].Output(iStates);
    }

    return;
}

bool Basis::SetQNumber(int iVar, int iValue) {

    switch(iVar) {
        case QN_M:  iM  = iValue; break;
        case QN_MS: iMs = iValue; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return false;
    }

    return true;
}

int Basis::GetQNumber(int iVar) {

    switch(iVar) {
        case QN_M:  return iM;  break;
        case QN_MS: return iMs; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return -1000;
    }
}
