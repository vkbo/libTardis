#ifndef __PROJECT__NT2__SUN_JAN_29_20_10_41_2006__FILE__GQR_ITF_HH__INCLUDED
#define __PROJECT__NT2__SUN_JAN_29_20_10_41_2006__FILE__GQR_ITF_HH__INCLUDED

////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2006 for LASMEA UMR 6602 du CNRS.                  
//  All rights reserved.                                             
//                                                                   
//  This file is part of the NT2 C++ Library.  This library is       
//  free software; you can redistribute it and/or modify it under    
//  the terms of the GNU Lesser General Public License as published  
//  by the Free Software Foundation; either version 2.1, or (at      
//  your option) any later version.                                  
//                                                                   
//  This library is distributed in the hope that it will be useful,  
//  but WITHOUT ANY WARRANTY; without even the implied warranty of   
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    
//  GNU Lesser General Public License for more details.              
//                                                                   
//  You should have received a copy of the GNU Lesser General        
//  Public License along with this library; see the file COPYING.    
//  If not, send mail to the developers of NT2                       
//                                                                   
//  As a special exception, you may use this file as part of a free  
//  software library without restriction.  Specifically, if other    
//  files instantiate templates or use macros or inline functions    
//  from this file, or you compile this file and link it with other  
//  files to produce an executable, this file does not by itself     
//  cause the resulting executable to be covered by the GNU Lesser   
//  General Public License.  This exception does not however         
//  invalidate any other reasons why the executable file might be    
//  covered by the GNU Lesser General Public License.                
//                                                                   
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  what        : gqr_itf.hh                                         
//  who         : Jean-Thierry LAPRESTE 
//  when        : Sun Jan 29 20:10:41 2006                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
//
// This is a grouping of xorgqr and xungqr LAPACK routines
//
// /////////////////////////////////////////////////////////////////////////////
#include "orgqr_itf.hh"
#include "ungqr_itf.hh"


/*! \file gqr_itf.hh

   **   xORGQR (xUNGQR) generates an M-by-N  matrix Q with orthonormal columns,
   **  which is defined as the first N columns of a product of K elementary
   **  reflectors of order M
    
   **  (excerpt adapted from xorgqr.f (xungqr.f))
   **  Arguments
   **  =========
   **
   **  M       (input) INTEGER
   **          The number of rows of the matrix Q. M >= 0.
   **
   **  N       (input) INTEGER
   **          The number of columns of the matrix Q. M >= N >= 0.
   **
   **  K       (input) INTEGER
   **          The number of elementary reflectors whose product defines the
   **          matrix Q. N >= K >= 0.
   **
   **  A       (input/output) DATA array, dimension (LDA,N)
   **          On entry, the i-th column must contain the vector which
   **          defines the elementary reflector H(i), for i = 1,2,...,k, as
   **          returned by xGEQRF in the first k columns of its array
   **          argument A.
   **          On exit, the M-by-N matrix Q.
   **
   **  LDA     (input) INTEGER
   **          The first dimension of the array A. LDA >= max(1,M).
   **
   **  TAU     (input) COMPLEX*16 array, dimension (K)
   **          TAU(i) must contain the scalar factor of the elementary
   **          reflector H(i), as returned by xGEQRF.
   **
   **  info    (output) long int
   **          = 0:  successful exit
   **          < 0:  if info = -i, the i-th argument has an illegal value
**/

// /////////////////////////////////////////////////////////////////////////////
//  Beginning of lpp namespace
// /////////////////////////////////////////////////////////////////////////////

namespace lpp
{

  
  // The following macro provides the 8 functions 
  /*! fn
   inline void gqr(
        const long int* m,
        const long int* n,
        const long int* k,
        float* a,
        const long int* lda,
        const float* tau,
        long int* info,
        wkspace<float> & w)
  */
  /*! fn
   inline void gqr(
        const long int* m,
        const long int* n,
        const long int* k,
        float* a,
        const long int* lda,
        const float* tau,
        long int* info)
  */
  /*! fn
   inline void gqr(
        const long int* m,
        const long int* n,
        const long int* k,
        double* a,
        const long int* lda,
        const double* tau,
        long int* info,
        wkspace<double> & w)
  */
  /*! fn
   inline void gqr(
        const long int* m,
        const long int* n,
        const long int* k,
        double* a,
        const long int* lda,
        const double* tau,
        long int* info)
  */
  /*! fn
   inline void gqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<float>* a,
       const long int* lda,
       const std::complex<float>* tau,
       long int* info,
       workspace<complex<float> > & w)
  */
  /*! fn
   inline void gqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<float>* a,
       const long int* lda,
       const std::complex<float>* tau,
       long int* info)
  */
  /*! fn
   inline void gqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<double>* a,
       const long int* lda,
       const std::complex<double>* tau,
       long int* info,
       workspace<complex<double> > & w)
  */
  /*! fn
   inline void gqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<double>* a,
       const long int* lda,
       const std::complex<double>* tau,
       long int* info)
  */

#define LPP_GQR(NAME, T)                                                \
  inline void gqr(long int* m, long int* n,long int* k,                 \
                  T* a, long int* lda,                                  \
                  T* tau,                                               \
                  long int* info,                                       \
                  workspace < T >  w)                                   \
  {                                                                     \
    NAME(m, n, k, a, lda, tau, info, w);                                \
  }                                                                     \
  inline void gqr(long int* m, long int* n,long int* k,                 \
                  T* a, long int* lda,                                  \
                  T* tau,                                               \
                  long int* info)                                       \
  {                                                                     \
    workspace < T >  w;                                                 \
    gqr(m, n, k, a, lda, tau, info, w);                                 \
  }                                                                     \
    
  LPP_GQR(orgqr, double)
    LPP_GQR(orgqr, float)  
    LPP_GQR(ungqr, std::complex<double>)
    LPP_GQR(ungqr, std::complex<float>)
    
#undef LPP_GQR      
 
}

// /////////////////////////////////////////////////////////////////////////////
//  End of nt2 namespace
// /////////////////////////////////////////////////////////////////////////////


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of gqr_itf.hh
// /////////////////////////////////////////////////////////////////////////////
