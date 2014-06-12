#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "cube.h"
#include "solution.h"
#include "assembler.h"

struct op {
	std::function<void(Cube&)> rot;
	char name;
};

struct op hlops[] = {
	{ &Cube::D, 'D' },
	{ &Cube::d, 'd' },
	{ &Cube::U, 'U' },
	{ &Cube::u, 'u' },
	{ &Cube::F, 'F' },
	{ &Cube::f, 'f' },
	{ &Cube::R, 'R' },
	{ &Cube::r, 'r' },
	{ &Cube::B, 'B' },
	{ &Cube::b, 'b' },
	{ &Cube::L, 'L' },
	{ &Cube::l, 'l' }
};

int test_cube() {
	Cube c;
	for(int i = 0; i < 100; i++) {
		int n = rand()%12;
		hlops[n].rot(c);
		printf("%c", hlops[n].name);
	}
	printf("\n");

	std::string soln = solution(c);
	std::cout << soln << std::endl;
	std::cout << assembler_O(soln) << std::endl;
	for(int i = 0; i < soln.size(); i++) {
		char m = soln[i];
		for(int j = 0; j < 12; j++) {
			if(hlops[j].name == m) {
				hlops[j].rot(c);
				break;
			}
		}
	}
	return c.solved() ? 1 : 0;
}

int main() {
	srand(time(NULL));
	for(int i = 0; i < 100; i++) {
		std::cout << std::endl;
		if(test_cube() == 0) {
			std::cout << ":C" << std::endl;
		}
	}
}

