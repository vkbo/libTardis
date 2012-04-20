/*
** ~ libTardis ~
**
** Class :: Slater
*/

#ifndef CLASS_SLATER_HPP

#define CLASS_SLATER_HPP
#include "../libTardis.hpp"
#include <bitset>
#include <vector>

#ifndef SLATER_WORD
    #define SLATER_WORD 64
#endif
//#include <boost/dynamic_bitset.hpp>
// URL: http://www.boost.org/doc/libs/1_49_0/libs/dynamic_bitset/dynamic_bitset.html
//#define BOOST_BITSET

namespace tardis {

class Slater
{
    public:
    #ifndef BOOST_BITSET
        std::bitset<SLATER_WORD> Word;
        Slater() {};
    #else
        boost::dynamic_bitset<> Word;
        Slater() {Word.resize(SLATER_WORD);};
    #endif
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
    void Output(int);
};

} // End namespace tardis

#endif
