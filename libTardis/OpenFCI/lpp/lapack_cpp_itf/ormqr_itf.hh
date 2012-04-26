#ifndef __PROJECT__LPP__FILE__ORMQR_HH__INCLUDED
#define __PROJECT__LPP__FILE__ORMQR_HH__INCLUDED

////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2005 for LASMEA UMR 6602 du CNRS.                  
//  All rights reserved.                                             
//                                                                   
//  This file is part of the LPP C++ Library.  This library is       
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
//  If not, send mail to the developers of LPP                       
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
//  what        : ormqr_itf.hh C++ interface to LAPACK (s,d,c,z)ormqr
//  who         : contributed by Jean-Thierry LAPRESTE 
//  when        : Thu Dec 15 07:00:44 2005                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*! \file ormqr_itf.hh
    (excerpt adapted from xormqr.f file commentaries)
    
    DATA TYPE can mean float, double, std::complex<float>, std::complex<double>
    
    BASE TYPE can mean respectively float, double, float, double
    
    In some cases only two of these types types are available
    the two real or the two std::complex ones.
    CAPITALIZED PARAMETERS are FORTRAN parameters who are not used directly
    in the C++ calls, but through the workspace parameter,
    their use is transparent for the caller (see lapackworkspace.hh)

    *
    **  purpose
    **  =======
    **
    **  xormqr overwrites the general BASE DATA TYPE m-by-n matrix c with
    **
    **                  side = 'l'     side = 'r'
    **  trans = 'n':      q * c          c * q
    **  trans = 't':      q**t * c       c * q**t
    **
    **  where q is a BASE DATA TYPE orthogonal matrix defined as the product of k
    **  elementary reflectors
    **
    **        q = h(1) h(2) . . . h(k)
    **
    **  as returned by dgeqrf. q is of order m if side = 'l' and of order n
    **  if side = 'r'.
    **
    **  arguments
    **  =========
    **
    **  side    (input) char
    **          = 'l': apply q or q**t from the left;
    **          = 'r': apply q or q**t from the right.
    **
    **  trans   (input) char
    **          = 'n':  no transpose, apply q;
    **          = 't':  transpose, apply q**t.
    **
    **  m       (input) long int
    **          the number of rows of the matrix c. m >= 0.
    **
    **  n       (input) long int
    **          the number of columns of the matrix c. n >= 0.
    **
    **  k       (input) long int
    **          the number of elementary reflectors whose product defines
    **          the matrix q.
    **          if side = 'l', m >= k >= 0;
    **          if side = 'r', n >= k >= 0.
    **
    **  a       (input) BASE DATA TYPE array, dimension (lda,k)
    **          the i-th column must contain the vector which defines the
    **          elementary reflector h(i), for i = 1,2,...,k, as returned by
    **          dgeqrf in the first k columns of its array argument a.
    **          a is modified by the routine but restored on exit.
    **
    **  lda     (input) long int
    **          the leading dimension of the array a.
    **          if side = 'l', lda >= max(1,m);
    **          if side = 'r', lda >= max(1,n).
    **
    **  tau     (input) BASE DATA TYPE array, dimension (k)
    **          tau(i) must contain the scalar factor of the elementary
    **          reflector h(i), as returned by dgeqrf.
    **
    **  c       (input/output) BASE DATA TYPE array, dimension (ldc,n)
    **          on entry, the m-by-n matrix c.
    **          on exit, c is overwritten by q*c or q**t*c or c*q**t or c*q.
    **
    **  ldc     (input) long int
    **          the leading dimension of the array c. ldc >= max(1,m).
    **
    **
    **
    **  info    (output) long int
    **          = 0:  successful exit
    **          < 0:  if info = -i, the i-th argument had an illegal value
    **
**/
/////////////////////////////////////////////////////////////////////////////////


// /////////////////////////////////////////////////////////////////////////////
//  Beginning of lpp namespace
// /////////////////////////////////////////////////////////////////////////////
namespace lpp
{
  
  // /////////////////////////////////////////////////////////////////////////////
  //  macros interfaces to FORTRAN calls
  // /////////////////////////////////////////////////////////////////////////////




  // The following macro provides the 4 functions 
  /*! fn
   inline void ormqr(
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
        workspace<float> & w)
  */
  /*! fn
   inline void ormqr(
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
   inline void ormqr(
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
        workspace<double> & w)
  */
  /*! fn
   inline void ormqr(
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


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from sormqr.f)
  //    *  WORK    (workspace/output) float array, dimension (LWORK)
  //    *          On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
  //    *
  //    *  LWORK   (input) long int
  //    *          The dimension of the array WORK.
  //    *          If SIDE = 'L', LWORK >= max(1,N);
  //    *          if SIDE = 'R', LWORK >= max(1,M).
  //    *          For optimum performance LWORK >= N*NB if SIDE = 'L', and
  //    *          LWORK >= M*NB if SIDE = 'R', where NB is the optimal
  //    *          blocksize.
  //    *
  //    *          If LWORK = -1, then a workspace query is assumed; the routine
  //    *          only calculates the optimal size of the WORK array, returns
  //    *          this value as the first entry of the WORK array, and no error
  //    *          message related to LWORK is issued by XERBLA.
  //    *
  /////////////////////////////////////////////////////////////////////////

#define LPP_ORMQR(NAME, T)\
inline void ormqr(\
    const char* side,\
    const char* trans,\
    const long int* m,\
    const long int* n,\
    const long int* k,\
    const T* a,\
    const long int* lda,\
    const T* tau,\
    T* c,\
    const long int* ldc,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(side, trans, m, n, k, a, lda, tau, c, ldc, w.getw(), w.query(), info);\
    w.resizew(w.neededsize());\
    F77NAME( NAME )(side, trans, m, n, k, a, lda, tau, c, ldc, w.getw(), &w.neededsize(), info);\
}\
inline void ormqr(\
    const char* side,\
    const char* trans,\
    const long int* m,\
    const long int* n,\
    const long int* k,\
    const T* a,\
    const long int* lda,\
    const T* tau,\
    T* c,\
    const long int* ldc,\
    long int* info)\
{\
   workspace<T> w;\
   ormqr(side, trans, m, n, k, a, lda, tau, c, ldc, info, w);\
}\

    LPP_ORMQR(sormqr, float)
    LPP_ORMQR(dormqr, double)

#undef LPP_ORMQR



}
#endif

// /////////////////////////////////////////////////////////////////////////////
// End of ormqr_itf.hh
// /////////////////////////////////////////////////////////////////////////////
