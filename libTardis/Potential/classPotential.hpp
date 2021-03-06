/*
** ~ libTardis ~
**
** Class :: Potential
*/

#ifndef CLASS_POTENTIAL_HPP

#define CLASS_POTENTIAL_HPP
#include "../libTardis.hpp"
#include "../System/classLog.hpp"

namespace tardis {

class Potential
{
    public:

    // Constructor and Destructor
    Potential(int, Log*) {};
    virtual ~Potential() {};

    // Public Functions
    virtual void Load(int)                 {return;};
    virtual void Generate(int, bool)       {return;};
    virtual void LoadOrGenerate(int, bool) {return;};

    // Setters
    virtual void SetCache(const char*) {return;};
    virtual void SetLambda(double)     {return;};
    virtual void SetEnergyCut(bool)    {return;};
    virtual void SetBlock(int, int)    {return;};

    // Getters
    virtual int  GetShells()        {return -1;};
    virtual int  GetStates()        {return -1;};
    virtual int  GetState(int, int) {return -1;};
    virtual bool GetEnergyCut()     {return false;};

    virtual double Get1PElement(int, int)           {return -1.0;};
    virtual double Get2PElement(int, int, int, int) {return -1.0;};

    virtual const arma::Mat<int>    *GetConfig(int, int) {return NULL;};
    virtual const arma::Col<double> *Get1PHam(int, int)  {return NULL;};
    virtual const arma::Mat<double> *Get2PHam(int, int)  {return NULL;};
};

} // End namespace tardis

#endif
