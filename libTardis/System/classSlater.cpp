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

bool Slater::Equal(Slater sdTest) {
    return (Word==sdTest.Word);
}

int Slater::Compare(Slater sdTest) {
    if(Word==sdTest.Word) return 0;
    if(Word.test((Word^sdTest.Word)._Find_first())) return 1;
    return -1;
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

/*
**  This function uses the experimental method _Find_first() from the bitset class
**   - See stl source code: http://www.sgi.com/tech/stl/bitset
*/
int Slater::GetFirst() {
    return Word._Find_first();
}

void Slater::Output(int iLen) {
    if(iLen > SLATER_WORD) iLen = SLATER_WORD;
    cout << "|";
    for(int i=0; i<iLen; i++) cout << Word[i];
    cout << ">" << endl;
    return;
}
