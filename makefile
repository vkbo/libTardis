##
##  Default Makfeile for libTardis
##

# Default Compiler Options

CC          = g++
DEBUG       = -g -Wall
LIBADD      =
LIBFLAGS    = -llapack -lblas -larmadillo $(LIBADD)
CFLAGS      = $(DEBUG) -O2 -c -fopenmp
LFLAGS      = $(DEBUG) -fopenmp

# Path Settings

LIBROOT     = libTardis
LIBSYS      = $(LIBROOT)/System
LIBCISD     = $(LIBROOT)/CISD
LIBPOT      = $(LIBROOT)/Potential
LIBFCI      = $(LIBROOT)/OpenFCI
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
OFCIOBJECTS = modGaussTools.o classRadialPotential.o classQDotInteraction.o
OBJECTS     = $(addprefix $(OUTPUT)/,$(SYSOBJECTS) $(CISDOBJECTS) $(POTOBJECTS) $(OFCIOBJECTS))


# Check if Output directory exists
$(shell [ -d "$(OUTPUT)" ] || mkdir -p $(OUTPUT))

# Executable and main.cpp

$(EXEC) : $(OUTPUT)/main.o $(OBJECTS)
	$(CC) $(LFLAGS) $(OUTPUT)/main.o $(OBJECTS) $(LIBFLAGS) -o $@

$(OUTPUT)/main.o : $(MAIN) $(LIBROOT)/libTardis.hpp
	$(CC) $(CFLAGS) $(MAIN) -o $@

# System Classes

$(OUTPUT)/classLog.o : $(LIBSYS)/classLog.cpp $(LIBSYS)/classLog.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classLog.cpp -o $@

$(OUTPUT)/classSystem.o : $(LIBSYS)/classSystem.cpp $(LIBSYS)/classSystem.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classSystem.cpp -o $@

$(OUTPUT)/classBasis.o : $(LIBSYS)/classBasis.cpp $(LIBSYS)/classBasis.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classBasis.cpp -o $@

$(OUTPUT)/classSlater.o : $(LIBSYS)/classSlater.cpp $(LIBSYS)/classSlater.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBSYS)/classSlater.cpp -o $@

# Potential Classes

$(OUTPUT)/classQDot2D.o : $(LIBPOT)/classQDot2D.cpp $(LIBPOT)/modQDot2D.cpp $(LIBPOT)/classQDot2D.hpp $(LIBPOT)/classPotential.hpp $(LIBROOT)/libTardis.hpp
	$(CC) $(CFLAGS) $(LIBPOT)/classQDot2D.cpp -o $@

# Solver Classes

$(OUTPUT)/classDiag.o : $(LIBCISD)/classDiag.cpp $(LIBCISD)/classDiag.hpp
	$(CC) $(CFLAGS) $(LIBCISD)/classDiag.cpp -o $@

$(OUTPUT)/classLanczos.o : $(LIBCISD)/classLanczos.cpp $(LIBCISD)/classLanczos.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBCISD)/classLanczos.cpp -o $@

# OpenFCI

$(OUTPUT)/modGaussTools.o : $(LIBFCI)/modGaussTools.cpp $(LIBFCI)/modGaussTools.hpp $(LIBFCI)/lpp/lapack.hh $(LIBFCI)/lpp/lapack_cpp_itf.hh
	$(CC) $(CFLAGS) $(LIBFCI)/modGaussTools.cpp -o $@

$(OUTPUT)/classRadialPotential.o : $(LIBFCI)/classRadialPotential.cpp $(LIBFCI)/classRadialPotential.hpp
	$(CC) $(CFLAGS) $(LIBFCI)/classRadialPotential.cpp -o $@

$(OUTPUT)/classQDotInteraction.o : $(LIBFCI)/classQDotInteraction.cpp $(LIBFCI)/classQDotInteraction.hpp
	$(CC) $(CFLAGS) $(LIBFCI)/classQDotInteraction.cpp -o $@

# Make Clean

clean:
	rm $(OUTPUT)/* $(EXEC)
