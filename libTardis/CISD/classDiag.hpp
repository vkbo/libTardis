/*
** ~ libTardis ~
**
** Class :: Diag
*/

#ifndef CLASS_DIAG_HPP

#define CLASS_DIAG_HPP
#include "../libTardis.hpp"
#include "../System/classSystem.hpp"

namespace tardis {

class Diag
{
    public:

    // Constructor and Destructor
    Diag(System*);
    ~Diag() {};

    // Public Functions
    double Run();


    private:

    // Variables
    int    iStates;
    int    iParticles;
    int    iM;
    int    iMs;
    double d1PFac;
    double d2PFac;

    // Objects
    System    *oSystem;
    Potential *oPot;

};

} // End namespace tardis

#endif
