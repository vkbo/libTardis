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

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>


#include "ConfigFile.h"

#include "QdotInteraction.hpp"

#include "tools.hpp"

using namespace std;
using namespace quantumdot;


/**
 * \file tabulate.cc
 * \date 10-7-2008
 * \author Simen Kvaal
 *
 * \brief Program for tabulation of interaction matrix elements.
 *
 * This small program is provided mostly as an example of how one may use
 * the OpenFCI library. The matrix elements tabulated are the <a b | U | c d>
 * matrix elements, and these could be input for other methods, e.g., coupled cluster
 * methods. Indeed, such a method could be implemented using parts of the OpenFCI library.
 * 
 * The program reads a configuration file (see ConfigFile) on the following form:
 * \code
 * # Tabulate Coulomb matrix elements for SP energies 2*n + |m| <= R.
 * R = 20
 * lambda = 1.00
 * use_veff = true
 * \endcode
 *
 *
 **/




/// \brief Tabulate Coulomb matrix elements for R+1 shells for CC calculations.
/// 
/// Output is written to std::cout, one line at a time,
/// each line has one matrix element. The line has the format:
/// \verbatim a b c d element  \endverbatim
/// All values 2n[a]+|m[a]| <= R are processed, but only nonzeroes are written.
///
/// \param lambda  The interaction strength
/// \param R   The value for R
/// \param use_veff   Set to true if effective interaction is to be tabulated instead of bare interaction.
void tabulateCoulomb(double lambda, int R, bool use_veff, bool use_energy_cut = false);


void tabulateCoulomb(double lambda, int R, bool use_veff, bool use_energy_cut, double w)
{
  ofstream Ofile;
  char *file = new char[100];
  if(use_veff){
    sprintf(file, "tp_w=%g_R=%d_eff",w,R+1);
  }
  else{
    sprintf(file, "tp_w=%g_R=%d",w,R+1);
  }
  Ofile.open(file, ios::out|ios::binary);
  
  int shellnumb=R+1;
  int num_spfunc,M, Mvalue, MSvalue, Mmax, alphadim,alpha,bsize;
  double MS;
  int *n,*m;
  double *ms;
  
  num_spfunc= shellnumb*(shellnumb+1);
  Mmax=(shellnumb-1)*2;
  alphadim=2*Mmax*3+3;
  n=new int[num_spfunc];
  m=new int[num_spfunc];
  ms=new double[num_spfunc];
  //new filling-algo corresponding to simens production
  int org=0;
  for(int i=1; i<=shellnumb; i++){
    for(int j=(-i+1); j<=0; j+=2){
      if(j!=0){
	m[org] = m[org+1] = j;
	m[org+2] = m[org+3] = -j;
	n[org] = n[org+1] = n[org+2] = n[org+3] =int((i-abs(m[org])-1)*0.5);
	ms[org]= ms[org+2] = -0.5;
	ms[org+1]= ms[org+3] = 0.5;
	org+=4;
      }
      else{
	m[org] = m[org+1] = j;
	n[org] = n[org+1] = int((i-abs(m[org])-1)*0.5);
	ms[org]= -0.5;
	ms[org+1]= 0.5;
	org+=2;
      }
    }
  }

  
  //vector for counting basis size for each alpha(M,MS) set
  int *basiscount;           
  basiscount = new int[alphadim];
  //finding maxbsize and filling basiscount
  alpha=0;
  for(int l=-Mmax; l<=Mmax; l++){
    Mvalue=l;
    for(MSvalue=-1; MSvalue<=1; MSvalue++){
      bsize=0;
      for (int i=0; i<num_spfunc-1;i++){
	for(int j=i+1; j<num_spfunc;j++){
	  M = m[i]+m[j];
	  MS = ms[i]+ms[j];
	  if(M==Mvalue && MS==MSvalue){
	    bsize += 1;
	  }
	}
      }
      basiscount[alpha]=bsize*2;
      alpha+=1;
    }
  }

  //allocating config, matrix(alpha,basis) for saving each 2particle basis-set
  int **config;
  config=new int*[alphadim];
  for(int i=0; i<alphadim; i++)
    config[i]=new int[basiscount[i]];
  //loop over M and MS values determining the 2particle basis
  alpha=0;
  for(int l=-Mmax; l<=Mmax; l++){
    Mvalue=l;
    for(MSvalue=-1; MSvalue<=1; MSvalue++){
      bsize=0;
      for (int i=0; i<num_spfunc-1;i++){
	for(int j=i+1; j<num_spfunc;j++){
	  M = m[i]+m[j];
	  MS = ms[i]+ms[j];
	  if(M==Mvalue && MS==MSvalue){
	    config[alpha][bsize]=i;
	    config[alpha][bsize+1]=j;
	    bsize += 2;
	  }
	}
      }
      alpha+=1;
    }
  }


  QdotInteraction inter;
  cerr << "Building COM to LAB transformation ..." << endl;
  if (!use_energy_cut)
    inter.setR(2*R);
  else 
    inter.setR(R);
  inter.setLambda(lambda);
  cerr << "Computing COM blocks of interaction ..." << endl;
  if (use_veff)
    inter.buildEffectiveInteractionComBlocks(1);
  else
    inter.buildInteractionComBlocks();

  // Tabulate values!

  // Build quantum numbers-to-orbital mapping.
  cerr << "Building quantum-numbers-to-orbital-number mapping." << endl;
  std::vector<int> m_arr, s_arr, n_arr, R_arr;
  int index = 0;
  for (int R1 = 0; R1 <= R; ++R1)
    {
      cerr << "-- R = " << R1 << " -------- " <<  endl;
      for (int absm1 = R1; absm1 >= 0; absm1 -= 2)
	{
	  int n1 = (R1 - absm1)/2;
	  int sign_min1 = absm1 > 0 ? -1 : 1;
	  for (int sign1 = sign_min1; sign1 <= 1; sign1 += 2)
	    {
	      for (int sigma1 = -1; sigma1 <= 1; sigma1 += 2)
		{
		  
		  cerr << "|" << index << "> : n = " << n1 << ", m = " 
		       << sign1*absm1 << ", sigma = " << sigma1 << endl; 

		  m_arr.push_back(sign1*absm1);
		  s_arr.push_back(sigma1);
		  n_arr.push_back(n1);
		  R_arr.push_back(R+1);
		  

		  index++;


		}
	    }
	}
    }

 //  ofstream Ofile2;
//   char *file2 = new char[100];
//   sprintf(file2, "testertconfigsimen");
//   Ofile2.open(file2, ios::out);

  const size_t n_orbitals = index;
  const int field_width  = 4;
  size_t nnz = 0;
  int a,b,c,d;
  short int a1,b1,c1,d1;
  for (int alpha=0; alpha<alphadim; alpha++)
    for (int i=0; i<basiscount[alpha]; i+=2)
      for (int j=0; j<basiscount[alpha]; j+=2)
	{
	  a=config[alpha][i];
	  b=config[alpha][i+1];
	  c=config[alpha][j];
	  d=config[alpha][j+1];
	  const int epsilon_a = 2*n_arr[a] + abs(m_arr[a]) + 1;
	  const int epsilon_b = 2*n_arr[b] + abs(m_arr[b]) + 1;
	  const int epsilon_c = 2*n_arr[c] + abs(m_arr[c]) + 1;
	  const int epsilon_d = 2*n_arr[d] + abs(m_arr[d]) + 1;
	  
	  
	  if ( !use_energy_cut || (use_energy_cut && (epsilon_a+epsilon_b <= R + 2) && (epsilon_c+epsilon_d <= R + 2)))
	    {
	      double elm1 = inter.singleElement(2*n_arr[a]+abs(m_arr[a]), m_arr[a],
						2*n_arr[b]+abs(m_arr[b]), m_arr[b],
						2*n_arr[c]+abs(m_arr[c]), m_arr[c],
						2*n_arr[d]+abs(m_arr[d]), m_arr[d]);
	      
	      double elm2 = inter.singleElement(2*n_arr[a]+abs(m_arr[a]), m_arr[a],
						2*n_arr[b]+abs(m_arr[b]), m_arr[b],
						2*n_arr[d]+abs(m_arr[d]), m_arr[d],
						2*n_arr[c]+abs(m_arr[c]), m_arr[c]);
	      
	      double elm = ((s_arr[a] == s_arr[c]) && (s_arr[b] == s_arr[d]))*elm1 
		- ((s_arr[a] == s_arr[d]) && (s_arr[b] == s_arr[c]))*elm2;
	      
	      a1=(short int)a; b1=(short int)b; c1=(short int)c; d1=(short int)d;
	      if (fabs(elm) > 1e-15)
		{
		  Ofile.write((char*)&a1,sizeof(short int));
		  Ofile.write((char*)&b1,sizeof(short int));
		  Ofile.write((char*)&c1,sizeof(short int));
		  Ofile.write((char*)&d1,sizeof(short int));
		  Ofile.write((char*)&elm,sizeof(double));
		  //cout <<  a << " " << b << " " << c << " " << d << " " << format(elm) << endl;
		  //Ofile2<<a << " " << b << " " << c << " " << d <<endl;
		  //printf("%d %d %d %d %0.14f \n",a, b, c, d,elm);
		  nnz++;
		}
	      
	    }
	  
	}
  
  
  cerr << "Total number of matrix elements written: " << nnz << endl;
  
//   for (N1 = 0; N1 <=R; ++N1)
//     for (m1 = -N1; m1 <= N1; m1 += 2)
//       for (N2 = 0; N2 <=R-N1; ++N2)
// 	for (m2 = -N2; m2 <= N2; m2 += 2)

// 	  for (N3 = N1; N3 <=R; ++N3)
// 	    for (m3 = (N3==N1 ? m1 : -N3); m3 <= N3; m3 += 2)
// 	      for (N4 = N2; N4 <=R-N3; ++N4)
// 		for (m4 = (N4==N2 ? m2 : -N4); m4 <= N4; m4 += 2)
// 		{
// 		  n1 = (N1 - abs(m1)) / 2;
// 		  n2 = (N2 - abs(m2)) / 2;
// 		  n3 = (N3 - abs(m3)) / 2;
// 		  n4 = (N4 - abs(m4)) / 2;
// 		  value = inter.singleElement(N1,m1, N2,m2, N3,m3, N4,m4);
// 		  if (value != 0.0)
// 		  {
// 		    cout << setw(w) << n1 << " " << setw(w) << m1 << " " << setw(w) << n2 << " " << setw(w) << m2 << " " 
// 			 << setw(w) << n3 << " " << setw(w) << m3 << " " << setw(w) << n4 << " " << setw(w) << m4 << " " 
// 			 << "    " << format(value) << endl;
// 		  }
// 		}

  Ofile.close();
}





int main(int argc, char **argv)
{

  print_copyright(cerr);

  string configname = "tabulate.ini";
  double w=atof(argv[1]);

  try
  {
    ConfigFile config(configname);
    double lambda = config.read<double>("lambda", 1.0);
    int R = config.read<int>("R", 10);
    bool use_veff = config.read<bool>("use_veff", false);
    bool use_energy_cut = config.read<bool>("use_energy_cut", false);

    tabulateCoulomb(lambda, R, use_veff, use_energy_cut,w);


  }
  catch( ConfigFile::file_not_found& e ) {
    cerr << "The configuration '" << e.filename << "' was not found. Aborting.";
    cerr << endl << endl;
    return 1;
  }


}
