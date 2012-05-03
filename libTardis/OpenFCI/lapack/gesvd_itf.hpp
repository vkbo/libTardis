#ifndef __PROJECT__LPP__FILE__GESVD_HH__INCLUDED
#define __PROJECT__LPP__FILE__GESVD_HH__INCLUDED

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
//  what        : gesvd_itf.hh C++ interface to LAPACK (c,d,c,z)gesvd
//  who         : contributed by Jean-Thierry LAPRESTE 
//  when        : Thu Dec 15 07:00:44 2005                           
//  where       : tested with g++ 3.x,4.x                            
//  from        :                                                    
//  to          :                                                    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*! \file gesvd_itf.hh
    (excerpt adapted from xgesvd.f file commentaries)
    
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
    **  xgesvd computes the singular value decomposition (svd) of a DATA TYPE
    **  m-by-n matrix a, optionally computing the left and/or right singular
    **  vectors. the svd is written
    **
    **       a = u * sigma * conjugate-transpose(v)
    **
    **  where sigma is an m-by-n matrix which is zero except for its
    **  min(m,n) diagonal elements, u is an m-by-m unitary matrix, and
    **  v is an n-by-n unitary matrix.  the diagonal elements of sigma
    **  are the singular values of a; they are BASE DATA TYPE and non-negative, and
    **  are returned in descending order.  the first min(m,n) columns of
    **  u and v are the left and right singular vectors of a.
    **
    **  note that the routine returns v**h, not v.
    **
    **  arguments
    **  =========
    **
    **  jobu    (input) char
    **          specifies options for computing all or part of the matrix u:
    **          = 'a':  all m columns of u are returned in array u:
    **          = 's':  the first min(m,n) columns of u (the left singular
    **                  vectors) are returned in the array u;
    **          = 'o':  the first min(m,n) columns of u (the left singular
    **                  vectors) are overwritten on the array a;
    **          = 'n':  no columns of u (no left singular vectors) are
    **                  computed.
    **
    **  jobvt   (input) char
    **          specifies options for computing all or part of the matrix
    **          v**h:
    **          = 'a':  all n rows of v**h are returned in the array vt;
    **          = 's':  the first min(m,n) rows of v**h (the right singular
    **                  vectors) are returned in the array vt;
    **          = 'o':  the first min(m,n) rows of v**h (the right singular
    **                  vectors) are overwritten on the array a;
    **          = 'n':  no rows of v**h (no right singular vectors) are
    **                  computed.
    **
    **          jobvt and jobu cannot both be 'o'.
    **
    **  m       (input) long int
    **          the number of rows of the input matrix a.  m >= 0.
    **
    **  n       (input) long int
    **          the number of columns of the input matrix a.  n >= 0.
    **
    **  a       (input/output) DATA TYPE array, dimension (lda,n)
    **          on entry, the m-by-n matrix a.
    **          on exit,
    **          if jobu = 'o',  a is overwritten with the first min(m,n)
    **                          columns of u (the left singular vectors,
    **                          stored columnwise);
    **          if jobvt = 'o', a is overwritten with the first min(m,n)
    **                          rows of v**h (the right singular vectors,
    **                          stored rowwise);
    **          if jobu .ne. 'o' and jobvt .ne. 'o', the contents of a
    **                          are destroyed.
    **
    **  lda     (input) long int
    **          the leading dimension of the array a.  lda >= max(1,m).
    **
    **  s       (output) BASE DATA TYPE array, dimension (min(m,n))
    **          the singular values of a, sorted so that s(i) >= s(i+1).
    **
    **  u       (output) DATA TYPE array, dimension (ldu,ucol)
    **          (ldu,m) if jobu = 'a' or (ldu,min(m,n)) if jobu = 's'.
    **          if jobu = 'a', u contains the m-by-m unitary matrix u;
    **          if jobu = 's', u contains the first min(m,n) columns of u
    **          (the left singular vectors, stored columnwise);
    **          if jobu = 'n' or 'o', u is not referenced.
    **
    **  ldu     (input) long int
    **          the leading dimension of the array u.  ldu >= 1; if
    **          jobu = 's' or 'a', ldu >= m.
    **
    **  vt      (output) DATA TYPE array, dimension (ldvt,n)
    **          if jobvt = 'a', vt contains the n-by-n unitary matrix
    **          v**h;
    **          if jobvt = 's', vt contains the first min(m,n) rows of
    **          v**h (the right singular vectors, stored rowwise);
    **          if jobvt = 'n' or 'o', vt is not referenced.
    **
    **  ldvt    (input) long int
    **          the leading dimension of the array vt.  ldvt >= 1; if
    **          jobvt = 'a', ldvt >= n; if jobvt = 's', ldvt >= min(m,n).
    **
    **
    **
    **
    **  info    (output) long int
    **          = 0:  successful exit.
    **          < 0:  if info = -i, the i-th argument had an illegal value.
    **          > 0:  if cbdsqr did not converge, info specifies how many
    **                superdiagonals of an intermediate bidiagonal form b
    **                did not converge to zero. see the description of RWORK
    **                above for details.
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
   inline void gesvd(
        const char* jobu,
        const char* jobvt,
        const long int* m,
        const long int* n,
        float* a,
        const long int* lda,
        float* s,
        const float* u,
        const long int* ldu,
        const float* vt,
        const long int* ldvt,
        long int* info,
        workspace<float> & w)
  */
  /*! fn
   inline void gesvd(
        const char* jobu,
        const char* jobvt,
        const long int* m,
        const long int* n,
        float* a,
        const long int* lda,
        float* s,
        const float* u,
        const long int* ldu,
        const float* vt,
        const long int* ldvt,
        long int* info)
  */
  /*! fn
   inline void gesvd(
        const char* jobu,
        const char* jobvt,
        const long int* m,
        const long int* n,
        double* a,
        const long int* lda,
        double* s,
        const double* u,
        const long int* ldu,
        const double* vt,
        const long int* ldvt,
        long int* info,
        workspace<double> & w)
  */
  /*! fn
   inline void gesvd(
        const char* jobu,
        const char* jobvt,
        const long int* m,
        const long int* n,
        double* a,
        const long int* lda,
        double* s,
        const double* u,
        const long int* ldu,
        const double* vt,
        const long int* ldvt,
        long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from sgesvd.f)
  //    *  WORK    (workspace/output) float array, dimension (LWORK)
  //    *          On exit, if INFO = 0, WORK(1) returns the optimal LWORK;
  //    *          if INFO > 0, WORK(2:MIN(M,N)) contains the unconverged
  //    *          superdiagonal elements of an upper bidiagonal matrix B
  //    *          whose diagonal is in S (not necessarily sorted). B
  //    *          satisfies A = U * B * VT, so it has the same singular values
  //    *          as A, and singular vectors related by U and VT.
  //    *
  //    *  LWORK   (input) long int
  //    *          The dimension of the array WORK. LWORK >= 1.
  //    *          LWORK >= MAX(3*MIN(M,N)+MAX(M,N),5*MIN(M,N)).
  //    *          For good performance, LWORK should generally be larger.
  //    *
  //    *          If LWORK = -1, a workspace query is assumed.  The optimal
  //    *          size for the WORK array is calculated and stored in WORK(1),
  //    *          and no other work except argument checking is performed.
  //    *
  /////////////////////////////////////////////////////////////////////////

#define LPP_GESVD(NAME, T)\
inline void gesvd(\
    const char* jobu,\
    const char* jobvt,\
    const long int* m,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    T* s,\
    const T* u,\
    const long int* ldu,\
    const T* vt,\
    const long int* ldvt,\
    long int* info,\
    workspace<T> & w)\
{\
    F77NAME( NAME )(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, w.getw(), w.query(), info);\
    w.resizew(w.neededsize());\
    F77NAME( NAME )(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, w.getw(), &w.neededsize(), info);\
}\
inline void gesvd(\
    const char* jobu,\
    const char* jobvt,\
    const long int* m,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    T* s,\
    const T* u,\
    const long int* ldu,\
    const T* vt,\
    const long int* ldvt,\
    long int* info)\
{\
   workspace<T> w;\
   gesvd(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, info, w);\
}\

    LPP_GESVD(sgesvd, float)
    LPP_GESVD(dgesvd, double)

#undef LPP_GESVD


  // The following macro provides the 4 functions 
  /*! fn
   inline void gesvd(
       const char* jobu,
       const char* jobvt,
       const long int* m,
       const long int* n,
       std::complex<float>* a,
       const long int* lda,
       float* s,
       const std::complex<float>* u,
       const long int* ldu,
       const std::complex<float>* vt,
       const long int* ldvt,
       long int* info,
       workspace<complex<float> > & w)
  */
  /*! fn
   inline void gesvd(
       const char* jobu,
       const char* jobvt,
       const long int* m,
       const long int* n,
       std::complex<float>* a,
       const long int* lda,
       float* s,
       const std::complex<float>* u,
       const long int* ldu,
       const std::complex<float>* vt,
       const long int* ldvt,
       long int* info)
  */
  /*! fn
   inline void gesvd(
       const char* jobu,
       const char* jobvt,
       const long int* m,
       const long int* n,
       std::complex<double>* a,
       const long int* lda,
       double* s,
       const std::complex<double>* u,
       const long int* ldu,
       const std::complex<double>* vt,
       const long int* ldvt,
       long int* info,
       workspace<complex<double> > & w)
  */
  /*! fn
   inline void gesvd(
       const char* jobu,
       const char* jobvt,
       const long int* m,
       const long int* n,
       std::complex<double>* a,
       const long int* lda,
       double* s,
       const std::complex<double>* u,
       const long int* ldu,
       const std::complex<double>* vt,
       const long int* ldvt,
       long int* info)
  */


  /////////////////////////////////////////////////////////////////////////
  // (excerpt adapted from cgesvd.f)
  //    *  WORK    (workspace/output) std::complex<float> array, dimension (LWORK)
  //    *          On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
  //    *
  //    *  LWORK   (input) long int
  //    *          The dimension of the array WORK. LWORK >= 1.
  //    *          LWORK >=  2*MIN(M,N)+MAX(M,N).
  //    *          For good performance, LWORK should generally be larger.
  //    *
  //    *          If LWORK = -1, a workspace query is assumed.  The optimal
  //    *          size for the WORK array is calculated and stored in WORK(1),
  //    *          and no other work except argument checking is performed.
  //    *
  //    *  RWORK   (workspace) float array, dimension
  //    *                                  (5*min(M,N))
  //    *          On exit, if INFO > 0, RWORK(1:MIN(M,N)-1) contains the
  //    *          unconverged superdiagonal elements of an upper bidiagonal
  //    *          matrix B whose diagonal is in S (not necessarily sorted).
  //    *          B satisfies A = U * B * VT, so it has the same singular
  //    *          values as A, and singular vectors related by U and VT.
  //    *
  /////////////////////////////////////////////////////////////////////////

#define LPP_GESVD(NAME, T, TBASE)\
inline void gesvd(\
    const char* jobu,\
    const char* jobvt,\
    const long int* m,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    TBASE* s,\
    const T* u,\
    const long int* ldu,\
    const T* vt,\
    const long int* ldvt,\
    long int* info,\
    workspace<T> & w)\
{\
  w.resizerw(5*std::min(*m,*n));                                        \
  F77NAME( NAME )(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, w.getw(), w.query(), w.getrw(), info); \
  w.resizew(w.neededsize());                                            \
  F77NAME( NAME )(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, w.getw(), &w.neededsize(), w.getrw(), info); \
}\
inline void gesvd(\
    const char* jobu,\
    const char* jobvt,\
    const long int* m,\
    const long int* n,\
    T* a,\
    const long int* lda,\
    TBASE* s,\
    const T* u,\
    const long int* ldu,\
    const T* vt,\
    const long int* ldvt,\
    long int* info)\
{\
   workspace<T> w;\
   gesvd(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, info, w);\
}\

    LPP_GESVD(cgesvd, std::complex<float>,  float)
    LPP_GESVD(zgesvd, std::complex<double>, double)

#undef LPP_GESVD



}
#endif

// /////////////////////////////////////////////////////////////////////////////
// End of gesvd_itf.hh
// /////////////////////////////////////////////////////////////////////////////
