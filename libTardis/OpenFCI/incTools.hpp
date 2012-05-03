#ifndef _TOOLS_HPP_
#define _TOOLS_HPP_

//
// Copyright (c) 2008 Simen Kvaal
//
// This file is part of OpenFCI.
//
// OpenFCI is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OpenFCI is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OpenFCI. If not, see <http://www.gnu.org/licenses/>.
//

/**
 *
 * \file tools.hpp
 * \author Simen Kvaal
 * \date 6-13-08
 *
 * \brief Some mathematical and other tools.
 *
 */

#include <string>
#include <sstream>
#include <cmath>
#include <vector>

/// \brief Compute ln(n!)
/// \param n number to take factorial of
inline double lnfact(int n) {
    double result = 0;
    for (int j=2; j<=n; ++j) result += log(j);
    return result;
}

/// \brief Compute n!.
/// \param n number to take factorial of
inline double fact(int n) {
    return exp(lnfact(n));
}

/// \brief Compute log of factorial, ln(n!/m!/(n-m)!)
/// \param n a number
/// \param m a number
inline double lnbinom(int n,int m) {
    return lnfact(n) - lnfact(m) - lnfact(n-m);
}

/// \brief Compute "n ober m" =  n!/(m!(n-m)!).
/// \param n a number
/// \param m a number
inline double binom(int n,int m) {
    return exp(lnbinom(n,m));
}

/// \brief Compute pow(-1,i). Used a lot!
template<typename T>
inline int m1pow(const T& i) {
    if (i % T(2) == T(1)) return -1;
    else                  return 1;
}

/// \brief Compute square of number; used a lot!
template<typename T>
inline T sqr(const T& x) {
    return x*x;
}

#endif
