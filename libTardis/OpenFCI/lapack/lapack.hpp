#ifndef LAPACK
#define LAPACK

/*
** These files have been modified to only include the content necessary for OpenFCI
*/

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

// Necessary content from lapack_C_itf.hh

#define F77NAME(x) x##_

typedef struct { float r, i;  } float_complex;
typedef struct { double r, i; } double_complex;

extern "C" {
    #define COMPLEX void
    void F77NAME(cgtsv)(const long int* n, const long int* nrhs, COMPLEX* dl, COMPLEX* d, COMPLEX* du, COMPLEX* b, const long int* ldb, long int* info);
    void F77NAME(dgtsv)(const long int* n, const long int* nrhs, double* dl, double* d, double* du, double* b, const long int* ldb, long int* info);
    void F77NAME(dsyev)(const char* jobz, const char* uplo, const long int* n, double* a, const long int* lda, double* w, double* work, const long int* lwork, long int* info);
    void F77NAME(sgtsv)(const long int* n, const long int* nrhs, float* dl, float* d, float* du, float* b, const long int* ldb, long int* info);
    void F77NAME(ssyev)(const char* jobz, const char* uplo, const long int* n, float* a, const long int* lda, float* w, float* work, const long int* lwork, long int* info);
    void F77NAME(zgtsv)(const long int* n, const long int* nrhs, COMPLEX* dl, COMPLEX* d, COMPLEX* du, COMPLEX* b, const long int* ldb, long int* info);
    void F77NAME(cgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, COMPLEX* a, const long int* lda, float* s, const COMPLEX* u, const long int* ldu, const COMPLEX* vt, const long int* ldvt, COMPLEX* work, const long int* lwork, float* rwork, long int* info);
    void F77NAME(dgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, double* a, const long int* lda, double* s, const double* u, const long int* ldu, const double* vt, const long int* ldvt, double* work, const long int* lwork, long int* info);
    void F77NAME(sgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, float* a, const long int* lda, float* s, const float* u, const long int* ldu, const float* vt, const long int* ldvt, float* work, const long int* lwork, long int* info);
    void F77NAME(zgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, COMPLEX* a, const long int* lda, double* s, const COMPLEX* u, const long int* ldu, const COMPLEX* vt, const long int* ldvt, COMPLEX* work, const long int* lwork, double* rwork, long int* info);
    int ilaenv_(const int *i, const char *n, const char *opts, const int *n1, const int *n2, const int *n3, const int *n4, long int n_len, long int opts_len);
    #undef COMPLEX
}

// Necessary content from lapack_cpp_itf.hh

#include <string>
#include <complex>
#include <vector>
#include <iostream>

namespace lpp {

inline int EnvBlockSize(int ispec, const std::string & fname, const std::string & opts, int n1 = -1, int n2 = -1, int n3 = -1, int n4 = -1) {
    int i = ispec;
    int N1 = n1;
    int N2 = n2;
    int N3 = n3;
    int N4 = n4;
    return F77NAME(ilaenv)(&i, fname.c_str(), opts.c_str(), &N1, &N2, &N3, &N4, fname.size(), opts.size());
}

/**
 *  This struct and its specialization are made to cast result returned by
 *  LAPACK with the wrong type
 */

template < class T > struct base{
    typedef T type_t;
    typedef T base_t;
    static long int Getval(const type_t & v) {
        return (long int)(v);
    }
};

template <class T > struct base <std::complex<T> > {
    typedef std::complex < T > type_t;
    typedef T base_t;
    static long int Getval(const type_t & v){
        return (long int)(v.real());
    }
};

/**
 *  This class allows to use easily LAPACK workspace features
 */

template < class T > class workspace{

    public :

    typedef typename base < T >::type_t   type_t;
    typedef typename base < T >::base_t   base_t;
    typedef std::vector < type_t > m_t;
    typedef std::vector < base_t > mb_t;
    typedef std::vector < long int > mi_t;

    /**
     * Sized constructor.
     * It allows to provide workspace memory from the beginning
     */

    workspace(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz = 0):
        w(std::max(wsiz, size_t(1))),
        rw(std::max(rwsiz, size_t(1))),
        iw(std::max(iwsiz, size_t(1))),
        bw(std::max(bwsiz, size_t(1))),
        mquery(-1)
    {}

    /**
     * Trivial constructor.
     * Only the main work area get a necessary small provision.
     * The other will be allocated on demand.
     */
    workspace():w(1), rw(1), iw(1), bw(1), mquery(-1){ }
    ~workspace(){}

    //! to resize the main work area
    void resizew (size_t size){ w.reserve(size); }

    //! to resize the real work area
    void resizerw(size_t size){rw.reserve(size); }

    //! to resize the integer work area
    void resizeiw(size_t size){iw.reserve(size); }

    //! to resize the logical work area
    void resizebw(size_t size){bw.reserve(size); }

    bool isok(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz)const{ //! is the workspace sufficiently large
        return (wsiz >= w.size()) && (rwsiz >= rw.size()) && (iwsiz >= iw.size()) && (bwsiz >= bw.size());
    }

    void realloc(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz = 0){
        if(wsiz >   w.size())  w.reserve(wsiz);
        if(rwsiz > rw.size()) rw.reserve(rwsiz);
        if(iwsiz > iw.size()) iw.reserve(iwsiz);
        if(bwsiz > bw.size()) bw.reserve(bwsiz);
    }

    type_t   * getw(){return &w[0]; }
    base_t   * getrw(){return &rw[0]; }
    long int * getiw(){return &iw[0]; }
    long int * getbw(){return &bw[0]; }

    const long int & neededsize(long int siz = 0){
        return (mldw =  siz ? siz : (base < type_t > ::Getval(w[0])));
    }

    const long int & neededisize(long int siz = 0){
        return mldiw = siz ? siz : iw[0];
    }

    const long int & neededrsize(long int siz = 0){
        return mldrw = siz ? siz : (long int)rw[0];
    }

    const long int & neededbsize(long int siz = 0){
        return mldbw = siz ? siz : bw[0];
    }

    const long int * query()const{return &mquery; }

    void showstate(char unit =  'B')const{
        size_t total = w.size()*sizeof(T)+rw.size()*sizeof(base_t)+iw.size()*sizeof(long int);
        size_t ext = w.capacity()*sizeof(T)+rw.capacity()*sizeof(base_t)+iw.capacity()*sizeof(long int)+bw.capacity()*sizeof(long int);
        std::cout << "workspace is using a total amount of: ";
        std::cout << total/factor(unit) << " " << name(unit) << std::endl;
        std::cout <<  w.size() << " in w,  " << std::endl;
        std::cout << rw.size() << " in rw, " << std::endl;
        std::cout << iw.size() << " in iw, " << std::endl;
        std::cout << bw.size() << " in bw, " << std::endl;
        std::cout << "Total capacity workspace up to now is  : ";
        std::cout << ext/factor(unit) << " " << name(unit) << std::endl;
        std::cout <<  w.capacity() << " in w,  " << std::endl;
        std::cout << rw.capacity() << " in rw, " << std::endl;
        std::cout << iw.capacity() << " in iw, " << std::endl;
        std::cout << bw.capacity() << " in bw, " << std::endl;
    }


    private :

    m_t w;
    mb_t rw;
    mi_t iw;
    mi_t bw;
    long int mldw, mldiw, mldrw, mldbw;
    const long int mquery;

    static inline size_t factor(char unit) {
        switch (unit) {
            case 'M' :
            case 'm' :
                return(1024*1024);
                break;
            case 'B' :
            case 'b' :
            case 'O' :
            case 'o' :
                return 1;
                break;
            case 'K' :
            case 'k' :
            default :
                return 1024;
        }
        return 1024;
    }

    static inline std::string name(char unit) {
        switch (unit) {
            case 'M' :
            case 'm' :
                return("Megabytes");
                break;
            case 'B' :
            case 'b' :
            case 'O' :
            case 'o' :
                return("Bytes");
                break;
            case 'K' :
            case 'k' :
            default :
                return("Kilobytes");
        }
        return("Kilobytes");
    }
};

inline char lower(const char c){
    return (c >= 'A' && c <= 'Z') ? c +('a'-'A') : c;
}

inline char upper(const char c){
    return (c >= 'a' && c <= 'z') ? c -('a'-'A') : c;
}

} // End namespace lpp

#include "gesvd_itf.hpp"
#include "gtsv_itf.hpp"
#include "syev_itf.hpp"

#endif
