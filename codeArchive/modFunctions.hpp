/*
** ~ libTardis ~
**
** Common Functions
*/

#ifndef MOD_FUNCTIONS_HPP

#define MOD_FUNCTIONS_HPP
#include "libTardis.hpp"

/*
** Runtime Variables
*/
#define FAC_LIMIT 300

/*
** Macro definitions
*/

// For integer arguments only:
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
#define MIN(a,b)  (((a) < (b)) ? (a) : (b))
#define PARITY(a) ((a) % 2) 
#define PHASE(a)  (1 - 2 * (abs(a) % 2))
#define MOD(a,b)  ((a) - ((a)/(b)) * b)
#define SIGN(a,b) ((b)<0 ? -fabs(a) : fabs(a))

namespace tardis {

double fFacRatio(int, int);
double fClebschGordan(int, int, int, int, int);
double fRan(long*);

} // End namespace tardis

#endif
