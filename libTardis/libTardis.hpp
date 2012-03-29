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

#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <armadillo>

#include "config.hpp"

// Variables
#define KBYTE 1024
#define MBYTE 1048576
#define GBYTE 1073741824

// Systems
#define ATOM     0
#define QDOT2D   1
#define QDOT3D   2
#define NUCLEUS  3
#define HNUCLEUS 4

// Other
#define OUTPUTF(p) showpoint << setw((p+2)) << setprecision((p))
#define OUTPUTN(p) noshowpoint << setw((p+2)) << setprecision((p))

// Classes
#ifndef CLASS_LANCZOS_HPP
    #include "CISD/classLanczos.hpp"
#endif

#ifndef CLASS_BASIS_HPP
    #include "System/classBasis.hpp"
#endif

#ifndef CLASS_SYSTEM_HPP
    #include "System/classSystem.hpp"
#endif

#ifndef CLASS_QDOT2D_HPP
  #include "System/classQDot2D.hpp"
#endif

#ifndef CLASS_SLATER_HPP
  #include "System/classSlater.hpp"
#endif
