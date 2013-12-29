#include <vector>

#ifndef RUBIXS_CUBE
#include "cubesolver.h"
#endif

class cube {
public:
	int** c; // array of faces, which are themselves arrays of ints represeting the colors on each tile
	
	cube();
	
	std::vector<cube*>* neighbours();
	
	cube* transform_roll_z();
	
	cube* transform_roll_x();
	
	cube* transform_rot_l();
	
	cube* transform_rot_r();
	
	cube* copy();
	
	bool solved();
};
