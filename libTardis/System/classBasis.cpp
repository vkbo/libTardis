/*
** ~ libTardis ~
**
** Class :: Basis
*/

#include "../libTardis.hpp"

using namespace std;
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

    double dX = 1.0;
    for(double i=0.0; i<iParticles; i++) {
        dX *= (iStates-i)/(iParticles-i);
    }
    iConfMax   = (int)dX;
    iConfCount = 0;

    return;
}

/*
** Public :: Functions
*/

int Basis::BuildBasis(int iM, int iMs) {

    vector<int> vTemp(iParticles,0);
    vBasis.clear();

    cout << showpoint;
    cout << setw(5);
    cout << setprecision(3);

    #ifndef PROGRESS
        cout << "Building Basis ... ";
    #endif
    fflush(stdout);

    fGenConfig(vTemp, iM, iMs, 0);

    #ifdef PROGRESS
        cout << "\rBuilding Basis: 100.0%" << endl;
    #else
        cout << "Done" << endl;
    #endif
    fflush(stdout);

    Slater sdTest;
    int iBasisDim = vBasis.size();
    int iDim      = iStates*iStates;
    #ifdef PROGRESS
        int iCount = 0;
    #endif

    vIndex.resize(iDim);

    #ifndef PROGRESS
        cout << "Indexing Basis ... ";
        fflush(stdout);
    #endif
    for(int p=0; p<iStates; p++) {
        for(int q=0; q<iStates; q++) {
            for(int i=0; i<iBasisDim; i++) {
                sdTest = vBasis[i];
                if(sdTest.Annihilate(p) != 0) {
                    if(sdTest.Annihilate(q) != 0) {
                        vIndex[p*iStates+q].push_back(i);
                    }
                }
            }

            #ifdef PROGRESS
                iCount++;
                if(iDim > 1000) {
                    if(iCount%(iDim/1000) == 0) {
                        cout << "\r                           ";
                        cout << "\rIndexing Basis: " << OUTPUTF(3) << (iCount/double(iDim)*100) << "%";
                        fflush(stdout);
                    }
                }
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
    for(unsigned int i=0; i<vIndex[p*iStates+q].size(); i++) {
        if(vBasis[vIndex[p*iStates+q][i]].Compare(sdFind)) {
            iIndex = vIndex[p*iStates+q][i];
            break;
        }
    }
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
