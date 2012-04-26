/*
**  Calculates the Coulomb interaction element <pq|V|rs>
** ======================================================
**  - Accounts for spin
**  - Is antisymmetric
*/
double QDot2D::fCalcElementQ2DOpenFCI(int p, int q, int r, int s) {

    double dDirect = 0.0, dExchange = 0.0;

    int iN1 = mStates(p,0);
    int iM1 = mStates(p,1);
    int iN2 = mStates(q,0);
    int iM2 = mStates(q,1);
    int iN3 = mStates(r,0);
    int iM3 = mStates(r,1);
    int iN4 = mStates(s,0);
    int iM4 = mStates(s,1);

    int iNN1 = 2*iN1 + abs(iM1);
    int iNN2 = 2*iN2 + abs(iM2);
    int iNN3 = 2*iN3 + abs(iM3);
    int iNN4 = 2*iN4 + abs(iM4);

    if(DELTA(mStates(p,2),mStates(s,2)) && DELTA(mStates(q,2),mStates(r,2))) {
        dExchange = oOFCI->singleElement(iNN1, iM1, iNN2, iM2, iNN3, iM3, iNN4, iM4);
    }

    if(DELTA(mStates(p,2),mStates(r,2)) && DELTA(mStates(q,2),mStates(s,2))) {
        dDirect = oOFCI->singleElement(iNN1, iM1, iNN2, iM2, iNN4, iM4, iNN3, iM3);
    }

    return dDirect - dExchange;
}
