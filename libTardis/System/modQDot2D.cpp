/*
**  Calculates the Coulomb interaction element <pq|V|rs>
** ======================================================
**  - Accounts for spin
**  - Is antisymmetric
*/
double System::fCalcElementQ2D(int p, int q, int r, int s) {

    double dDirect = 0.0, dExchange = 0.0;

    if(DELTA(mStates(p,2),mStates(s,2)) && DELTA(mStates(q,2),mStates(r,2))) {
        dExchange = fCoulomb2D(mStates(p,0),mStates(p,1),mStates(q,0),mStates(q,1),mStates(r,0),mStates(r,1),mStates(s,0),mStates(s,1));
    }

    if(DELTA(mStates(p,2),mStates(r,2)) && DELTA(mStates(q,2),mStates(s,2))) {
        dDirect = fCoulomb2D(mStates(p,0),mStates(p,1),mStates(q,0),mStates(q,1),mStates(s,0),mStates(s,1),mStates(r,0),mStates(r,1));
    }

    return dDirect - dExchange;
}

/*
**  Calculates Coulomb interactions in 2 dimensions
** =================================================
**  Code adapted from Morten Hjorth-Jensen
**  See Anisimovas and Matulis (1997) for analytical expression
**
**  - Computes <12|V|34>
**  - Does not check spin
**  - Does not antisymmertise
**  - Calculate: d(Ms1,Ms3)*d(Ms2,Ms4)*<12|V|43> - d(Ms1,Ms4)*d(Ms2,Ms3)*<12|V|34>
**      Where d(i,j) is the delta function
*/
double System::fCoulomb2D(int iN1, int iM1, int iN2, int iM2, int iN3, int iM3, int iN4, int iM4) {

    double dCoulombInt = 0.0;

    if(iM1 + iM2 == iM3 + iM4) {
        double dTemp;
        int    iLambda;
        int    iGamma1 = 0;
        int    iGamma2 = 0;
        int    iGamma3 = 0;
        int    iGamma4 = 0;
        int    iG = 0;
        for(int iJ1 = 0; iJ1 <= iN1; iJ1++) {
            for(int iJ2 = 0; iJ2 <= iN2; iJ2++) {
                for(int iJ3 = 0; iJ3 <= iN3; iJ3++) {
                    for(int iJ4 = 0; iJ4 <= iN4; iJ4++) {
                        iGamma1 = (int)(iJ1 + iJ4 + 0.5*(abs(iM1) + iM1) + 0.5*(abs(iM4) - iM4));
                        iGamma2 = (int)(iJ2 + iJ3 + 0.5*(abs(iM2) + iM2) + 0.5*(abs(iM3) - iM3));
                        iGamma3 = (int)(iJ2 + iJ3 + 0.5*(abs(iM3) + iM3) + 0.5*(abs(iM2) - iM2));
                        iGamma4 = (int)(iJ1 + iJ4 + 0.5*(abs(iM4) + iM4) + 0.5*(abs(iM1) - iM1));
                        iG = iGamma1 + iGamma2 + iGamma3 + iGamma4;

                        double dLogRatio1   = - vLogFac[iJ1] - vLogFac[iJ2] - vLogFac[iJ3] - vLogFac[iJ4];
                        double dLogProduct2 = vLogFac[iN1 + abs(iM1)] + vLogFac[iN2 + abs(iM2)]
                                            + vLogFac[iN3 + abs(iM3)] + vLogFac[iN4 + abs(iM4)]
                                            - vLogFac[iN1 - iJ1] - vLogFac[iN2 - iJ2]
                                            - vLogFac[iN3 - iJ3] - vLogFac[iN4 - iJ4]
                                            - vLogFac[iJ1 + abs(iM1)] - vLogFac[iJ2 + abs(iM2)]
                                            - vLogFac[iJ3 + abs(iM3)] - vLogFac[iJ4 + abs(iM4)];
                        double dLogRatio2   = -1*(iG + 1)*0.5*log(2);

                        dTemp   = 0.0;
                        iLambda = 0;

                        for(int iL1 = 0; iL1 <= iGamma1; iL1++) {
                            for(int iL2 = 0; iL2 <= iGamma2; iL2++) {
                                for(int iL3 = 0; iL3 <= iGamma3; iL3++) {
                                    for(int iL4 = 0; iL4 <= iGamma4; iL4++) {
                                        iLambda = iL1 + iL2 + iL3 + iL4;
                                        if((iL1 + iL2) == (iL3 + iL4)) {
                                            dTemp += MINUS_POW(iGamma2 + iGamma3 - iL2 - iL3)
                                                   * exp(vLogFac[iGamma1] + vLogFac[iGamma2] + vLogFac[iGamma3] + vLogFac[iGamma4]
                                                         - vLogFac[iL1] - vLogFac[iL2] - vLogFac[iL3] - vLogFac[iL4]
                                                         - vLogFac[iGamma1 - iL1] - vLogFac[iGamma2 - iL2]
                                                         - vLogFac[iGamma3 - iL3] - vLogFac[iGamma4 - iL4]
                                                         + vLGamma[2 + iLambda] + vLGamma[iG - iLambda + 1]);
                                        }
                                    }
                                }
                            }
                        }

                        dCoulombInt += MINUS_POW(iJ1 + iJ2 + iJ3 + iJ4)
                                     * exp(dLogRatio1 + dLogProduct2 + dLogRatio2)*dTemp;

                    }
                }
            }
        }
        dCoulombInt *= exp((vLogFac[iN1] + vLogFac[iN2] + vLogFac[iN3] + vLogFac[iN4]
                            - vLogFac[iN1 + abs(iM1)] - vLogFac[iN2 + abs(iM2)]
                            - vLogFac[iN3 + abs(iM3)] - vLogFac[iN4 + abs(iM4)])*0.5);
    }

    return dCoulombInt;
}

/*
**  Calculates log(Gamma) of a real argument
** ==========================================
**  Code adapted from Morten Hjorth-Jensen
**      Algorithms and coefficient values from "Computation of Special
**      Functions", Zhang and Jin, John Wiley and Sons, 1996.
**
**  (C) 2003, C. Bond. All rights reserved.
**
**  NOTE: Returns 1e308 if argument is 0 or negative.
**  Taken from the web at http://www.crbond.com/math.htm
*/
double System::fLGamma(double dX) {

    double dX0, dX2, dXp, dGL, dGL0;
    int    iN = 0, iK;
    static double aA[] = {8.333333333333333e-02, -2.777777777777778e-03,
                          7.936507936507937e-04, -5.952380952380952e-04,
                          8.417508417508418e-04, -1.917526917526918e-03,
                          6.410256410256410e-03, -2.955065359477124e-02,
                          1.796443723688307e-01, -1.39243221690590};

    dX0 = dX;
    if     (dX <= 0.0) return 1e308;
    else if((dX == 1.0) || (dX == 2.0)) return 0.0;
    else if(dX <= 7.0) {
        iN = (int)(7-dX);
        dX0 = dX + iN;
    }
    dX2 = 1.0/(dX0*dX0);
    dXp = 2.0*M_PI;
    dGL0 = aA[9];
    for(iK = 8; iK >= 0; iK--) dGL0 = dGL0*dX2 + aA[iK];
    dGL = dGL0/dX0 + 0.5*log(dXp) + (dX0 - 0.5)*log(dX0) - dX0;
    if(dX <= 7.0) {
        for(iK = 1; iK <= iN; iK++) {
            dGL -= log(dX0-1.0);
            dX0 -= 1.0;
        }
    }
    return dGL;
}
