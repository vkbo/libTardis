/*
** ~ libTardis ~
**
** Class :: Slater
*/

#ifndef CLASS_SLATER_HPP

#define CLASS_SLATER_HPP
#include "../libTardis.hpp"
#include "../confSlater.hpp"
#include <bitset>
#include <vector>

#ifndef SLATER_WORD
	#define SLATER_WORD 64
#endif

namespace tardis {

class Slater
{
	public:
	std::bitset<SLATER_WORD> Word;
	Slater() {};
	~Slater() {};

	int  Create(int);
	int  Annihilate(int);
	bool Compare(Slater);
	int  Count();
	int  CountOdd();
	int  CountEven();
	void Output(int);
};

} // End namespace tardis

#endif
