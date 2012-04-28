/*
** ~ libTardis ~
**
** Class :: Basis
*/

#ifndef CLASS_BASIS_HPP

#define CLASS_BASIS_HPP
#include "../libTardis.hpp"
#include "../Potential/classPotential.hpp"
#include "classLog.hpp"
#include "classSlater.hpp"

#ifdef OPENMP
    #include "omp.h"
#endif

namespace tardis {

class Basis
{
    public:

    // Constructor and Destructor
    Basis(Potential*, Log*, int, int);
    ~Basis() {};

    // Public Functions
    int BuildBasis();
    int FindSlater(tardis::Slater, int p=0, int q=0);

    // Getters, Setters and Output
    int    GetSize()        {return vBasis.size();};
    Slater GetSlater(int i) {return vBasis.at(i);};
    void   Output();

    // System Configuration
    bool SetQNumber(int, int);
    int  GetQNumber(int);
    bool SetEnergyCut(bool);
    bool GetEnergyCut()       {return bEnergyCut;};


    private:

    // Variables
    int  iParticles;
    int  iStates;
    bool b3PIndex;
    bool bEnergyCut;

    // System Configuration
    int iM;      // Total M
    int iMs;     // Total Spin

    // Other Variables
    std::stringstream ssOut;  // stdout and log string

    // Objects
    Potential *oPot;  // Potential
    Log       *oOut;  // Logfile

    // Vectors
    std::vector<tardis::Slater> vBasis;
    #ifdef INDEX_BASIS
        std::vector<std::vector<short> > vIndex;
    #else
        arma::Mat<int> mIndex;
    #endif

    // Basis selection functions
    bool fCheckQDot2D(const std::vector<int>&);
};

} // End namespace tardis

#endif
