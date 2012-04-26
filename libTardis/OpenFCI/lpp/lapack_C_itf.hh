#ifndef __PROJECT__NT2__FILE__LAPACK_C_ITF_HH__INCLUDED
#define __PROJECT__NT2__FILE__LAPACK_C_ITF_HH__INCLUDED

#define F77NAME(x) x##_

typedef struct { float r, i;  } float_complex;
typedef struct { double r, i; } double_complex;

extern "C"
{
#define COMPLEX void
  void F77NAME(cgtsv)(const long int* n, const long int* nrhs, COMPLEX* dl, COMPLEX* d, COMPLEX* du, COMPLEX* b, const long int* ldb, long int* info);
  void F77NAME(dgtsv)(const long int* n, const long int* nrhs, double* dl, double* d, double* du, double* b, const long int* ldb, long int* info);
  void F77NAME(dsyev)(const char* jobz, const char* uplo, const long int* n, double* a, const long int* lda, double* w, double* work, const long int* lwork, long int* info);
  void F77NAME(sgtsv)(const long int* n, const long int* nrhs, float* dl, float* d, float* du, float* b, const long int* ldb, long int* info);
  void F77NAME(ssyev)(const char* jobz, const char* uplo, const long int* n, float* a, const long int* lda, float* w, float* work, const long int* lwork, long int* info);
  void F77NAME(zgtsv)(const long int* n, const long int* nrhs, COMPLEX* dl, COMPLEX* d, COMPLEX* du, COMPLEX* b, const long int* ldb, long int* info);
  int ilaenv_(const int *i, const char *n, const char *opts, const int *n1, const int *n2, const int *n3, const int *n4, long int n_len, long int opts_len);
#undef COMPLEX
  
}
#endif
