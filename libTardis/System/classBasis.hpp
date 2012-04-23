/*
** ~ libTardis ~
**
** Class :: Basis
*/

#ifndef CLASS_BASIS_HPP

#define CLASS_BASIS_HPP
#include "../libTardis.hpp"
#ifdef OPENMP
    #include "omp.h"
#endif

namespace tardis {

class Basis
{
    public:

    // Constructor and Destructor
    Basis(tardis::System*);
    ~Basis() {};

    // Public Functions
    int BuildBasis(int, int);
    int FindSlater(tardis::Slater, int, int);

    // Getters, Setters and Output
    int            GetSize();
    tardis::Slater GetSlater(int);
    void           Output();


    private:

    // Variables
    int  iParticles;
    int  iStates;
    bool b3PIndex;

    // Objects
    tardis::System                 *oSystem;

    // Vectors
    std::vector<tardis::Slater> vBasis;
    #ifdef INDEX_BASIS
        std::vector<std::vector<short> > vIndex;
    #else
        arma::Mat<int> mIndex;
    #endif

    // Functions
    //void fGenConfig(std::vector<int>&, int, int, int);
    //void fGenIndex();

};

} // End namespace tardis

#endif
