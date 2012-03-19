/*
** ~ libTardis ~
**
** Class :: Slater
*/

#include "../libTardis.hpp"

using namespace std;
using namespace tardis;

int Slater::Create(int i) {
	if(!Word.test(i)) {
		Word.set(i,true);
		int iP = (Word<<(SLATER_WORD-i)).count();
		return 1-2*(iP%2);
	} else {
		return 0;
	}
}

int Slater::Annihilate(int i) {
	if(Word.test(i)) {
		Word.set(i,false);
		int iP = (Word<<(SLATER_WORD-i)).count();
		return 1-2*(iP%2);
	} else {
		return 0;
	}
}

bool Slater::Compare(Slater sdTest) {
	return (Word^sdTest.Word).none();
}

int Slater::Count() {
	return Word.count();
}

int Slater::CountOdd() {
	int iCount = 0;
	for(int i=1; i<SLATER_WORD; i+=2) iCount+=Word[i];
	return iCount;
}

int Slater::CountEven() {
	int iCount = 0;
	for(int i=0; i<SLATER_WORD; i+=2) iCount+=Word[i];
	return iCount;
}

void Slater::Output(int iLength) {
	if(iLength > SLATER_WORD) iLength = SLATER_WORD;
	cout << "|";
	for(int i=0; i<iLength; i++) cout << Word[i];
	cout << ">" << endl;
	return;
}
