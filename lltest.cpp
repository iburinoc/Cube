#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>

#include "solution.h"
#include "cube.h"
#include "serial.h"
#include "assembler.h"

/* reads a face of the cube from stdin */
static void getface(std::string face, int side, Cube& c) {
	char sides[128];
	sides[(int)'w'] = 0;
	sides[(int)'r'] = 1;
	sides[(int)'g'] = 2;
	sides[(int)'o'] = 3;
	sides[(int)'b'] = 4;
	sides[(int)'y'] = 5;

	std::cout << face << std::endl;
	for(int i = 0; i < 9; i++) {
		char ch;
		std::cin >> ch;
		c.c[side][i] = sides[(int)ch];
	}
}

/* reads all 6 faces */
static Cube getcube() {
	Cube c;
	getface("top", 0, c);
	getface("front", 1, c);
	getface("right", 2, c);
	getface("back", 4, c);
	getface("left", 5, c);
	getface("bottom", 3, c);
	return c;
}

int main(int argc, char** argv) {
	Cube c = getcube();
	c.display();
	while(1) {
		char ch;
		std::cin >> ch;
		std::string s = "i";
		s[0] = ch;
		c.apply_ll(s);
		c.display();
	}
}

