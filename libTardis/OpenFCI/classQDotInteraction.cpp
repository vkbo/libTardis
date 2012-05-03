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

#include "classQDotInteraction.hpp"
#include "modGaussTools.hpp"
#include "incTools.hpp"

/*
 * Implementation of matrix elements for the quantum dot, plus various helper functions.
 *
 */

namespace quantumdot {

using namespace gauss;
using namespace std;

void QdotInteraction::buildTalmiBlocks() {

    cout.precision(16);

    for (int N = 0; N<=2*R; ++N) {
        dense_matrix TN;
        computeTalmiMatrix(TN, N);
        T.push_back(TN);
    }

    return;
}


void QdotInteraction::buildInteractionComBlocks() {

    // Also set up the C_index vector. It is trivial in the standard
    // bare interaction case.

    C_index.resize(2*R+1);
    fill(C_index.begin(), C_index.end(), 0);

    // Build the Coulomb matrices.
    for (int m = 0; m <= 2*R; ++m) {
        dense_matrix Cm;
        potential.computeMatrix(Cm, (2*R - m)/2, m);
        Cm *= lambda;
        C.push_back(Cm);
    }

    return;
}

void QdotInteraction::buildEffectiveInteractionComBlocks(int g) {

    // Also set up the C_index vector.
    C_index.resize(g*R + 1);
    fill(C_index.begin(), C_index.end(), 0);

    // Build the effective Coulomb matrices.
    for (int delta_R = 0; delta_R <= g*R; ++delta_R) {
        int the_R = g*R - delta_R;

        // Compute index into vector of C-matrices for the
        // current COM quantum number delta_R.

        C_index[delta_R] = C.size();

        for (int m = 0; m <= the_R; ++m) {
            // Compute matrix
            dense_matrix Cm;
            potential.setLambda(lambda);
            potential.computeEffectiveMatrix(Cm, (the_R - m)/2, m);
            potential.setLambda(1.0);
            C.push_back(Cm);
        }
    }

    return;
}

double QdotInteraction::singleElement(int N1, int m1, int N2, int m2, int N1pr, int m1pr, int N2pr, int m2pr) {

    // conserve angular momentum ...
    if (m1+m2 != m1pr + m2pr) return 0;

    if (precomputed) {

        if (m1+m2<0) {
            m1 = -m1;
            m2 = -m2;
            m1pr = -m1pr;
            m2pr = -m2pr;
        }
        int M = m1 + m2;
        int row = state_map[M][n_orbitals*orbitalMap2(N1,m1) + orbitalMap2(N2,m2)];
        int col = state_map[M][n_orbitals*orbitalMap2(N1pr,m1pr) + orbitalMap2(N2pr,m2pr)];
        assert(row>0);
        assert(col>0);

        return U[M][row-1][col-1];

    } else {

        const int np1 = (N1 + m1)/2;
        const int nm1 = (N1 - m1)/2;
        const int np2 = (N2 + m2)/2;
        const int nm2 = (N2 - m2)/2;
        const int np1pr = (N1pr + m1pr)/2;
        const int nm1pr = (N1pr - m1pr)/2;
        const int np2pr = (N2pr + m2pr)/2;
        const int nm2pr = (N2pr - m2pr)/2;
        const int Np = np1 + np2;
        const int Nm = nm1 + nm2;
        const int Nppr = np1pr + np2pr;
        const int Nmpr = nm1pr + nm2pr;

        assert(T[Np].numRows() == Np+1);
        assert(T[Nm].numRows() == Nm+1);
        assert(T[Nppr].numRows() == Nppr+1);
        assert(T[Nmpr].numRows() == Nmpr+1);

        int mup, mum;

        double sum = 0;
        for (mup = 0; mup<= Np; ++mup) {
            const double f1 = T[Np](mup+1,np2+1);
            const int muppr = Nppr - Np + mup;
            if (muppr >= 0) {
                const double f2 = T[Nppr](muppr+1, np2pr+1);
                for (mum = 0; mum<= Nm; ++mum) {
                    const int n = min(mum,mup);
                    const int m = mup-mum;
                    const double g1 = T[Nm](mum+1,nm2+1);
                    const int mumpr = Nmpr - Nm + mum;

                    const int delta_R = Np + Nm - (mup + mum);
                    const int ind = C_index[delta_R]; // index into C[] array.

                    if (mumpr >= 0) {
                        const double g2 = T[Nmpr](mumpr+1, nm2pr+1);
                        const int s = Nppr - Np;
                        if (s >= -n) {
                            sum += f1*f2*g1*g2*C[ind + abs(m)](n+1,n+s+1);
                        }
                    }
                }
            }
        }

        return sum;
    }

    return 0.0;
}

void QdotInteraction::precomputeLabFrameMatrix() {

    int M;
    int Mmax = 2*R;
    int kount;

    // Vector holding all orbital pairs needed.
    vector<vector<orb_pair> > lab_orbs;
    vector<int> U_dim;

    // Compute SP-mappings.
    n_orbitals = orbitalMap2(R, R) + 1;

    // Allocate vector-vectors and maps for other mappings.
    state_map.resize(Mmax+1);
    lab_orbs.resize(Mmax+1);
    U_dim.resize(Mmax+1);

    // Construct mapping index mappings.
    for (M = 0; M<=Mmax; ++M) {
        kount = 0; // counts the different ni, mi combinations.
        // loop over all possible cmobinations of m1 and m2.
        for (int m1 = -R; m1<=R; ++m1) {
            int m2 = M - m1;

            if (abs(m2) <= R) {

                // now (m1,m2) is a possible combination of
                // angular momentums such that m1+m2 = M, and
                // |mi| <= R.

                for (int N1 = abs(m1); N1 <= R; N1+=2) {
                    for (int N2 = abs(m2); N2 <= R; N2+=2) {
                        // we now have a legal combination of N1 and N2,
                        // together with a legal combination for m1 and m2,
                        // at the given M.

                        // add to the mapping index -> (n1,m1,n2,m2).
                        orb_pair temp;
                        temp.N1 = N1;
                        temp.N2 = N2;
                        temp.m1 = m1;
                        temp.m2 = m2;
                        lab_orbs[M].push_back(temp);

                        // add to the inverse mapping.
                        assert(orbitalMap2(N1,m1) < n_orbitals);
                        assert(orbitalMap2(N2,m2) < n_orbitals);
                        state_map[M][n_orbitals * orbitalMap2(N1,m1) + orbitalMap2(N2,m2)] = kount + 1;

                        ++kount;

                    }
                }
            }
        }

        // store the dimension of the direct product space.
        U_dim[M] = kount;
    } // end of M loop

    // Allocate Mmax + 1 sparse matrices.
    U.resize(Mmax+1);

    // Loop though values for M = m1 + m2 = m3 + m4.
    for (M=0; M<=Mmax; ++M) {

        // Build individual block U[M].
        U[M].clear();

        cerr << "Building interaction matrix for m1 + m2 = "<<M<<" ... " << endl;
        int row, col;

        cerr << "matrix dim = " << U_dim[M] << endl;
        for (row = 0; row < U_dim[M]; ++row) {
            orb_pair& ro = lab_orbs[M][row];
            assert(orbitalMap2(ro.N1,ro.m1) < n_orbitals);
            assert(orbitalMap2(ro.N2,ro.m2) < n_orbitals);

            for (col = 0; col < U_dim[M]; ++col) {
                orb_pair& co = lab_orbs[M][col];
                assert(ro.m1+ro.m2 == co.m1 + co.m2);
                assert(orbitalMap2(co.N1,co.m1) < n_orbitals);
                assert(orbitalMap2(co.N2,co.m2) < n_orbitals);

                U[M][row][col] = singleElement(ro.N1, ro.m1, ro.N2, ro.m2, co.N1, co.m1, co.N2, co.m2);
            } // column loop
        } // row loop
    } // M loop

    // Indicate that we have a precomputed interaction.
    precomputed = true;

    return;
}

void computeTalmiMatrix(dense_matrix& TN, int N) {

    // Gauss-Hermite points and weights.
    dense_vector x;
    dense_vector w;

    // Resize matrix.
    TN.resize(N+1,N+1);

    // Compute Gauss-Hermite points needed.
    int gorder = N+1;
    int gorder2 = gorder*gorder;
    computeGaussHermite(x,w,gorder);

    // Create a grid from these.
    dense_vector x1(gorder2), x2(gorder2);
    dense_vector xi1(gorder2), xi2(gorder2);
    dense_vector w1(gorder2);
    for (int k=1; k<=gorder; ++k) {
        for (int l=1; l<=gorder; ++l) {
            x1(gorder*(k-1) + l) = x(k);
            x2(gorder*(k-1) + l) = x(l);
            xi1(gorder*(k-1) + l) = sqrt(.5)*(x(k) + x(l));
            xi2(gorder*(k-1) + l) = sqrt(.5)*(x(k) - x(l));
            w1(gorder*(k-1) + l) = w(k)*w(l);
        }
    }

    // Compute ALL the Hermite polys needed for this N.
    dense_matrix P1,P2,P3,P4;
    computeHermitePolys(x1, P1, N);
    computeHermitePolys(x2, P2, N);
    computeHermitePolys(xi1, P3, N);
    computeHermitePolys(xi2, P4, N);

    // Compute matrix elements
    for (int mu = 0; mu<=N; ++mu) {
        for (int nu = 0; nu<=N; ++nu) {
            double sum = 0;
            for (int j = 1; j<=gorder2; ++j) {
                sum += w1(j)*P1(j,N-mu+1)*P2(j,mu+1)*P3(j,N-nu+1)*P4(j,nu+1);
            }
            TN(mu+1,nu+1) = sum;
        }
    }

    return;
}

} // namespace quantumdot
