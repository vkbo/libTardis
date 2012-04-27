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
  void F77NAME(cgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, COMPLEX* a, const long int* lda, float* s, const COMPLEX* u, const long int* ldu, const COMPLEX* vt, const long int* ldvt, COMPLEX* work, const long int* lwork, float* rwork, long int* info);
  void F77NAME(dgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, double* a, const long int* lda, double* s, const double* u, const long int* ldu, const double* vt, const long int* ldvt, double* work, const long int* lwork, long int* info);
  void F77NAME(sgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, float* a, const long int* lda, float* s, const float* u, const long int* ldu, const float* vt, const long int* ldvt, float* work, const long int* lwork, long int* info);
  void F77NAME(zgesvd)(const char* jobu, const char* jobvt, const long int* m, const long int* n, COMPLEX* a, const long int* lda, double* s, const COMPLEX* u, const long int* ldu, const COMPLEX* vt, const long int* ldvt, COMPLEX* work, const long int* lwork, double* rwork, long int* info);
  int ilaenv_(const int *i, const char *n, const char *opts, const int *n1, const int *n2, const int *n3, const int *n4, long int n_len, long int opts_len);
#undef COMPLEX

}
#endif
