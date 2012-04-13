CC          = g++
DEBUG       = -g
LIBADD      =
LIBFLAGS    = -llapack -lblas -larmadillo -fopenmp $(LIBADD)
CFLAGS      = -Wall -O2 -c $(DEBUG)
LFLAGS      = -Wall $(DEBUG)

LIBROOT     = libTardis
LIBSYS      = $(LIBROOT)/System
LIBCISD     = $(LIBROOT)/CISD
NODE        = Test
COMPILE     = tempCompile
OUTPUT      = $(COMPILE)/$(NODE)

EXEC        = CISD-$(NODE)
MAIN        = main.cpp
SYSOBJECTS  = classSystem.o classSlater.o classBasis.o
CISDOBJECTS = classLanczos.o
OBJECTS     = $(addprefix $(OUTPUT)/,$(SYSOBJECTS) $(CISDOBJECTS))

$(shell [ -d "$(OUTPUT)" ] || mkdir -p $(OUTPUT))

$(EXEC) : $(OUTPUT)/main.o $(OBJECTS)
	$(CC) $(LFLAGS) $(OUTPUT)/main.o $(OBJECTS) $(LIBFLAGS) -o $@

$(OUTPUT)/main.o : $(MAIN)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(MAIN) -o $@

$(OUTPUT)/classSystem.o : $(LIBSYS)/classSystem.cpp $(LIBSYS)/classSystem.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classSystem.cpp -o $@

$(OUTPUT)/classSlater.o : $(LIBSYS)/classSlater.cpp $(LIBSYS)/classSlater.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classSlater.cpp -o $@

$(OUTPUT)/classBasis.o : $(LIBSYS)/classBasis.cpp $(LIBSYS)/classBasis.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBSYS)/classBasis.cpp -o $@

$(OUTPUT)/classLanczos.o : $(LIBCISD)/classLanczos.cpp $(LIBCISD)/classLanczos.hpp $(LIBROOT)/config.hpp
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBCISD)/classLanczos.cpp -o $@

clean:
	rm $(OUTPUT)/* $(EXEC)
