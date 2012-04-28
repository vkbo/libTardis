/*
** ~ Library: TARDIS ~
** o-------------------------------------------------------------------o
** | The Doctor: This is my timey-wimey detector. It goes ding when    |
** | there's stuff. Also, it can boil an egg at 30 paces, whether you  |
** | want it to or not, actually, so I've learned to stay away from    |
** | hens. It's not pretty when they blow.                             |
** |                                                      - Doctor Who |
** o-------------------------------------------------------------------o
*/

#ifndef LIBTARDIS_HPP
#define LIBTARDIS_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <armadillo>

#include "config.hpp"

// Variables
#define KBYTE 1024
#define MBYTE 1048576
#define GBYTE 1073741824

// System Conditions
#define QN_M       100
#define QN_MS      101
#define VAR_LAMBDA 200
#define VAR_OMEGA  201
#define VAR_1PFAC  202
#define VAR_2PFAC  203

// Systems
#define ATOM     1
#define QDOT2D   2
    #define Q2D_ANALYTIC  20
    #define Q2D_NORMAL    21
    #define Q2D_EFFECTIVE 22
#define QDOT3D   3
#define NUCLEUS  4
#define HNUCLEUS 5

// Other
#define OUTPUTF(p) showpoint << setw((p+2)) << setprecision((p))
#define OUTPUTN(p) noshowpoint << setw((p+2)) << setprecision((p))

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

#endif
