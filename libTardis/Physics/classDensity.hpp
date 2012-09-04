/*
** ~ libTardis ~
**
** Class :: Density
*/

#ifndef CLASS_DENSITY_HPP

#define CLASS_DENSITY_HPP
#include "../libTardis.hpp"

namespace tardis {

class Density
{
    public:

    Density(System*);
    ~Density() {};

    void OneBodyDensity();
    void TwoBodyDensity();


    private:

    // Objects
    System *oSystem;
    Basis  *oBasis;
    Log    *oOut;
};

} // End namespace tardis

#endif
