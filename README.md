# libTardis

**Full Scale Configuration Interaction library**

This is the source code for my 2012 master's thesis titled "Full Configuration Interaction Simulation of Quantum Dots"
([PDF](https://www.duo.uio.no/bitstream/handle/10852/34217/vkb-olsen.pdf)).

**Note:** This library was written using an older version of the Armadillo library, and doesn't build with the never versions.

### The Physics

The code calculates energy eigenstates of electrons in a two-dimensional harmonic oscillator potential. It uses binary
operations to create and destroy particles in various states, and uses the standard library `bitset` class to allow for
more than 64 quantum states (64 bit). The code has been run up to 512 bit, but there is no ard limit. The code includes
a module of effective interaction code written by Simen Kvaal for his PhD thesis, which significantly speeds up the
initialisation by pre-calculating the energy difference between all possible changes in two-particle states.

The code has partially been extended to allow for three dimensional potentials and thus also allow for performing
calculations on nuclear particles. This implementation was never fully completed as calculations on nuclear particle
interactions require that the code accounts for three-particle interactions, which for electrons are a negligible
contribution.

The core algoritm of the code is a [Lanczos](https://en.wikipedia.org/wiki/Lanczos_algorithm) solver, which iteratively
computes extremal eigenvalues and eigenvectors of very large matrices. Since we are often interested in the lower
eigenstates, this is a useful approach. It has the added benefit over other methodes, like Coupled Cluster and Monte
Carlo methods, that it returns an eigenvector as well, which gives you the coefficients for the lower eigenfunctions and
thus an approximate wave function. This method can for instance be used to verify choice of seed wave functions for
other algorithms.

### Technical

The code does not run on an input file like most physics codes. Mostly because I didn't want to spend time on coding a file
parser at the time. Instead, it can be used by writing a simple main function that creates an object of the problem to
solve, and the pass it through one of the two solvers included in the code.

The solvers are coded in c++, and the repository includes Python scripts that will generate and compile main.cpp files
based on arrays of parameters.

The code is parallelised and tested on an Intel Xeon based super computer, and has been run successfully on up to 1280
cores. It is, however, the first such code I wrote, and it is likely it can be optimised in many ways. The simulations
presented in the thesis represents around 450 000 CPU hours of computations.
