/*
** ~ libTardis ~
**
** Class :: Basis
*/

#include "../libTardis.hpp"

using namespace std;
//using namespace arma;
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

    vBasis.clear();
    //vIndex.resize(iDim);

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
        cout << "Basis Dim: " << iBasisDim << endl;
        return iBasisDim;
        cout << "Indexing Basis ... " << flush;
        lCount = 0;
    #else
        cout << "Done" << endl;
    #endif
    return iBasisDim;

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
    int iIndex=-1;
    /*
    for(unsigned int i=0; i<vIndex[p*iStates+q].size(); i++) {
        if(vBasis[vIndex[p*iStates+q][i]].Compare(sdFind)) {
            iIndex = vIndex[p*iStates+q][i];
            break;
        }
    }
    */



    return iIndex;
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
