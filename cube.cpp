#include "cube.h"

/* cube face: 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */

/* cube net: 0: bot, 1: top, 2: front, 3: right, 4: back, 5: left
 * face origins are as follows: top: top-left, all others as if transformed from top
 * bottom: as if transformed from top via two forward rotations
 *   1
 *   2
 * 5 0 3
 *   4
 */

void rotate_side(int*, int);
void flip_h(int*);
void flip_v(int*);

cube::cube() {
	c = (int**) malloc(sizeof(int*) * 6);
	for(int i = 0; i < 6; i++) {
		c[i] = (int*) malloc(sizeof(int) * 9);
		for(int j = 0; j < 9; j++){ 
			c[i][j] = i;
#ifdef DEBUG_CUBE_STATE
			c[i][j] = 10 * c[i][j] + j;
#endif
		}
	}
	hist = "";
}

cube::~cube() {
	for(int i = 0; i < 6; i++) {
		free(c[i]);
	}
	free(c);
}

std::vector<cube*>* cube::neighbours() {
	std::vector<cube*>* v = new std::vector<cube*>;
	v->push_back(new cube);
	return v;
}

cube* cube::transform_roll_z() {
	cube* n = copy();
	
	int* t = n->c[1];
	int* r = n->c[3];
	int* b = n->c[0];
	int* l = n->c[5];
	
	n->c[1] = l;
	n->c[3] = t;
	n->c[0] = r;
	rotate_side(n->c[0], 0);
	rotate_side(n->c[0], 0);
	n->c[5] = b;
	rotate_side(n->c[5], 0);
	rotate_side(n->c[5], 0);
	
	rotate_side(n->c[2], 1);
	rotate_side(n->c[4], 0);
	
	n->hist += "z";
	
	return n;
}

cube* cube::transform_roll_x() {
	cube* n = copy();
	
	int* t = n->c[1];
	int* f = n->c[2];
	int* b = n->c[0];
	int* r = n->c[4];
	
	n->c[1] = r;
	n->c[2] = t;
	n->c[0] = f;
	n->c[4] = b;
	
	rotate_side(n->c[5], 1);
	rotate_side(n->c[3], 0);
	
	n->hist += "x";
	
	return n;
}

cube* cube::transform_rot_l() {
	cube* n = copy();
	
	int a = n->c[1][2],
		b = n->c[1][5],
		c = n->c[1][8];
	
	n->c[1][2] = n->c[2][2];
	n->c[1][5] = n->c[2][5];
	n->c[1][8] = n->c[2][8];
	
	n->c[2][2] = n->c[0][2];
	n->c[2][5] = n->c[0][5];
	n->c[2][8] = n->c[0][8];
		
	n->c[0][2] = n->c[4][2];
	n->c[0][5] = n->c[4][5];
	n->c[0][8] = n->c[4][8];
	
	n->c[4][2] = a;
	n->c[4][5] = b;
	n->c[4][8] = c;
	
	rotate_side(n->c[3], 1);
	
	n->hist += "l";
	
	return n;
}

cube* cube::transform_rot_r() {
	cube* n = copy();
	
	int a = n->c[1][2],
		b = n->c[1][5],
		c = n->c[1][8];
	
	n->c[1][2] = n->c[4][2];
	n->c[1][5] = n->c[4][5];
	n->c[1][8] = n->c[4][8];
	
	n->c[4][2] = n->c[0][2];
	n->c[4][5] = n->c[0][5];
	n->c[4][8] = n->c[0][8];
		
	n->c[0][2] = n->c[2][2];
	n->c[0][5] = n->c[2][5];
	n->c[0][8] = n->c[2][8];
	
	n->c[2][2] = a;
	n->c[2][5] = b;
	n->c[2][8] = c;
	
	rotate_side(n->c[3], 0);
	
	n->hist += "r";
	
	return n;
}

cube* cube::copy() {
	cube* n = new cube;
	for(int i = 0; i < 6; i++) {
		memcpy(n->c[i], this->c[i], 9 * sizeof(int));
	}
	n->hist = this->hist;
	return n;
}

bool cube::solved() {
	for(int f = 0; f < 6; f++) {
		int v = c[f][0];
		for(int i = 1; i < 9; i++) {
			if(c[f][i] != v) {
				return false;
			}
		}
	}
	return true;
}

void display_side(int* s, int iw, int offset) { //finish later
	
	char* o = (char*) malloc(offset * sizeof(char));
	for(int i = 0; i < offset; i++) {
		o[i] = ' ';
	}
	
	for(int i = 0; i < 3; i++) {
		std::cout << o << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << s[i * 3 + j] << ' ';
		}
		std::cout << std::endl;
	}
}

void cube::display() {
	//const int iw = 2;
	
	
}

/* cube face: 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */

// dir = 0 is clockwise, dir = 1 is counterclockwise
void rotate_side(int* f, int dir) {
	int c, m;
	switch(dir) {
		case 0:
		c = f[0];
		m = f[1];
		
		f[1] = f[3];
		f[0] = f[6];
		
		f[3] = f[7];
		f[6] = f[8];
		
		f[7] = f[5];
		f[8] = f[2];
		
		f[5] = m;
		f[2] = c;
		break;
		
		case 1:
		c = f[0];
		m = f[3];
		
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