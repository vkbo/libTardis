#ifndef __PROJECT__NT2__SUN_JAN_29_20_10_41_2006__FILE__MQR_ITF_HH__INCLUDED
#define __PROJECT__NT2__SUN_JAN_29_20_10_41_2006__FILE__MQR_ITF_HH__INCLUDED

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
//  what        : mqr_itf.hh                                         
//  who         : Jean-Thierry LAPRESTE 
//  when        : Sun Jan 29 20:10:41 2006                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
//
// This is a grouping of xormqr and xunmqr LAPACK routines
//
// /////////////////////////////////////////////////////////////////////////////
#include "ormqr_itf.hh"
#include "unmqr_itf.hh"


/*! \file mqr_itf.hh

   **   xORMQR (xUNMQR) generates an M-by-N  matrix Q with orthonormal columns,
   **  which is defined as the first N columns of a product of K elementary
   **  reflectors of order M
    
   **  (excerpt adapted from xormqr.f (xunmqr.f))
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
   **  TAU     (input) DATA array, dimension (K)
   **          TAU(i) must contain the scalar factor of the elementary
   **          reflector H(i), as returned by xGEQRF.
   **  C       (input/output) REAL array, dimension (LDC,N)
   **          On entry, the M-by-N matrix C.
   **          On exit, C is overwritten by Q*C or Q**T*C or C*Q**T or C*Q.
   **
   **  LDC     (input) INTEGER
   **          The leading dimension of the array C. LDC >= max(1,M).
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
   inline void mqr(
        const char* side,
        const char* trans,
        const long int* m,
        const long int* n,
        const long int* k,
        const float* a,
        const long int* lda,
        const float* tau,
        float* c,
        const long int* ldc,
        long int* info,
        wkspace<float> & w)
  */
  /*! fn
   inline void mqr(
        const char* side,
        const char* trans,
        const long int* m,
        const long int* n,
        const long int* k,
        const float* a,
        const long int* lda,
        const float* tau,
        float* c,
        const long int* ldc,
        long int* info)
  */
  /*! fn
   inline void mqr(
        const char* side,
        const char* trans,
        const long int* m,
        const long int* n,
        const long int* k,
        const double* a,
        const long int* lda,
        const double* tau,
        double* c,
        const long int* ldc,
        long int* info,
        wkspace<double> & w)
  */
  /*! fn
   inline void mqr(
        const char* side,
        const char* trans,
        const long int* m,
        const long int* n,
        const long int* k,
        const double* a,
        const long int* lda,
        const double* tau,
        double* c,
        const long int* ldc,
        long int* info)
  */
  /*! fn
   inline void mqr(
       const char* side,
       const char* trans,
       const long int* m,
       const long int* n,
       const long int* k,
       const std::complex<float>* a,
       const long int* lda,
       const std::complex<float>* tau,
       std::complex<float>* c,
       const long int* ldc,
       long int* info,
       workspace<complex<float> > & w)
  */
  /*! fn
   inline void mqr(
       const char* side,
       const char* trans,
       const long int* m,
       const long int* n,
       const long int* k,
       const std::complex<float>* a,
       const long int* lda,
       const std::complex<float>* tau,
       std::complex<float>* c,
       const long int* ldc,
       long int* info)
  */
  /*! fn
   inline void mqr(
       const char* side,
       const char* trans,
       const long int* m,
       const long int* n,
       const long int* k,
       const std::complex<double>* a,
       const long int* lda,
       const std::complex<double>* tau,
       std::complex<double>* c,
       const long int* ldc,
       long int* info,
       workspace<complex<double> > & w)
  */
  /*! fn
   inline void mqr(
       const char* side,
       const char* trans,
       const long int* m,
       const long int* n,
       const long int* k,
       const std::complex<double>* a,
       const long int* lda,
       const std::complex<double>* tau,
       std::complex<double>* c,
       const long int* ldc,
       long int* info)
  */




#define LPP_MQR(NAME, T)                                                \
  inline void mqr(                                                      \
                  const char* side,                                     \
                  const char* trans,                                    \
                  const long int* m,                                    \
                  const long int* n,                                    \
                  const long int* k,                                    \
                  const T* a,                                           \
                  const long int* lda,                                  \
                  const T* tau,                                         \
                  T* c,                                                 \
                  const long int* ldc,                                  \
                  long int* info,                                       \
                  workspace<T> & w)                                     \
  {                                                                     \
    NAME(side, trans, m, n, k, a, lda, tau, c, ldc, info, w);           \
  }                                                                     \
  inline void mqr(                                                      \
                  const char* side,                                     \
                  const char* trans,                                    \
                  const long int* m,                                    \
                  const long int* n,                                    \
                  const long int* k,                                    \
                  const T* a,                                           \
                  const long int* lda,                                  \
                  const T* tau,                                         \
                  T* c,                                                 \
                  const long int* ldc,                                  \
                  long int* info)                                       \
  {                                                                     \
    workspace < T > w;                                                  \
    NAME(side, trans, m, n, k, a, lda, tau, c, ldc, info, w);           \
  }                                                                     \

  LPP_MQR(ormqr, double)
    LPP_MQR(ormqr, float)  
    LPP_MQR(unmqr, std::complex<double>)
    LPP_MQR(unmqr, std::complex<float>)
    
#undef LPP_MQR      
 
}

// /////////////////////////////////////////////////////////////////////////////
//  End of lpp namespace
// /////////////////////////////////////////////////////////////////////////////


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of mqr_itf.hh
// /////////////////////////////////////////////////////////////////////////////
