#ifndef __PROJECT__LPP__FILE__UNGQR_HH__INCLUDED
#define __PROJECT__LPP__FILE__UNGQR_HH__INCLUDED

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
//  what        : ungqr_itf.hh C++ interface to LAPACK (c,d,c,z)ungqr
//  who         : contributed by Jean-Thierry LAPRESTE 
//  when        : Thu Dec 15 07:00:44 2005                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*! \file ungqr_itf.hh
    (excerpt adapted from xungqr.f file commentaries)
    
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
    **  xungqr generates an m-by-n DATA TYPE matrix q with orthonormal columns,
    **  which is defined as the first n columns of a product of k elementary
    **  reflectors of order m
    **
    **        q  =  h(1) h(2) . . . h(k)
    **
    **  as returned by cgeqrf.
    **
    **  arguments
    **  =========
    **
    **  m       (input) long int
    **          the number of rows of the matrix q. m >= 0.
    **
    **  n       (input) long int
    **          the number of columns of the matrix q. m >= n >= 0.
    **
    **  k       (input) long int
    **          the number of elementary reflectors whose product defines the
    **          matrix q. n >= k >= 0.
    **
    **  a       (input/output) DATA TYPE array, dimension (lda,n)
    **          on entry, the i-th column must contain the vector which
    **          defines the elementary reflector h(i), for i = 1,2,...,k, as
    **          returned by cgeqrf in the first k columns of its array
    **          argument a.
    **          on exit, the m-by-n matrix q.
    **
    **  lda     (input) long int
    **          the first dimension of the array a. lda >= max(1,m).
    **
    **  tau     (input) DATA TYPE array, dimension (k)
    **          tau(i) must contain the scalar factor of the elementary
    **          reflector h(i), as returned by cgeqrf.
    **
    **
    **
    **  info    (output) long int
    **          = 0:  successful exit
    **          < 0:  if info = -i, the i-th argument has an illegal value
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
   inline void ungqr(
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
   inline void ungqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<float>* a,
       const long int* lda,
       const std::complex<float>* tau,
       long int* info)
  */
  /*! fn
   inline void ungqr(
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
   inline void ungqr(
       const long int* m,
       const long int* n,
       const long int* k,
       std::complex<double>* a,
       const long int* lda,
       const std::complex<double>* tau,
       long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from cungqr.f)
  //    *  WORK    (workspace/output) std::complex<float> array, dimension (LWORK)
  //    *          On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
  //    *
  //    *  LWORK   (input) long int
  //    *          The dimension of the array WORK. LWORK >= max(1,N).
  //    *          For optimum performance LWORK >= N*NB, where NB is the
  //    *          optimal blocksize.
  //    *
  //    *          If LWORK = -1, then a workspace query is assumed; the routine
  //    *          only calculates the optimal size of the WORK array, returns
  //    *          this value as the first entry of the WORK array, and no error
  //    *          message related to LWORK is issued by XERBLA.
  //    *
  /////////////////////////////////////////////////////////////////////////

#define LPP_UNGQR(NAME, T, TBASE)\
inline void ungqr(\
    const long int* m,\
    const long int* n,\
    const long int* k,\
    T* a,\
    const long int* lda,\
    const T* tau,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(m, n, k, a, lda, tau, w.getw(), w.query(), info);\
    w.resizew(w.neededsize());\
    F77NAME( NAME )(m, n, k, a, lda, tau, w.getw(), &w.neededsize(), info);\
}\
inline void ungqr(\
    const long int* m,\
    const long int* n,\
    const long int* k,\
    T* a,\
    const long int* lda,\
    const T* tau,\
    long int* info)\
{\
   workspace<T> w;\
   ungqr(m, n, k, a, lda, tau, info, w);\
}\

    LPP_UNGQR(cungqr, std::complex<float>,  float)
    LPP_UNGQR(zungqr, std::complex<double>, double)

#undef LPP_UNGQR



}
#endif

// /////////////////////////////////////////////////////////////////////////////
// End of ungqr_itf.hh
// /////////////////////////////////////////////////////////////////////////////
