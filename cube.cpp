#include "cube.h"

/* cube face: 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */

cube::cube() {
	c = (int**) malloc(sizeof(int*) * 6);
	for(int i = 0; i < 6; i++) {
		c[i] = (int*) malloc(sizeof(int) * 9);
		memset(c[i], 0, 9 * sizeof(int));
	}
}

std::vector<cube*>* cube::neighbours() {
	std::vector<cube*>* v = new std::vector<cube*>;
	v->push_back(new cube);
	return v;
}

cube* cube::transform_roll_z() {
	return NULL;
}

cube* cube::transform_roll_x() {
	return NULL;
}

cube* cube::transform_rot_l() {
	return NULL;
}

cube* cube::transform_rot_r() {
	return NULL;
}

/* cube face: 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */

// dir = 0 is clockwise, dir = 1 is counterclockwise
void rotate_side(int* f, int dir) {
	switch(dir) {
		case 0:
		int c = f[0];
		int m = f[1];
		
		f[1] = f[3];
		f[0] = f[6];
		
		f[3] = f[7];
		f[6] = f[8];
		
		f[7] = f[5];
		f[8] = f[2];
		
		f[5] = c;
		f[2] = m;
		break;
		
		case 1:
		int c = f[0];
		int m = f[3];
		
		f[3] = f[1];
		f[0] = f[2];
		
		f[1] = f[5];
		f[2] = f[8];
		
		f[5] = f[7];
		f[8] = f[6];
		
		f[7] = m;
		f[6] = c;
		break;
	}
}

void flip_h(int* f) {
	int a = f[0],
		b = f[3],
		c = f[6];
	
	f[0] = f[2];
	f[3] = f[5];
	f[6] = f[8];
	
	f[2] = a;
	f[5] = b;
	f[8] = c;
}

void flip_v(int* f) {
	int a = f[0],
		b = f[1],
		c = f[2];
	
	f[0] = f[6];
	f[1] = f[7];
	f[2] = f[8];
	
	f[6] = a;
	f[7] = b;
	f[8] = c;
}