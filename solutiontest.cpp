#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "cube.h"
#include "solution.h"

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

int main() {
	Cube c;
	srand(time(NULL));
	for(int i = 0; i < 100; i++) {
		hlops[rand()%12].rot(c);
	}

	c.display();

	std::string soln = solution(c);
	std::cout << soln << std::endl;
}

