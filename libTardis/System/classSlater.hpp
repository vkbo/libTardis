/*
** ~ libTardis ~
**
** Class :: Slater
*/

#ifndef CLASS_SLATER_HPP

#define CLASS_SLATER_HPP
#include "../libTardis.hpp"
#include <bitset>

#ifndef SLATER_WORD
    #define SLATER_WORD 64
#endif

namespace tardis {

class Slater
{
    public:
    std::bitset<SLATER_WORD> Word;
    Slater() {};
    ~Slater() {};

    int  Create(int);
    int  Annihilate(int);
    bool Equal(Slater);
    int  Compare(Slater);
    void Zero();
    int  Count();
    int  CountOdd();
    int  CountEven();
    int  GetFirst();
    int  IsSet(int);
    void Output(int);
};

} // End namespace tardis

#endif
