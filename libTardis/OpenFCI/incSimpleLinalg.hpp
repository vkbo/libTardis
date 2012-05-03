#ifndef _SIMPLE_LINALG_HPP_
#define _SIMPLE_LINALG_HPP_

//
// Copyright (c) 2008 Simen Kvaal
//
// This file is part of OpenFCI.
//
// OpenFCI is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OpenFCI is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OpenFCI. If not, see <http://www.gnu.org/licenses/>.
//


#include "incSimpleMatrix.hpp"
#include "incSimpleVector.hpp"
#include "lapack/lapack.hpp"

namespace simple_dense {

/// \brief Compute eigenvalues and/or eigenvectors of a matrix A, known to be symmetric.
/// It uses only upper triangular part for computations.
///
/// \param A      Matrix to diagonalize; output eigenvectors if compute_evec = true
/// \param lambda Output vector of eigenvalues
/// \param compute_evec  True if eigenvectors should be computed. They are stored in A if true.
/// \return 0 if success, -i of this wrapper has a bug, +i if algorithm failed to converge.
inline
long int symeig(simple_matrix<double>& A, simple_vector<double>& lambda, bool compute_evec) {

    std::string jobz = compute_evec ? "v" : "n";
    long int n = A.numRows();
    long int lda = A.getLd();
    long int info;

    assert(n == A.numCols());

    simple_matrix<double> temp(n,n);
    // Backup A if !compute_evec, since syev destroys it.
    if (!compute_evec) temp = A;

    lpp::syev(jobz.c_str(), "u", &n, &(A(1,1)),
    &lda, &(lambda(1)), &info);

    // restore A of !compute_evec.
    if (!compute_evec) A = temp;

    return info;
}

/// \brief Solve a system of tridiagonal linear equations Ax = b.
///
/// Calls the LAPACK function lpp:gtsv().
///
/// \param A Coefficient matrix. Unaffected.
/// \param b In: Right-hand-side. Out: Solution.
/// \return result of gtsv. == 0 if ok.
inline
long int solveTridiagonal(const simple_matrix<double>& A, simple_vector<double>& b) {

    long int n = A.numRows();
    long int nrhs = 1;
    long int ldb = b.length();
    long int info;

    simple_vector<double> dl(n), d(n), du(n); // diagonals

    for (index_t j = 1; j <= n; ++j) d(j) = A(j,j);

    for (index_t j = 1; j < n; ++j) {
        dl(j) = A(j+1, j);
        du(j) = A(j, j+1);
    }

    lpp::gtsv(&n, &nrhs, &dl(1), &d(1), &du(1), &b(1), &ldb, &info);

    return info;
}

/// \brief Add matrices: C = a*A + b*B.
/// \param A First matrix
/// \param a First coeff
/// \param B Second matrix
/// \param b Second coeff
/// \param C Destination
template<class T>
inline void addMatrices(simple_matrix<T>& C, const simple_matrix<T>& A, const T& a, const simple_matrix<T>& B, const T& b) {

    C = A;
    C *= a;

    for (index_t col = 1; col <= A.numCols(); ++col) {
        for (index_t row = 1; row <= A.numRows(); ++row) {
            C(row,col) += b*B(row, col);
        }
    }

    return;
}

/// \brief Multiply matrices: C = A*B.
/// \param A First matrix
/// \param B Second matrix
/// \param C Destination
/// \param transB  True if B is to be transposed.
template<class T>
inline void multiplyMatrices(simple_matrix<T>& C, const simple_matrix<T>& A, const simple_matrix<T>& B, bool transB = false) {

    if (!transB) {
        assert(A.numCols() == B.numRows());
        C.resize(A.numRows(), B.numCols());
        C = 0;

        for (index_t col = 1; col <= C.numCols(); ++col) {
            for (index_t row = 1; row <= C.numRows(); ++row) {
                for (index_t k = 1; k <= A.numCols(); ++k) {
                    C(row,col) += A(row,k)*B(k,col);
                }
            }
        }
    } else {
        assert(A.numCols() == B.numCols());
        C.resize(A.numRows(), B.numRows());
        C = 0;

        for (index_t col = 1; col <= C.numCols(); ++col) {
            for (index_t row = 1; row <= C.numRows(); ++row) {
                for (index_t k = 1; k <= A.numCols(); ++k) {
                    C(row,col) += A(row,k)*B(col,k);
                }
            }
        }
    }

    return;
}

} // namespace simple_dense

#endif // _SIMPLE_LINALG_HPP_
