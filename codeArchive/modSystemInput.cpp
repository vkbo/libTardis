/*
**  modSystemInput.cpp
** ~~~~~~~~~~~~~~~~~~~~
**  Module for J and M-Scheme input and conversion for class System
*/

#include "libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
**  ReadJ
** ~~~~~~~
** - Reads J-scheme data from specified input file into an armadillo array
** - Second input is number of particle interactions, 1, 2 or 3.
** - File must be on format iParticles*<n l j n l j> + <2 x Total Isospin> + <2 x J_t> [+ <Strangeness>] + <Energy>
*/
void System::ReadJ(char const* sInputFile, int iPartInt) {
	
	mat mTemp;
	int iAdd = 0;

	mTemp.load(sInputFile);
	
	unsigned int iQNum = 6*(unsigned int)iPartInt;
	unsigned int iCols = mTemp.n_cols;
	unsigned int iRows = mTemp.n_rows;
	SchNo = iRows;
	
	if(iCols < iQNum + 3) {
		cout << "Error: Input file '" << sInputFile << "' has the wrong format." << endl;
		return;
	}
	
	SchQn.set_size(iRows,2*iPartInt);
	SchQmj.set_size(iRows,2*iPartInt);
	SchQ2s.set_size(iRows,2*iPartInt);
	SchQl.set_size(iRows,2*iPartInt);
	SchQ2j.set_size(iRows,2*iPartInt);
	SchQ2t.set_size(iRows,2*iPartInt);
	SchQ2tz.set_size(iRows,2*iPartInt);
	SchQS.set_size(iRows,2*iPartInt);
	SchEn.set_size(iRows);
	
	for(unsigned int i=0; i<mTemp.n_rows; i++) {
		for(unsigned int j=0; j<iQNum; j++) SchQn(i,j) = (int)mTemp(i,j);
		SchQ2tz(i) = (int)mTemp(i,iQNum);
		SchQ2j(i) = (int)mTemp(i,iQNum+1);
		if(iCols - iQNum > 3) {
			SchQS(i) = (int)mTemp(i,iQNum+2);
			iAdd = 1;
		} else {
			SchQS(i) = 0;
		}
		SchEn(i) = mTemp(i,iQNum+iAdd+2);
	}
}

/*
**  ReadM
** ~~~~~~~
** - Reads M-scheme data from specified input file into an armadillo array
** - Second input is number of particle interactions, 1, 2 or 3.
** - File must be on format iParticles*<n l j mj n l j mj> + <Energy>
*/
void System::ReadM(char const* sInputFile, int iPartInt) {
	
	mat mTemp;

	mTemp.load(sInputFile);
	
	unsigned int iQNum = 8*(unsigned int)iPartInt;
	unsigned int iCols = mTemp.n_cols;
	unsigned int iRows = mTemp.n_rows;
	SchNo = iRows;
	
	if(iCols != iQNum + 1) {
		cout << "Error: Input file '" << sInputFile << "' has the wrong format." << endl;
		return;
	}
	
	SchQn.set_size(iRows,iQNum);
	SchEn.set_size(iRows);
	
	for(unsigned int i=0; i<mTemp.n_rows; i++) {
		for(unsigned int j=0; j<iQNum; j++) SchQn(i,j) = (int)mTemp(i,j);
		SchEn(i) = mTemp(i,iQNum+1);
	}
}

/*
**  JtoM
** ~~~~~~~
*/
void System::JtoM() {
	
}
