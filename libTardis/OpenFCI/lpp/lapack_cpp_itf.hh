#ifndef __PROJECT__LPP__MON_JAN_16_10_29_29_2006__FILE__LAPACK_CPP_ITF_HH__INCLUDED
#define __PROJECT__LPP__MON_JAN_16_10_29_29_2006__FILE__LAPACK_CPP_ITF_HH__INCLUDED

#include <string>
namespace lpp
{
  inline int EnvBlockSize(int ispec,
                   const std::string & fname,
                   const std::string & opts,
                   int n1 = -1, 
                   int n2 = -1,
                   int n3 = -1,
                   int n4 = -1)
  {
    int i = ispec;
    int N1 = n1;
    int N2 = n2;
    int N3 = n3;
    int N4 = n4; 
    return F77NAME(ilaenv)(&i, fname.c_str(), opts.c_str(), &N1, &N2, &N3, &N4,
                           fname.size(), opts.size());
  }
}

#include "lapackworkspace.hh"

namespace lpp
{
  inline char lower(const char c){
    return (c >= 'A' && c <= 'Z') ? c +('a'-'A') : c; 
  }
  inline char upper(const char c){
    return (c >= 'a' && c <= 'z') ? c -('a'-'A') : c; 
  }

}
#include "lapack_cpp_itf/gesvd_itf.hh"
#include "lapack_cpp_itf/gtsv_itf.hh"
#include "lapack_cpp_itf/syev_itf.hh"

#endif    
