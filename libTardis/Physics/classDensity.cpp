/*
** ~ libTardis ~
**
** Class :: Density
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

Density::Density(System *oInput) {

    oSystem = oInput;
    oBasis  = oSystem->GetBasis();
    oOut    = oSystem->GetLog();

}

void Density::OneBodyDensity() {

}

void Density::TwoBodyDensity() {

}

/*
** Private Functios
*/

void fHermitePoly(Col<double> &mPoly, double dX, int iLen) {

    if(iLen < 0) return;

    mPoly.zeros(iLen);
    mPoly[0] = 1;

    if(iLen < 1) return;
    mPoly[1] = 2*dX;

    if(iLen < 2) return;
    for(int i = 2; i<iLen; i++) {
        mPoly[i] = 2*dX*mPoly[i-1] - 2*i*mPoly[i-2];
    }

    return;
}
