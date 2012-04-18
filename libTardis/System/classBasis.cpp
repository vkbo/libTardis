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

Basis::Basis(System *oSys) {

    oSystem    = oSys;
    iParticles = oSystem->GetParticles();
    iStates    = oSystem->GetStates();

    if(iStates > SLATER_WORD) {
        cout << "Warning: SLATER_WORD not large enough for this configuration." << endl;
        cout << "         SLATER_WORD must be at least " << (floor(iStates/64)+1)*64 << " bit" << endl;
        cout << endl;
    }

    /*
    ** Determining what type of search-index to use
    **  - For systems larger than 420 states, only the first 2 particles are indexed
    **  - For smaller systems, the first 3 particles are indexed
    **  - For 2-particle systems only 2-particle index is needed
    */

    if(iStates > 420 || iParticles <= 2) {
        m2PIndex.set_size(iStates,iStates);
        m2PIndex.fill(-1);
        b3PIndex = false;
    } else {
        m3PIndex.set_size(iStates,iStates,iStates);
        m3PIndex.fill(-1);
        b3PIndex = true;
    }

    mIndex.set_size(iStates+1,2);
    mIndex.fill(-1);

    return;
}

/*
** Public :: Functions
*/

int Basis::BuildBasis(int iM, int iMs) {

    Slater      sdTest;
    int         iTM = 0, iTMs = 0;
    int         iBasisDim = 0;
    int         iDim = iStates*iStates;
    int         i,j,p,q, iOut;
    vector<int> vTemp(iParticles,0);
    vector<int> vPrev(3,-1);
    int         iPrev = -1;

    vBasis.clear();
    //if(b3PIndex)  m3PIndex.zeros(iStates,iStates,iStates);
    //if(!b3PIndex) m2PIndex.zeros(iStates,iStates);

    //cout << m3PIndex << endl;
    vIndex.resize(iDim);

    #ifdef PROGRESS
        long   lConfMax, lCount = 0;
        double d, dX = 1.0;
        for(d=0.0; d<iParticles; d++) {
            dX *= (iStates-d)/(iParticles-d);
        }
        lConfMax = (long)dX;
        cout << "Possible configurations: " << lConfMax << endl;

        cout << showpoint;
        cout << setw(5);
        cout << setprecision(3);
    #else
        cout << "Building Basis ... " << flush;
    #endif

    //fGenConfig(vTemp, iM, iMs, 0);

    for(int i=0; i<iParticles; i++) {
        vTemp[i] = i;
        iTM  += oSystem->GetState(i,1);
        iTMs += 2*(i%2)-1;
    }
    if(iTMs == iMs && iTM == iM) {
        sdTest.Zero();
        for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
        vBasis.push_back(sdTest);
        if(vTemp[0] != iPrev) {
            if(iPrev >= 0) mIndex(iPrev,1)  = vBasis.size()-2;
            mIndex(vTemp[0],0) = vBasis.size()-1;
            mIndex(vTemp[0],1) = vBasis.size()-1;
            iPrev = vTemp[0];
        }
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
            iTM  += oSystem->GetState(vTemp[i],1);
            iTMs += 2*(vTemp[i]%2)-1;
        }
        if(iTMs == iMs && iTM == iM) {
            sdTest.Zero();
            for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
            vBasis.push_back(sdTest);
            //mIndex(vTemp[0],0) = vBasis.size()-1;
            //mIndex(vTemp[0]+1,0) = vBasis.size()-1;

            if(vTemp[0] != iPrev) {
                if(iPrev >= 0) mIndex(iPrev,1)  = vBasis.size()-2;
                mIndex(vTemp[0],0) = vBasis.size()-1;
                mIndex(vTemp[0],1) = vBasis.size()-1;
                iPrev = vTemp[0];
            }

            //sdTest.Output(iStates);
            //for(i=0; i<iParticles; i++) cout << vTemp[i] << " ";
            //cout << endl;
            //for(i=0; i<3; i++) cout << vPrev[i] << " ";
            //cout << endl;

            // Update index
            if(b3PIndex) {
                if(vPrev[0] != vTemp[0]) {
                    m3PIndex(vTemp[0],0,0) = vBasis.size()-1;
                    //cout << vTemp[0] << ",0,0 = " << vBasis.size()-1 << endl;
                    vPrev[0] = vTemp[0];
                }
                if(vPrev[1] != vTemp[1]) {
                    m3PIndex(vTemp[0],vTemp[1],0) = vBasis.size()-1;
                    //cout << vTemp[0] << "," << vTemp[1] << ",0 = " << vBasis.size()-1 << endl;
                    vPrev[1] = vTemp[1];
                }
                if(vPrev[2] != vTemp[2]) {
                    m3PIndex(vTemp[0],vTemp[1],vTemp[2]) = vBasis.size()-1;
                    //cout << vTemp[0] << "," << vTemp[1] << "," << vTemp[2] << " = " << vBasis.size()-1 << endl;
                    vPrev[2] = vTemp[2];
                }
            } else {
            }
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

    //vBasis[200].Output(iStates);

    //for(i=0; i<iBasisDim; i++) {
    //    vBasis[i].Output(iStates);
    //    if(vBasis[i].After(vBasis[200], iStates)) {
    //        cout << "After" << endl;
    //        vBasis[200].Output(iStates);
    //        cout << endl;
    //    }
    //}

    //cout << FindSlater(vBasis[200],0,0) << endl;
    //cout << mIndex << endl;

    //cout << m3PIndex << endl;

    #ifdef PROGRESS
        cout << "\rBuilding Basis: 100.0%" << endl;
        cout << "Basis Dim: " << iBasisDim << endl;
        //return iBasisDim;
        cout << "Indexing Basis ... " << flush;
        lCount = 0;
    #else
        cout << "Done" << endl;
    #endif

    //return iBasisDim;

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
    #else
        cout << "Done" << endl;
    #endif
    cout << endl;
    fflush(stdout);

    return iBasisDim;
}

int Basis::FindSlater(Slater sdFind, int p, int q) {

    /*
    for(unsigned int i=0; i<vIndex[p*iStates+q].size(); i++) {
        if(vBasis[vIndex[p*iStates+q][i]].Compare(sdFind)) {
            return vIndex[p*iStates+q][i];
        }
    }

    return -1;
    */
    //for(unsigned int i=0; i<vBasis.size(); i++) {
    //    if(vBasis[i].Compare(sdFind)) return i;
    //}

    int iCheck;
    int iMin = 0;
    int iMax = vBasis.size();

    int iP = sdFind.GetFirst(0);
    //cout << iP << endl;
    if(iP != -1) {
        iMin = mIndex(iP,0);
        iMax = mIndex(iP,1)+1;
    }

    if(iMin == -1) return -1;

    //if(iMax-iMin < 10) {
    //    for(int i=iMin; i<iMax; i++) {
    //        if(vBasis[i].Compare(sdFind)) return i;
    //    }
    //} else {
        while(iMax!=iMin) {
            iCheck = iMin+floor((iMax-iMin)/2);
            //cout << iMax << ", " << iMin << ", " << iCheck << endl;
            if(vBasis[iCheck].Compare(sdFind)) {
                return iCheck;
            } else {
                if(vBasis[iCheck].After(sdFind,iP,iStates)) {
                    iMax = iCheck;
                } else {
                    iMin = iCheck+1;
                }
            }
        }
    //}

    return -1;
}

/*
** Public :: Getters, Setters and Output
*/

int Basis::GetSize() {
    return vBasis.size();
}

Slater Basis::GetSlater(int iIndex) {
    return vBasis.at(iIndex);
}

void Basis::Output() {

    int iWidth = ceil(log10(iStates))+1;

    for(unsigned int i=0; i<vBasis.size(); i++) {
        cout << "|" << setw(iWidth) << i << "> : ";
        vBasis[i].Output(iStates);
    }

    return;
}

/*
** Private :: Functions
*/

/*
void Basis::fGenConfig(vector<int> &vTemp, int iM, int iMs, int iP) {

    int iStart = 0;

    if(iP < iParticles) {
        if(iP > 0) iStart = vTemp[iP-1]+1;
        for(int iS=iStart; iS<iStates; iS++) {
            vTemp[iP] = iS;
            fGenConfig(vTemp, iM, iMs, iP+1);
        }
    } else {
        Slater sdNew;
        int iTM = 0;

        for(int i=0; i<iParticles; i++) {
            sdNew.Create(vTemp[i]);
            iTM += oSystem->GetState(vTemp[i],1);
        }

        if(sdNew.CountOdd()-sdNew.CountEven() == iMs && iTM == iM) {
            vBasis.push_back(sdNew);
        }

        #ifdef PROGRESS
            iConfCount++;
            if(iConfMax > 10000) {
                if(iConfCount%(iConfMax/1000) == 0) {
                    cout << "\r                           ";
                    cout << "\rBuilding Basis: " << OUTPUTF(3) << (iConfCount/double(iConfMax)*100) << "%";
                    fflush(stdout);
                }
            }
        #endif
    }

    return;
}
*/
