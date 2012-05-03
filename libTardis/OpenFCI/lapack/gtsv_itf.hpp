#ifndef __PROJECT__LPP__FILE__GTSV_HH__INCLUDED
#define __PROJECT__LPP__FILE__GTSV_HH__INCLUDED

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
//  what        : gtsv_itf.hh C++ interface to LAPACK (c,d,c,z)gtsv
//  who         : contributed by Jean-Thierry LAPRESTE 
//  when        : Thu Dec 15 07:00:44 2005                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*! \file gtsv_itf.hh
    (excerpt adapted from xgtsv.f file commentaries)
    
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
    **  xgtsv  solves the equation
    **
    **     a*x = b,
    **
    **  where a is an n-by-n tridiagonal matrix, by gaussian elimination with
    **  partial pivoting.
    **
    **  note that the equation  a'*x = b  may be solved by interchanging the
    **  order of the arguments du and dl.
    **
    **  arguments
    **  =========
    **
    **  n       (input) long int
    **          the order of the matrix a.  n >= 0.
    **
    **  nrhs    (input) long int
    **          the number of right hand sides, i.e., the number of columns
    **          of the matrix b.  nrhs >= 0.
    **
    **  dl      (input/output) DATA TYPE array, dimension (n-1)
    **          on entry, dl must contain the (n-1) subdiagonal elements of
    **          a.
    **          on exit, dl is overwritten by the (n-2) elements of the
    **          second superdiagonal of the upper triangular matrix u from
    **          the lu factorization of a, in dl(1), ..., dl(n-2).
    **
    **  d       (input/output) DATA TYPE array, dimension (n)
    **          on entry, d must contain the diagonal elements of a.
    **          on exit, d is overwritten by the n diagonal elements of u.
    **
    **  du      (input/output) DATA TYPE array, dimension (n-1)
    **          on entry, du must contain the (n-1) superdiagonal elements
    **          of a.
    **          on exit, du is overwritten by the (n-1) elements of the first
    **          superdiagonal of u.
    **
    **  b       (input/output) DATA TYPE array, dimension (ldb,nrhs)
    **          on entry, the n-by-nrhs right hand side matrix b.
    **          on exit, if info = 0, the n-by-nrhs solution matrix x.
    **
    **  ldb     (input) long int
    **          the leading dimension of the array b.  ldb >= max(1,n).
    **
    **  info    (output) long int
    **          = 0:  successful exit
    **          < 0:  if info = -i, the i-th argument had an illegal value
    **          > 0:  if info = i, u(i,i) is exactly zero, and the solution
    **                has not been computed.  the factorization has not been
    **                completed unless i = n.
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
   inline void gtsv(
        const long int* n,
        const long int* nrhs,
        float* dl,
        float* d,
        float* du,
        float* b,
        const long int* ldb,
        long int* info,
        workspace<float> & w)
  */
  /*! fn
   inline void gtsv(
        const long int* n,
        const long int* nrhs,
        float* dl,
        float* d,
        float* du,
        float* b,
        const long int* ldb,
        long int* info)
  */
  /*! fn
   inline void gtsv(
        const long int* n,
        const long int* nrhs,
        double* dl,
        double* d,
        double* du,
        double* b,
        const long int* ldb,
        long int* info,
        workspace<double> & w)
  */
  /*! fn
   inline void gtsv(
        const long int* n,
        const long int* nrhs,
        double* dl,
        double* d,
        double* du,
        double* b,
        const long int* ldb,
        long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from sgtsv.f)
  /////////////////////////////////////////////////////////////////////////

#define LPP_GTSV(NAME, T)\
inline void gtsv(\
    const long int* n,\
    const long int* nrhs,\
    T* dl,\
    T* d,\
    T* du,\
    T* b,\
    const long int* ldb,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(n, nrhs, dl, d, du, b, ldb, info);\
}\
inline void gtsv(\
    const long int* n,\
    const long int* nrhs,\
    T* dl,\
    T* d,\
    T* du,\
    T* b,\
    const long int* ldb,\
    long int* info)\
{\
   workspace<T> w;\
   gtsv(n, nrhs, dl, d, du, b, ldb, info, w);\
}\

    LPP_GTSV(sgtsv, float)
    LPP_GTSV(dgtsv, double)

#undef LPP_GTSV


  // The following macro provides the 4 functions 
  /*! fn
   inline void gtsv(
       const long int* n,
       const long int* nrhs,
       std::complex<float>* dl,
       std::complex<float>* d,
       std::complex<float>* du,
       std::complex<float>* b,
       const long int* ldb,
       long int* info,
       workspace<complex<float> > & w)
  */
  /*! fn
   inline void gtsv(
       const long int* n,
       const long int* nrhs,
       std::complex<float>* dl,
       std::complex<float>* d,
       std::complex<float>* du,
       std::complex<float>* b,
       const long int* ldb,
       long int* info)
  */
  /*! fn
   inline void gtsv(
       const long int* n,
       const long int* nrhs,
       std::complex<double>* dl,
       std::complex<double>* d,
       std::complex<double>* du,
       std::complex<double>* b,
       const long int* ldb,
       long int* info,
       workspace<complex<double> > & w)
  */
  /*! fn
   inline void gtsv(
       const long int* n,
       const long int* nrhs,
       std::complex<double>* dl,
       std::complex<double>* d,
       std::complex<double>* du,
       std::complex<double>* b,
       const long int* ldb,
       long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from cgtsv.f)
  /////////////////////////////////////////////////////////////////////////

#define LPP_GTSV(NAME, T, TBASE)\
inline void gtsv(\
    const long int* n,\
    const long int* nrhs,\
    T* dl,\
    T* d,\
    T* du,\
    T* b,\
    const long int* ldb,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(n, nrhs, dl, d, du, b, ldb, info);\
}\
inline void gtsv(\
    const long int* n,\
    const long int* nrhs,\
    T* dl,\
    T* d,\
    T* du,\
    T* b,\
    const long int* ldb,\
    long int* info)\
{\
   workspace<T> w;\
   gtsv(n, nrhs, dl, d, du, b, ldb, info, w);\
}\

    LPP_GTSV(cgtsv, std::complex<float>,  float)
    LPP_GTSV(zgtsv, std::complex<double>, double)

#undef LPP_GTSV



}
#endif

// /////////////////////////////////////////////////////////////////////////////
// End of gtsv_itf.hh
// /////////////////////////////////////////////////////////////////////////////
