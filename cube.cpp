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
	v->push_back(transform_roll_z());
	v->push_back(transform_roll_x());
	v->push_back(transform_rot_l());
	v->push_back(transform_rot_r());
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

void display_side(int* s, int offset) { //finish later
	
	char* o = (char*) malloc((offset+1) * sizeof(char));
	for(int i = 0; i < offset; i++) {
		o[i] = ' ';
	}
	o[offset] = '\0';
	
	for(int i = 0; i < 3; i++) {
		std::cout << o << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << s[i * 3 + j] << ' ';
		}
		std::cout << std::endl;
	}
}

void display_triple(int* a,int* b,int* c) {
	for(int i = 0; i < 3; i++) {
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << a[i * 3 + j] << ' ';
		}
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << b[i * 3 + j] << ' ';
		}
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << c[i * 3 + j] << ' ';
		}
		std::cout << std::endl;
	}
}

void cube::display() {
	display_side(c[1], 7);
	display_side(c[2], 7);
	display_triple(c[5], c[0], c[3]);
	display_side(c[4], 7);
	std::cout << std::endl;
}

uint128_t vref[6][6][6];
uint128_t eref[6][6];

void init_ref_arr() {
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				vref[i][j][k] = 31; 
				if (i == 2 && j == 5 && k == 1) {
					vref[i][j][k] = 0;
				} else if (i == 1 && j == 2 && k == 5) {
					vref[i][j][k] = 1;
				} else if (i == 5 && j == 1 && k == 2) {
					vref[i][j][k] = 2;       
				} else if (i == 2 && j == 1 && k == 3) {
					vref[i][j][k] = 4;
				} else if (i == 3 && j == 2 && k == 1) {
					vref[i][j][k] = 5;
				} else if (i == 1 && j == 3 && k == 2) {
					vref[i][j][k] = 6;
				} else if (i == 2 && j == 0 && k == 5) {
					vref[i][j][k] = 8;
				} else if (i == 5 && j == 2 && k == 0) {
					vref[i][j][k] = 9;
				} else if (i == 0 && j == 5 && k == 2) {
					vref[i][j][k] = 10;
				} else if (i == 2 && j == 3 && k == 0) {
					vref[i][j][k] = 12;
				} else if (i == 0 && j == 2 && k == 3) {
					vref[i][j][k] = 13;
				} else if (i == 3 && j == 0 && k == 2) {
					vref[i][j][k] = 14;
				} else if (i == 4 && j == 1 && k == 5) {
					vref[i][j][k] = 16;
				} else if (i == 5 && j == 4 && k == 1) {
					vref[i][j][k] = 17;
				} else if (i == 1 && j == 5 && k == 4) {
					vref[i][j][k] = 18;
				} else if (i == 4 && j == 3 && k == 1) {
					vref[i][j][k] = 20;
				} else if (i == 1 && j == 4 && k == 3) {
					vref[i][j][k] = 21;
				} else if (i == 3 && j == 1 && k == 4) {
					vref[i][j][k] = 22;
				} else if (i == 4 && j == 5 && k == 0) {
					vref[i][j][k] = 24;
				} else if (i == 0 && j == 4 && k == 5) {
					vref[i][j][k] = 25;
				} else if (i == 5 && j == 0 && k == 4) {
					vref[i][j][k] = 26;
				} else if (i == 4 && j == 0 && k == 3) {
					vref[i][j][k] = 28;
				} else if (i == 3 && j == 4 && k == 0) {
					vref[i][j][k] = 29;
				} else if (i == 0 && j == 3 && k == 4) {
					vref[i][j][k] = 30;
				}
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			eref[i][j] = 31;
			if (i == 2 && j == 1) {
				eref[i][j] = 0;
			} else if (i == 1 && j == 2) {
				eref[i][j] = 1;
			} else if (i == 2 && j == 3) {
				eref[i][j] = 2;
			} else if (i == 3 && j == 2) {
				eref[i][j] = 3;
			} else if (i == 2 && j == 0) {
				eref[i][j] = 4;
			} else if (i == 0 && j == 2) {
				eref[i][j] = 5;
			} else if (i == 2 && j == 5) {
				eref[i][j] = 6;
			} else if (i == 5 && j == 2) {
				eref[i][j] = 7;
			} else if (i == 1 && j == 3) {
				eref[i][j] = 8;
			} else if (i == 3 && j == 1) {
				eref[i][j] = 9;
			} else if (i == 3 && j == 0) {
				eref[i][j] = 10;
			} else if (i == 0 && j == 3) {
				eref[i][j] = 11;
			} else if (i == 0 && j == 5) {
				eref[i][j] = 12;
			} else if (i == 5 && j == 0) {
				eref[i][j] = 13;
			} else if (i == 5 && j == 1) {
				eref[i][j] = 14;
			} else if (i == 1 && j == 5) {
				eref[i][j] = 15;
			} else if (i == 4 && j == 1) {
				eref[i][j] = 16;
			} else if (i == 1 && j == 4) {
				eref[i][j] = 17;
			} else if (i == 4 && j == 3) {
				eref[i][j] = 18;
			} else if (i == 3 && j == 4) {
				eref[i][j] = 19;
			} else if (i == 4 && j == 0) {
				eref[i][j] = 20;
			} else if (i == 0 && j == 4) {
				eref[i][j] = 21;
			} else if (i == 4 && j == 5) {
				eref[i][j] = 22;
			} else if (i == 5 && j == 4) {
				eref[i][j] = 23;
			}
		}
    }
}

uint128_t cube::serialize() {
    uint128_t value = 0;
    value |= (vref[c[2][0]][c[5][8]][c[1][6]]) << 0;
    value |= (vref[c[2][2]][c[1][8]][c[3][6]]) << 5;
    value |= (vref[c[2][6]][c[0][0]][c[5][6]]) << 10;
    value |= (vref[c[2][8]][c[3][8]][c[0][2]]) << 15;
    value |= (vref[c[4][6]][c[1][0]][c[5][2]]) << 20;
    value |= (vref[c[4][8]][c[3][0]][c[1][2]]) << 25;
    value |= (vref[c[4][0]][c[5][0]][c[0][6]]) << 30;
    value |= (vref[c[4][2]][c[0][8]][c[3][2]]) << 35;
    value |= (eref[c[2][1]][c[1][7]]) << 40;
    value |= (eref[c[2][5]][c[3][7]]) << 45;
    value |= (eref[c[2][7]][c[0][1]]) << 50;
    value |= (eref[c[2][3]][c[5][7]]) << 55;
    value |= (eref[c[1][5]][c[3][3]]) << 60;
    value |= (eref[c[3][5]][c[0][5]]) << 65;
    value |= (eref[c[0][3]][c[5][3]]) << 70;
    value |= (eref[c[5][5]][c[1][3]]) << 75;
    value |= (eref[c[4][7]][c[1][1]]) << 80;
    value |= (eref[c[4][5]][c[3][1]]) << 85;
    value |= (eref[c[4][1]][c[0][7]]) << 90;
    value |= (eref[c[4][3]][c[5][1]]) << 95;
    value |= (c[2][4]) << 100;
    value |= (c[1][4]) << 103;
    value |= (c[3][4]) << 106;
    value |= (c[0][4]) << 109;
    value |= (c[5][4]) << 112;
    value |= (c[4][4]) << 115;
    return value;
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
