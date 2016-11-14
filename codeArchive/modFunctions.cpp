/*
**  modFunctions.cpp
** ~~~~~~~~~~~~~~~~~~
**  Private functions for class System
*/

#include "modFunctions.hpp"

using namespace std;
//using namespace arma;

namespace tardis {

double fClebschGordan(int iJ1, int iJ2, int iJ3, int iM1, int iM2) {

	static double aFac[150] = {
		.1000000000000000E+01,.3162277660168379E-01,.2000000000000000E-02,
		.1897366596101028E-03,.2400000000000000E-04,.3794733192202056E-05,
		.7200000000000002E-06,.1593787940724864E-06,.4032000000000001E-07,
		.1147527317321902E-07,.3628800000000002E-08,.1262280049054092E-08,
		.4790016000000003E-09,.1969156876524384E-09,.8717829120000006E-10,
		.4135229440701207E-10,.2092278988800002E-10,.1124782407870728E-10,
		.6402373705728006E-11,.3846755834917892E-11,.2432902008176642E-11,
		.1615637450665515E-11,.1124000727777609E-11,.8175125500367506E-12,
		.6204484017332402E-12,.4905075300220504E-12,.4032914611266062E-12,
		.3443362860754794E-12,.3048883446117143E-12,.2796010642932893E-12,
		.2652528598121915E-12,.2600289897927591E-12,.2631308369336940E-12,
		.2745906132211536E-12,.2952327990396046E-12,.3267628297331728E-12,
		.3719933267899019E-12,.4352480892045862E-12,.5230226174666021E-12,
		.6450376682011969E-12,.8159152832478993E-12,.1057861775849963E-11,
		.1405006117752883E-11,.1910498367185033E-11,.2658271574788455E-11,
		.3782786767026367E-11,.5502622159812102E-11,.8178384990311005E-11,
		.1241391559253610E-10,.1923556149721149E-10,.3041409320171346E-10,
		.4905068181788930E-10,.8065817517094409E-10,.1351836790901029E-09,
		.2308436973392420E-09,.4014955268976057E-09,.7109985878048654E-09,
		.1281573721857157E-08,.2350561331282885E-08,.4385545276195193E-08,
		.8320987112741415E-08,.1605109571087441E-07,.3146997326038803E-07,
		.6269557984667544E-07,.1268869321858846E-06,.2608136121621699E-06,
		.5443449390774448E-06,.1153317792981115E-05,.2480035542436839E-05,
		.5411367084667394E-05,.1197857166996993E-04,.2689449441079695E-04,
		.6123445837688631E-04,.1413574626231488E-03,.3307885441519399E-03,
		.7845339175584759E-03,.1885494701666058E-02,.4591092485552201E-02,
		.1132428117820634E-01,.2829031189597267E-01,.7156945704626409E-01,
		.1833212210859029E+00,.4753643337012861E+00,.1247684230710655E+01,
		.3314240134565367E+01,.8908465407274079E+01,.2422709538367284E+02,
		.6665313817722467E+02,.1854826422573992E+03,.5220273782040236E+03,
		.1485715964481768E+04,.4275404227490954E+04,.1243841405464136E+05,
		.3658035857041260E+05,.1087366156656748E+06,.3266626020337846E+06,
		.9916779348709544E+06,.3041882150138602E+07,.9426890448883294E+07,
		.2951234062064472E+08,.9332621544394462E+08,.2980746402685117E+09,
		.9614466715035176E+09,.3131572170660985E+10,.1029901674514568E+11,
		.3419676810361796E+11,.1146280563734714E+12,.3878597438312349E+12,
		.1324641819451836E+13,.4565884904381298E+13,.1588245541522752E+14,
		.5574945468249565E+14,.1974506857221085E+15,.7055650984616650E+15,
		.2543559733472202E+16,.9249958440832429E+16,.3393108684451918E+17,
		.1255404359589777E+18,.4684525849754318E+18,.1762838801735966E+19,
		.6689502913449167E+19,.2559641940120622E+20,.9875044200833661E+20,
		.3840998695345006E+21,.1506141741511150E+22,.5953547977784760E+22,
		.2372173242880062E+23,.9526867474051174E+23,.3856204823625829E+24,
		.1573076357315330E+25,.6466855489220516E+25,.2678949036508007E+26,
		.1118248651196012E+27,.4703162928493458E+27,.1992942746161532E+28,
		.8508021737644667E+28,.3659042881952573E+29,.1585214610157954E+30,
		.6917786472619537E+30,.3040758665204989E+31,.1346201247571762E+32,
		.6002457605114648E+32,.2695364137888182E+33,.1218859041294581E+34,
		.5550293832739345E+34,.2544977678223085E+35,.1174997204390920E+36,
		.5462031093002385E+36,.2556323917872885E+37,.1204487096628886E+38
	};

	double dReturn;
	int    iTemp, iChange;
	int    iJz1, iJz2, iJz3, 
	       iJt1, iJt2, iJt3, iJt4, iJt5,
	       iJ4, iJ5;

	int    iLoopMin, iLoopMax, iPhase, iLoop;
	double dFactor;

	dReturn = 0.0;

	/*
	** Interchange the angular momenta such that the smallest j-value 
	** is placed in position 2. A parameter is set to remember the interchange 
	**   iChange  = -1 - j1 is placed in position 2.  
	**            =  0 - no change                       
	**            =  1 - j3 is placed in position 2.  
	*/

	if((iJ1 < iJ2) && (iJ1 < iJ3)) {        // interchange 1 and 2
		iTemp = iJ1; iJ1 = iJ2; iJ2 = iTemp;
		iTemp = iM1; iM1 = iM2; iM2 = iTemp;
		iChange = -1;
	} else if((iJ3 < iJ1) && (iJ3 < iJ2)) { // interchange 2 and 3
		iTemp = iJ2; iJ2 = iJ3; iJ3 = iTemp;
		iM2 = -(iM1 + iM2);
		iChange = 1;
	} else {
		iChange = 0;
	}

	// Test of angular momentum relations

	iJz1 = (iJ1 + iJ2 - iJ3)/2;
	iJz2 = (iJ1 + iJ3 - iJ2)/2;
	iJz3 = (iJ2 + iJ3 - iJ1)/2;

	if((iJz1 < 0) || (iJz2 < 0) || (iJz3 < 0)) return dReturn;

	// Test of angular projection relations

	if((iJ1 < abs(iM1)) || (iJ2 < abs(iM2)) || (iJ3 < abs(iM1 + iM2))) return dReturn;

	// Definition of loop parameters

	iJt1 = (iJ1 - iJ3 + iM2)/2;
	iJt2 = (iJ2 - iJ3 - iM1)/2;
	iJt3 = (iJ1 - iM1)/2;
	iJt4 = (iJ2 + iM2)/2;
	iJt5 = (iJ2 - iM2)/2;
	iJ4  = iJ1/2;
	iJ5  = iJ3/2;

	// Loop limits

	iLoopMin = MAX(MAX(iJt1, iJt2), 0);
	iLoopMax = MIN(MIN(iJt3, iJt4), iJz1);

	// Loop test

	if(iLoopMin > iLoopMax) return dReturn;

	// Maximum factorials test

	if((iJz1 > FAC_LIMIT) || (iJz3 > FAC_LIMIT) || (iJt4 > FAC_LIMIT) || (iJt5 > FAC_LIMIT)) {
		cout << "Error: Too large factorial in fClebschGordan" << endl;
		exit(1);
	}

	for(iLoop = iLoopMin, iPhase = PHASE(iLoopMin); iLoop <= iLoopMax; iPhase *= -1, iLoop++) {
		dReturn += (fFacRatio(iJt3-iLoop,iJ4) / aFac[iJt4-iLoop])
		         * (fFacRatio(iLoop-iJt2,iJ5) / aFac[iLoop-iJt1])
		         * ((iPhase/aFac[iJz1-iLoop]) / aFac[iLoop]);
	}

	dFactor = fFacRatio(iJ4,(iJ1 + iM1)/2) * fFacRatio(iJ4,iJt3)
					* fFacRatio((iJ1 + iJ2 + iJ3)/2 + 1,iJz2)
					* fFacRatio(iJ5,(iJ3 + iM1 + iM2)/2)
					* fFacRatio(iJ5,(iJ3 - iM1 - iM2)/2)
					* aFac[iJt4] * aFac[iJt5] * aFac[iJz1] * aFac[iJz3]
					* (iJ3 + 1);
	dReturn *= sqrt(dFactor);

	// Add the angular momentum interchange factor

	if(iChange == -1) {
		dReturn *= PHASE(iJz1);
	} else if(iChange == 1) {
		dReturn *= PHASE(iJt3) * sqrt((iJ2 + 1.0) / (iJ3+1.0));
	}
	
	return dReturn;
}

/*
**  fFacRatio
** ~~~~~~~~~~~
** - Function used by fClebschGordan
*/
double fFacRatio(int iM, int iN) {

  int    iHigh;
  double dReturn;

  dReturn = 1.0;
  
  // Return for n equal m
  if(iN == iM) return dReturn;

  iHigh = MAX(iN,iM); 
  for(int i = MIN(iN,iM)+1; i <= iHigh; i++) dReturn *= i;

	// Return for n less than m
  if(iN < iM) return (1.0/dReturn);
  
  // Return for n greater than m
  return dReturn;
}

/*
** Random Number Generator
** by Morten H. Jensen (modified)
**
** Seed must be <= -1 (long)
*/

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

double fRan(long *lIdum) {

	int  j;
	long k;
	static long iy=0;
	static long iv[NTAB];
	double dTemp;

	if(*lIdum <= 0 || !iy) {
		if(-(*lIdum) < 1) *lIdum=1;
		else *lIdum = -(*lIdum);
		for(j=NTAB+7; j>=0; j--) {
			k = (*lIdum)/IQ;
			*lIdum = IA*(*lIdum-k*IQ)-IR*k;
			if(*lIdum < 0) *lIdum += IM;
			if(j < NTAB) iv[j] = *lIdum;
		}
		iy = iv[0];
	}

	k = (*lIdum)/IQ;
	*lIdum = IA*(*lIdum-k*IQ)-IR*k;
	if(*lIdum < 0) *lIdum += IM;
	j = iy/NDIV;
	iy = iv[j];
	iv[j] = *lIdum;

	if((dTemp=AM*iy) > RNMX) return RNMX;
	else return dTemp;
}

} // End namespace tardis
