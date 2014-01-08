#include <vector>
#include <string>

#ifndef RUBIKS_CUBE
#include "cubesolver.h"
#endif

class cube {
public:
	int** c; // array of faces, which are themselves arrays of ints represeting the colors on each tile
	
	std::string hist; //history of transforms applied to this cube
	
	cube();
	
	~cube();
	
	std::vector<cube*>* neighbours();
	
	cube* transform_roll_z();
	
	cube* transform_roll_x();
	
	cube* transform_rot_l();
	
	cube* transform_rot_r();
	
    cube* swap_etl_etf();

    cube* swap_vbrt_vrft_vflt();

    cube* rotate_vftr();

    cube* rotate_etr();

    cube* move_ebd_to_erf();

    cube* move_eld_to_efr();

	cube* copy();
	
	bool solved();
	
	void display();
	
	__uint128_t serialize();
};

void init_ref_arr();
