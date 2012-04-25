/*
** ~ libTardis ~
**
** Class :: Log
*/

#ifndef CLASS_LOG_HPP

#define CLASS_LOG_HPP
#include "../libTardis.hpp"
#include <fstream>

namespace tardis {

class Log
{
    public:

    std::stringstream ssOutput; // Logfile
    bool              bOutput;  // True if Logfile is set

    Log(const char *cLogFile = "");
    ~Log() {};
    void SetFile(const char*);
    void Output(std::stringstream*);

};

} // End namespace tardis

#endif
