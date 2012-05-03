#ifndef __PROJECT__LPP__FILE__SYEV_HH__INCLUDED
#define __PROJECT__LPP__FILE__SYEV_HH__INCLUDED

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
//  what        : syev_itf.hh C++ interface to LAPACK (s,d,c,z)syev
//  who         : contributed by Jean-Thierry LAPRESTE 
//  when        : Thu Dec 15 07:00:44 2005                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*! \file syev_itf.hh
    (excerpt adapted from xsyev.f file commentaries)
    
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
    **  xsyev computes all eigenvalues and, optionally, eigenvectors of a
    **  BASE DATA TYPE symmetric matrix a.
    **
    **  arguments
    **  =========
    **
    **  jobz    (input) char
    **          = 'n':  compute eigenvalues only;
    **          = 'v':  compute eigenvalues and eigenvectors.
    **
    **  uplo    (input) char
    **          = 'u':  upper triangle of a is stored;
    **          = 'l':  lower triangle of a is stored.
    **
    **  n       (input) long int
    **          the order of the matrix a.  n >= 0.
    **
    **  a       (input/output) BASE DATA TYPE array, dimension (lda, n)
    **          on entry, the symmetric matrix a.  if uplo = 'u', the
    **          leading n-by-n upper triangular part of a contains the
    **          upper triangular part of the matrix a.  if uplo = 'l',
    **          the leading n-by-n lower triangular part of a contains
    **          the lower triangular part of the matrix a.
    **          on exit, if jobz = 'v', then if info = 0, a contains the
    **          orthonormal eigenvectors of the matrix a.
    **          if jobz = 'n', then on exit the lower triangle (if uplo='l')
    **          or the upper triangle (if uplo='u') of a, including the
    **          diagonal, is destroyed.
    **
    **  lda     (input) long int
    **          the leading dimension of the array a.  lda >= max(1,n).
    **
    **  w       (output) BASE DATA TYPE array, dimension (n)
    **          if info = 0, the eigenvalues in ascending order.
    **
    **
    **
    **  info    (output) long int
    **          = 0:  successful exit
    **          < 0:  if info = -i, the i-th argument had an illegal value
    **          > 0:  if info = i, the algorithm failed to converge; i
    **                off-diagonal elements of an intermediate tridiagonal
    **                form did not converge to zero.
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
   inline void syev(
        const char* jobz,
        const char* uplo,
        const long int* n,
        float* a,
        const long int* lda,
        float* ws,
        long int* info,
        workspace<float> & w)
  */
  /*! fn
   inline void syev(
        const char* jobz,
        const char* uplo,
        const long int* n,
        float* a,
        const long int* lda,
        float* ws,
        long int* info)
  */
  /*! fn
   inline void syev(
        const char* jobz,
        const char* uplo,
        const long int* n,
        double* a,
        const long int* lda,
        double* ws,
        long int* info,
        workspace<double> & w)
  */
  /*! fn
   inline void syev(
        const char* jobz,
        const char* uplo,
        const long int* n,
        double* a,
        const long int* lda,
        double* ws,
        long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from ssyev.f)
  //    *  WORK    (workspace/output) float array, dimension (LWORK)
  //    *          On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
  //    *
  //    *  LWORK   (input) long int
  //    *          The length of the array WORK.  LWORK >= max(1,3*N-1).
  //    *          For optimal efficiency, LWORK >= (NB+2)*N,
  //    *          where NB is the blocksize for SSYTRD returned by ILAENV.
  //    *
  //    *          If LWORK = -1, then a workspace query is assumed; the routine
  //    *          only calculates the optimal size of the WORK array, returns
  //    *          this value as the first entry of the WORK array, and no error
  //    *          message related to LWORK is issued by XERBLA.
  //    *
  /////////////////////////////////////////////////////////////////////////

#define LPP_SYEV(NAME, T)\
inline void syev(\
    const char* jobz,\
    const char* uplo,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    T* ws,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(jobz, uplo, n, a, lda, ws, w.getw(), w.query(), info);\
    w.resizew(w.neededsize());\
    F77NAME( NAME )(jobz, uplo, n, a, lda, ws, w.getw(), &w.neededsize(), info);\
}\
inline void syev(\
    const char* jobz,\
    const char* uplo,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    T* ws,\
    long int* info)\
{\
   workspace<T> w;\
   syev(jobz, uplo, n, a, lda, ws, info, w);\
}\

    LPP_SYEV(ssyev, float)
    LPP_SYEV(dsyev, double)

#undef LPP_SYEV



}
#endif

// /////////////////////////////////////////////////////////////////////////////
// End of syev_itf.hh
// /////////////////////////////////////////////////////////////////////////////
