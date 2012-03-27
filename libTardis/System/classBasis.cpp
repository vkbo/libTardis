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

    return;
}

/*
** Public :: Functions
*/

int Basis::BuildBasis(int iM, int iMs) {

    vector<int> vTemp(iParticles,0);

    vBasis.clear();
    cout << endl;
    fGenConfig(vTemp, iM, iMs, 0);
    cout << endl;

    Slater sdTest;
    int    iBasisDim = vBasis.size();

    vIndex.resize(iStates*iStates);

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
        }
    }

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
            cout << "\r                                ";
            cout << "\rDimension of basis: " << vBasis.size();
            fflush(stdout);
        }
    }

    return;
}
