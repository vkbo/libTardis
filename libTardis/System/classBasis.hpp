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
    int  BuildBasis(bool bOutputConfigs=false);
    bool LoadBasis(const char*);
    int  FindSlater(tardis::Slater, int p=0, int q=0);
    bool SortBasis();

    // Getters, Setters and Output
    int    GetSize()        {return vBasis.size();};
    Slater GetSlater(int i) {return vBasis.at(i);};
    bool   SetCoefficients(arma::Col<double>&);
    void   Output();
    bool   Save(const char*, int iMode=0);

    // System Configuration
    bool SetQNumber(int, int);
    int  GetQNumber(int);
    bool EnableEnergyCut(bool);


    private:

    // Variables
    int  iParticles;     // Number of particles
    int  iStates;        // Number of quantum states
    int  iShells;        // Number of shells
    bool bEnergyCut;     // Use Energy Cut?
    bool bEnergyCutSet;  // Is Energy Cut set manually?
    int  iEnergyCuts;    // Number of energy cuts done.

    // System Configuration
    int  iM;             // Total M
    int  iMs;            // Total Spin
    int  iEMax;          // Energy cut value

    // Other Variables
    std::stringstream ssOut;  // stdout and log string

    // Objects
    Potential *oPot;     // Potential
    Log       *oOut;     // Logfile

    // Vectors
    std::vector<tardis::Slater> vBasis;
    arma::Col<double>           mCoefficients;
    arma::Col<unsigned int>     mCoeffOrder;
    arma::Mat<int>              mConfigMap;
    #ifdef INDEX_BASIS
        std::vector<std::vector<short> > vIndex;
    #else
        arma::Mat<int> mIndex;
    #endif

    // Basis selection functions
    bool fCheckQDot2D(const std::vector<int>&, bool);
};

} // End namespace tardis

#endif
