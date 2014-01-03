#include "cube.h"

#ifndef RUBIKS_CUBE
#include "cubesolver.h"
#endif

cube* read_cube(); // should be moved to separate file later? (like when we write it)

cube* solve_cube(cube*);

void execute_soln(cube*); // should probably also get its own file
