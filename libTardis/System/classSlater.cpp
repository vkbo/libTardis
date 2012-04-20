/*
** ~ libTardis ~
**
** Class :: Slater
*/

#include "../libTardis.hpp"

using namespace std;
using namespace tardis;

/*
** Annihilate particle in position i
**  - If the particle doesn't exist, calculates the parity and returns it
**  - Otherwise returns 0
*/
int Slater::Create(int i) {
    if(!Word.test(i)) {
        Word.set(i,true);
        int iP = (Word<<(SLATER_WORD-i)).count();
        return 1-2*(iP%2);
    } else {
        return 0;
    }
}

/*
** Annihilate particle in position i
**  - If the particle exists, calculates the parity and returns it
**  - Otherwise returns 0
*/
int Slater::Annihilate(int i) {
    if(Word.test(i)) {
        Word.set(i,false);
        int iP = (Word<<(SLATER_WORD-i)).count();
        return 1-2*(iP%2);
    } else {
        return 0;
    }
}

/*
** Checks if the SDs are equal
*/
bool Slater::Equal(Slater sdTest) {
    return (Word==sdTest.Word);
}

/*
** Function for checking if a SD is before or after a given SD in a sorted basis
**  - This function first does a check if the SDs are equal. If so, return 0
**  - Next it does an XOR operation on the two SDs returning a Word with a 1 for
**      each bit that are not equal
**  - Then it looks for the first un-equal bit in that word
**  - The SD that contains a 1 in that position is the one with the largest index
**  - If this is the base-word, return 1
**  - Otherwise return -1
*/
int Slater::Compare(Slater sdTest) {
    if(Word==sdTest.Word) return 0;
    if(Word.test((Word^sdTest.Word)._Find_first())) return 1;
    return -1;
}

/*
** Sets the SD to zero or vacuum state |0>
*/
void Slater::Zero() {
    Word.reset();
    return;
}

/*
** Counts the number of 1s in the SD
**  - Wrapper for bitset-count()
*/
int Slater::Count() {
    return Word.count();
}

/*
** Counts the number of 1s in odd positions in the SD
*/
int Slater::CountOdd() {
    int iCount = 0;
    for(int i=1; i<SLATER_WORD; i+=2) iCount+=Word[i];
    return iCount;
}

/*
** Counts the number of 1s in even positions in the SD
*/
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

/*
** Formatted output of the SD
*/
void Slater::Output(int iLen) {
    if(iLen > SLATER_WORD) iLen = SLATER_WORD;
    cout << "|";
    for(int i=0; i<iLen; i++) cout << Word[i];
    cout << ">" << endl;
    return;
}
