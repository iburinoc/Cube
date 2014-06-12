#include <iostream>
#include <cstdlib>
#include <cstring>

#include "cube.h"

/* Cube face: 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */

/* Cube net: 0: top, 1: front, 2: right, 3: bottom, 4: back, 5: left
 *   0
 * 5 1 2
 *   3
 *   4
 */

static void rotate_side(unsigned char*, bool);

Cube::Cube(){
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 9; j++) {
			c[i][j] = i;
		}
	}
	hist = "";
}

Cube::Cube(Cube const& that) {
	memcpy(this->c, that.c, sizeof(this->c));
	this->hist = that.hist;
}

bool Cube::equals(Cube const& that) const {
	return memcmp(that.c, this->c, sizeof(this->c)) == 0;
}

void Cube::roll() {		
	unsigned char tmp[9];
	memcpy(tmp, c[0], sizeof(unsigned char) * 9);
	unsigned char tmp2[] = {c[4][8], c[4][7], c[4][6], c[4][5], c[4][4], c[4][3], c[4][2], c[4][1], c[4][0]};
	memcpy(c[0], tmp2, sizeof(unsigned char) * 9);
	unsigned char tmp3[] = {c[3][8], c[3][7], c[3][6], c[3][5], c[3][4], c[3][3], c[3][2], c[3][1], c[3][0]};
	memcpy(c[4], tmp3, sizeof(unsigned char) * 9);
	memcpy(c[3], c[1], sizeof(unsigned char) * 9);
	memcpy(c[1], tmp, sizeof(unsigned char) * 9);
	rotate_side(c[5], false);
	rotate_side(c[2], true);
	hist += "f";
}

void Cube::rotate_cw() {
	unsigned char tmp[9];
	memcpy(tmp,  c[1], sizeof(unsigned char) * 9);
	memcpy(c[1], c[2], sizeof(unsigned char) * 9);
	memcpy(c[2], c[4], sizeof(unsigned char) * 9);
	memcpy(c[4], c[5], sizeof(unsigned char) * 9);
	memcpy(c[5], tmp, sizeof(unsigned char) * 9);	
	rotate_side(c[0], false);
	rotate_side(c[3], true);
	hist += "r";
}

void Cube::rotate_ccw() {
	unsigned char tmp[9];
	memcpy(tmp,  c[1], sizeof(unsigned char) * 9);
	memcpy(c[1], c[5], sizeof(unsigned char) * 9);
	memcpy(c[5], c[4], sizeof(unsigned char) * 9);
	memcpy(c[4], c[2], sizeof(unsigned char) * 9);
	memcpy(c[2],  tmp, sizeof(unsigned char) * 9);	
	rotate_side(c[0], true);
	rotate_side(c[3], false);
	hist += "l";
}

void Cube::turn_cw() {
	unsigned char tmp[] = {c[1][6], c[1][7], c[1][8]};
	for (int i = 6; i < 9; i++) {
		c[1][i] = c[5][i];
		c[5][i] = c[4][i];
		c[4][i] = c[2][i];
		c[2][i] = tmp[i - 6];
	}
	rotate_side(c[3], false);
	hist += "c";
}

void Cube::turn_ccw() {
	unsigned char tmp[] = {c[1][6], c[1][7], c[1][8]};
	for (int i = 6; i < 9; i++) {
		c[1][i] = c[2][i];
		c[2][i] = c[4][i];
		c[4][i] = c[5][i];
		c[5][i] = tmp[i - 6];
	}
	rotate_side(c[3], true);
	hist += "w";
}

// dir = false is clockwise, dir = true is counter clockwise
static void rotate_side(unsigned char* f, bool dir) {
	unsigned char c, m;
	if (!dir) {
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
	} else {
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
	}	
}

void Cube::D() {
	turn_cw();
}

void Cube::d() {
	turn_ccw();
}

void Cube::U() {
	roll();
	roll();
	turn_cw();
	roll();
	roll();
}

void Cube::u() {
	roll();
	roll();
	turn_ccw();
	roll();
	roll();
}

void Cube::F() {
	roll();
	turn_cw();
	roll();
	roll();
	roll();
}

void Cube::f() {
	roll();
	turn_ccw();
	roll();
	roll();
	roll();
}

void Cube::R() {
	rotate_cw();
	roll();
	turn_cw();
	roll();
	roll();
	roll();
	rotate_ccw();
}

void Cube::r() {
	rotate_cw();
	roll();
	turn_ccw();
	roll();
	roll();
	roll();
	rotate_ccw();
}

void Cube::B() {
	roll();
	roll();
	roll();
	turn_cw();
	roll();
}

void Cube::b() {
	roll();
	roll();
	roll();
	turn_ccw();
	roll();
}

void Cube::L() {
	rotate_ccw();
	roll();
	turn_cw();
	roll();
	roll();
	roll();
	rotate_cw();
}

void Cube::l() {
	rotate_ccw();
	roll();
	turn_ccw();
	roll();
	roll();
	roll();
	rotate_cw();
}

bool Cube::solved() {
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

void Cube::apply_ll(std::string s) {
	for(int i = 0; i < s.size(); i++) {
		switch(s[i]) {
			case 'f': roll(); break;
			case 'r': rotate_cw(); break;
			case 'l': rotate_ccw(); break;
			case 'c': turn_cw(); break;
			case 'w': turn_ccw();
		}
	}
}

void Cube::apply_hl(std::string s) {
	for(int i = 0; i < s.size(); i++) {
		switch(s[i]) {
			case 'D': D(); break;
			case 'd': d(); break;
			case 'U': U(); break;
			case 'u': u(); break;
			case 'F': F(); break;
			case 'f': f(); break;
			case 'R': R(); break;
			case 'r': r(); break;
			case 'B': B(); break;
			case 'b': b(); break;
			case 'L': L(); break;
			case 'l': l(); break;
		}
	}
}

static void display_side(unsigned char* s, int offset) { //finish later
	
	unsigned char* o = new unsigned char[offset+1];
	for(int i = 0; i < offset; i++) {
		o[i] = ' ';
	}
	o[offset] = '\0';
	
	for(int i = 0; i < 3; i++) {
		std::cout << o << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << (int)s[i * 3 + j] << ' ';
		}
		std::cout << std::endl;
	}
}

static void display_triple(unsigned char* a,unsigned char* b,unsigned char* c) {
	for(int i = 0; i < 3; i++) {
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << (int)a[i * 3 + j] << ' ';
		}
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << (int)b[i * 3 + j] << ' ';
		}
		std::cout << ' ';
		for(int j = 0; j < 3; j++) {
			std::cout << (int)c[i * 3 + j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Cube::display() {
	display_side(c[0], 7);
	display_triple(c[5], c[1], c[2]);
	display_side(c[3], 7);
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

uint128_t Cube::serialize() const {
    uint128_t value = 0;
    value |= (uint128_t)(vref[c[2][0]][c[5][8]][c[1][6]]) << 0;
    value |= (uint128_t)(vref[c[2][2]][c[1][8]][c[3][6]]) << 5;
    value |= (uint128_t)(vref[c[2][6]][c[0][0]][c[5][6]]) << 10;
    value |= (uint128_t)(vref[c[2][8]][c[3][8]][c[0][2]]) << 15;
    value |= (uint128_t)(vref[c[4][6]][c[1][0]][c[5][2]]) << 20;
    value |= (uint128_t)(vref[c[4][8]][c[3][0]][c[1][2]]) << 25;
    value |= (uint128_t)(vref[c[4][0]][c[5][0]][c[0][6]]) << 30;
    value |= (uint128_t)(vref[c[4][2]][c[0][8]][c[3][2]]) << 35;
    value |= (uint128_t)(eref[c[2][1]][c[1][7]]) << 40;
    value |= (uint128_t)(eref[c[2][5]][c[3][7]]) << 45;
    value |= (uint128_t)(eref[c[2][7]][c[0][1]]) << 50;
    value |= (uint128_t)(eref[c[2][3]][c[5][7]]) << 55;
    value |= (uint128_t)(eref[c[1][5]][c[3][3]]) << 60;
    value |= (uint128_t)(eref[c[3][5]][c[0][5]]) << 65;
    value |= (uint128_t)(eref[c[0][3]][c[5][3]]) << 70;
    value |= (uint128_t)(eref[c[5][5]][c[1][3]]) << 75;
    value |= (uint128_t)(eref[c[4][7]][c[1][1]]) << 80;
    value |= (uint128_t)(eref[c[4][5]][c[3][1]]) << 85;
    value |= (uint128_t)(eref[c[4][1]][c[0][7]]) << 90;
    value |= (uint128_t)(eref[c[4][3]][c[5][1]]) << 95;
    value |= (uint128_t)(c[2][4]) << 100;
    value |= (uint128_t)(c[1][4]) << 103;
    value |= (uint128_t)(c[3][4]) << 106;
    value |= (uint128_t)(c[0][4]) << 109;
    value |= (uint128_t)(c[5][4]) << 112;
    value |= (uint128_t)(c[4][4]) << 115;
    return value;
}

bool operator==(Cube const& a, Cube const& b) {
	return a.equals(b);
}

bool operator!=(Cube const& a, Cube const& b) {
	return !a.equals(b);
}

namespace std {
	size_t hash<Cube>::operator()(Cube const& cube) const {
		return (size_t) cube.serialize();
	}
}
