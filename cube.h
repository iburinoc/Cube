#include <vector>
#include <string>

#ifndef RUBIKS_CUBE
#include "Cubesolver.h"
#endif

class Cube {
public:
	int c[6][9];

	Cube();

	~Cube();

	Cube transform_roll_z();

	Cube transform_roll_x();

	Cube transform_rot_l();

	Cube transform_rot_r();

	bool solved();

	void display();

	__uint128_t serialize();
};

void init_ref_arr();
