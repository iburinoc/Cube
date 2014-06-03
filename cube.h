#include <vector>
#include <string>

#ifndef RUBIKS_CUBE
#include "Cubesolver.h"
#endif

class Cube {
public:
	int c[6][9];

	Cube();

	Cube(Cube& c);

	void roll();

	void rotate_cw();
	
	void rotate_ccw();

	void turn_cw();

	void turn_ccw();

	bool solved();

	void display();

	__uint128_t serialize();
};

void init_ref_arr();

