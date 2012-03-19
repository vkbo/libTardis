/*
** ~ libTardis ~
**
** Class :: Basis
*/

#ifndef CLASS_BASIS_HPP

#define CLASS_BASIS_HPP
#include "../libTardis.hpp"

namespace tardis {

class Basis
{
	public:

	// Constructor and Destructor
	Basis(tardis::System*);
	~Basis() {};

	// Public Functions
	int BuildBasis(int, int);
	int FindSlater(tardis::Slater, int, int);

	// Getters, Setters and Output
	int            GetSize();
	tardis::Slater GetSlater(int);
	void           Output();


	private:

	// Variables
	int iParticles;
	int iStates;

	// Objects
	tardis::System                 *oSystem;
	std::vector<tardis::Slater>     vBasis;
	std::vector<std::vector<int> >  vIndex;

	// Functions
	void fGenConfig(std::vector<int>&, int, int, int);
	void fGenIndex();

};

} // End namespace tardis

#endif
