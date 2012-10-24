###
###  Default Makfeile for libTardis
###

# Default Compiler Options
CC     = g++
DEBUG  = -g -Wall
LIBADD =

ifeq ($(NODE),Abel)
	LIBINTEL = -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm
	LIBARMA  = -L$(HOME)/usr/lib64 -larmadillo
	LIBFLAGS = $(LIBINTEL) $(LIBARMA) -lmpi $(LIBADD)
	CFLAGS   = $(DEBUG) -O2 -c -openmp -DMKL_LP64 -I$(MKLROOT)/include -I$(HOME)/usr/include
	LFLAGS   = $(DEBUG) -openmp
else
	LIBFLAGS = -llapack -lblas -larmadillo $(LIBADD)
	CFLAGS   = $(DEBUG) -O2 -c -fopenmp
	LFLAGS   = $(DEBUG) -fopenmp
endif


# Path Settings
LIBROOT     = libTardis
LIBSYS      = $(LIBROOT)/System
LIBCISD     = $(LIBROOT)/CISD
LIBPOT      = $(LIBROOT)/Potential
LIBPHYS     = $(LIBROOT)/Physics
LIBFCI      = $(LIBROOT)/OpenFCI
NODE        = Test
COMPILE     = tempCompile
OUTPUT      = $(COMPILE)/$(NODE)

# Executable
EXEC        = CISD-$(NODE)
MAIN        = main.cpp

# libTardis Objects
SYSOBJECTS  = classLog.o classSystem.o classSlater.o classBasis.o
CISDOBJECTS = classLanczos.o classDiag.o
POTOBJECTS  = classQDot2D.o
PHYSOBJECTS = classDensity.o

# OpenFCI Files
OFCIOBJECTS = modGaussTools.o classRadialPotential.o classQDotInteraction.o
OFCIINCLUDE = incLinalg.hpp incSimpleLinalg.hpp incSimpleMatrix.hpp incSimpleVector.hpp incSparse.hpp incTools.hpp lapack/lapack.hpp
OFCIHEADERS = $(addprefix $(LIBFCI)/,$(OFCIINCLUDE))

# Combine Objects
OBJECTS     = $(addprefix $(OUTPUT)/,$(SYSOBJECTS) $(CISDOBJECTS) $(POTOBJECTS) $(PHYSOBJECTS) $(OFCIOBJECTS))

##
## Compile
##

# Check if Output directory exists
$(shell [ -d "$(OUTPUT)" ] || mkdir -p $(OUTPUT))

# Executable and main.cpp

$(EXEC) : $(OUTPUT)/main.o $(OBJECTS)
	$(CC) $(LFLAGS) $(OUTPUT)/main.o $(OBJECTS) $(LIBFLAGS) -o $@

# Main File

$(OUTPUT)/main.o : $(MAIN) $(LIBROOT)/libTardis.hpp
	$(CC) $(CFLAGS) $(MAIN) -o $@

# System Classes

$(OUTPUT)/classLog.o : $(LIBSYS)/classLog.cpp $(LIBSYS)/classLog.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classLog.cpp -o $@

$(OUTPUT)/classSlater.o : $(LIBSYS)/classSlater.cpp $(LIBSYS)/classSlater.hpp $(LIBROOT)/slaterword.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classSlater.cpp -o $@

$(OUTPUT)/classSystem.o : $(LIBSYS)/classSystem.cpp $(LIBSYS)/classSystem.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classSystem.cpp -o $@

$(OUTPUT)/classBasis.o : $(LIBSYS)/classBasis.cpp $(LIBSYS)/classBasis.hpp $(LIBROOT)/config.hpp $(LIBROOT)/slaterword.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classBasis.cpp -o $@

# Potential Classes

$(OUTPUT)/classQDot2D.o : $(LIBPOT)/classQDot2D.cpp $(LIBPOT)/modQDot2D.cpp $(LIBPOT)/classQDot2D.hpp $(LIBPOT)/classPotential.hpp $(LIBROOT)/libTardis.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBPOT)/classQDot2D.cpp -o $@

# Solver Classes

$(OUTPUT)/classDiag.o : $(LIBCISD)/classDiag.cpp $(LIBCISD)/classDiag.hpp
	$(CC) $(CFLAGS) $(LIBCISD)/classDiag.cpp -o $@

$(OUTPUT)/classLanczos.o : $(LIBCISD)/classLanczos.cpp $(LIBCISD)/classLanczos.hpp $(LIBROOT)/config.hpp $(LIBROOT)/slaterword.hpp
	$(CC) $(CFLAGS) $(LIBCISD)/classLanczos.cpp -o $@

# Physics Classes

$(OUTPUT)/classDensity.o : $(LIBPHYS)/classDensity.cpp $(LIBPHYS)/classDensity.hpp
	$(CC) $(CFLAGS) $(LIBPHYS)/classDensity.cpp -o $@

# OpenFCI

$(OUTPUT)/modGaussTools.o : $(LIBFCI)/modGaussTools.cpp $(LIBFCI)/modGaussTools.hpp $(OFCIHEADERS)
	$(CC) $(CFLAGS) $(LIBFCI)/modGaussTools.cpp -o $@

$(OUTPUT)/classRadialPotential.o : $(LIBFCI)/classRadialPotential.cpp $(LIBFCI)/classRadialPotential.hpp $(OFCIHEADERS)
	$(CC) $(CFLAGS) $(LIBFCI)/classRadialPotential.cpp -o $@

$(OUTPUT)/classQDotInteraction.o : $(LIBFCI)/classQDotInteraction.cpp $(LIBFCI)/classQDotInteraction.hpp $(OFCIHEADERS)
	$(CC) $(CFLAGS) $(LIBFCI)/classQDotInteraction.cpp -o $@

# Make Clean

clean:
	rm $(OUTPUT)/* $(EXEC)
