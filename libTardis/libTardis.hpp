/*
**                         ~ Library: libTARDIS ~
**
** o––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––o
** | This is my timey-wimey detector. It goes ding when there's stuff.  |
** | Also, it can boil an egg at 30 paces, whether you want it to or    |
** | not, actually, so I've learned to stay away from hens. It's not    |
** | pretty when they blow.                                             |
** |                                                                    |
** | People assume that time is a strict progression of cause-of-effect |
** | ... but actually, from a non-linear, non-subjective viewpoint,     |
** | it's more like a big ball of wibbly-wobbly ... timey-wimey ...     |
** | stuff.                                                             |
** |                                                                    |
** |                                     - Doctor Who (Episode "Blink") |
** o––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––o
**
*/

#ifndef LIBTARDIS_HPP
#define LIBTARDIS_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <armadillo>

#include "config.hpp"


/*
**  System Variables
** ==================
*/

// Quantum numbers
#define QN_M       100 // Total M value
#define QN_MS      101 // Total spin value
#define QN_EMAX    102 // Energy cut value

// Variables
#define VAR_LAMBDA 200 // Interaction strength
#define VAR_OMEGA  201 // Harmonic oscillator frequency
#define VAR_1PFAC  202 // For internal use
#define VAR_2PFAC  203 // For internal use


/*
**  Systems (Potentials)
** ======================
*/

// Atomic electrons                     ** NOT IMPLEMENTED **
#define ATOM 1

// Quantum dots in 2 dimensions
#define QDOT2D 2
    #define Q2D_ANALYTIC  20 // Using analytic expression (Anisimovas and Matulis)
    #define Q2D_NORMAL    21 // Using OpenFCI (Simen Kvaal) without effective interaction
    #define Q2D_EFFECTIVE 22 // Using OpenFCI (Simen Kvaal) with effective interaction

// Quantum dots in 3 dimensions         ** NOT IMPLEMENTED **
#define QDOT3D 3

// Atomic nucleus                       ** NOT IMPLEMENTED **
#define NUCLEUS 4

// Atomic nucleus with strangeness != 0 ** NOT IMPLEMENTED **
#define HNUCLEUS 5


/*
**  Other Variables
** =================
*/

#define KBYTE 1024
#define MBYTE 1048576
#define GBYTE 1073741824

#define F_ASCII  0
#define F_BINARY 1

#define OUTPUTF(p) showpoint << setw((p+2)) << setprecision((p))
#define OUTPUTN(p) noshowpoint << setw((p+2)) << setprecision((p))

#define SAVE_BASIS_ASC  0
#define SAVE_BASIS_ARMA 1
#define SAVE_COEFF_ARMA 2

/*
**  Classes and Includes
** ======================
*/

// Solver Classes
#include "CISD/classDiag.hpp"
#include "CISD/classLanczos.hpp"

// Potential Classes
#include "Potential/classPotential.hpp"
#include "Potential/classQDot2D.hpp"

// System Classes
#include "System/classSystem.hpp"
#include "System/classLog.hpp"
#include "System/classBasis.hpp"
#include "System/classSlater.hpp"

// Physics Classes
#include "Physics/classDensity.hpp"

#endif
