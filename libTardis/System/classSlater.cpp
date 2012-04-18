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
    return (Word==sdTest.Word);
}

bool Slater::After(Slater sdTest, int iStart, int iLen) {
    for(int i=iStart; i<iLen; i++) {
        if(sdTest.Word.test(i) && !Word.test(i)) return true;
        if(!sdTest.Word.test(i) && Word.test(i)) return false;
    }
    return false;
}

void Slater::Zero() {
    Word.reset();
    return;
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

int Slater::GetFirst(int iOffset) {
    for(int i=iOffset; i<SLATER_WORD; i++) if(Word.test(i)) return i;
    return -1;
}

void Slater::Output(int iLen) {
    if(iLen > SLATER_WORD) iLen = SLATER_WORD;
    cout << "|";
    for(int i=0; i<iLen; i++) cout << Word[i];
    cout << ">" << endl;
    return;
}
