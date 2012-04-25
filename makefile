##
##  Default Makfeile for libTardis
##

# Default Compiler Options

CC          = g++
DEBUG       = -g
LIBADD      =
LIBFLAGS    = -llapack -lblas -larmadillo -fopenmp $(LIBADD)
CFLAGS      = -Wall -O2 -c $(DEBUG)
LFLAGS      = -Wall $(DEBUG)

# Path Settings

LIBROOT     = libTardis
LIBSYS      = $(LIBROOT)/System
LIBCISD     = $(LIBROOT)/CISD
LIBPOT      = $(LIBROOT)/Potential
NODE        = Test
COMPILE     = tempCompile
OUTPUT      = $(COMPILE)/$(NODE)

# Executable

EXEC        = CISD-$(NODE)
MAIN        = main.cpp

# Compile Variables

SYSOBJECTS  = classLog.o classSystem.o classSlater.o classBasis.o
CISDOBJECTS = classLanczos.o classDiag.o
POTOBJECTS  = classQDot2D.o
OBJECTS     = $(addprefix $(OUTPUT)/,$(SYSOBJECTS) $(CISDOBJECTS) $(POTOBJECTS))


# Check if Output directory exists
$(shell [ -d "$(OUTPUT)" ] || mkdir -p $(OUTPUT))

# Executable and main.cpp

$(EXEC) : $(OUTPUT)/main.o $(OBJECTS)
	$(CC) $(LFLAGS) $(OUTPUT)/main.o $(OBJECTS) $(LIBFLAGS) -o $@

$(OUTPUT)/main.o : $(MAIN) $(LIBROOT)/libTardis.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(MAIN) -o $@

# System Classes

$(OUTPUT)/classLog.o : $(LIBSYS)/classLog.cpp $(LIBSYS)/classLog.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classLog.cpp -o $@

$(OUTPUT)/classSystem.o : $(LIBSYS)/classSystem.cpp $(LIBSYS)/classSystem.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classSystem.cpp -o $@

$(OUTPUT)/classBasis.o : $(LIBSYS)/classBasis.cpp $(LIBSYS)/classBasis.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classBasis.cpp -o $@

$(OUTPUT)/classSlater.o : $(LIBSYS)/classSlater.cpp $(LIBSYS)/classSlater.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classSlater.cpp -o $@

# Potential Classes

$(OUTPUT)/classQDot2D.o : $(LIBPOT)/classQDot2D.cpp $(LIBPOT)/classQDot2D.hpp $(LIBPOT)/classPotential.hpp $(LIBROOT)/libTardis.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBPOT)/classQDot2D.cpp -o $@

# Solver Classes

$(OUTPUT)/classDiag.o : $(LIBCISD)/classDiag.cpp $(LIBCISD)/classDiag.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBCISD)/classDiag.cpp -o $@

$(OUTPUT)/classLanczos.o : $(LIBCISD)/classLanczos.cpp $(LIBCISD)/classLanczos.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBCISD)/classLanczos.cpp -o $@

# Make Clean

clean:
	rm $(OUTPUT)/* $(EXEC)
