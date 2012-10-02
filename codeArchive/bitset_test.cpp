//# Threads : 1

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../libTardis/libTardis.hpp"

using namespace std;
using namespace tardis;

int main(int argc, char* argv[]) {

    Slater sdTest;
    int    i, j=0;
    int    iOrb = SLATER_WORD;
    
    for(i=0; i<1e8; i++) {
        j++;
        if(j >= iOrb) j=0;
        sdTest.Create(j);
        sdTest.Annihilate(j);
    }

    return 0;
}
