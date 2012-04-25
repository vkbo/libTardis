/*
** ~ libTardis ~
**
** Class :: Log
*/

#include "../libTardis.hpp"

using namespace std;
using namespace tardis;

Log::Log(const char* cLogFile) {
    SetFile(cLogFile);
    return;
}

void Log::SetFile(const char* cLogFile) {
    bOutput = false;
    ssOutput << cLogFile;
    if(ssOutput.str().length() > 0) bOutput = true;
    return;
}

void Log::Output(stringstream *ssOut) {

    cout << ssOut->str();

    if(bOutput) {
        ofstream oFile;
        oFile.open(ssOutput.str().c_str(), ios::app);
        oFile << ssOut->str();
        oFile.close();
    }

    ssOut->str(string());

    return;
}
