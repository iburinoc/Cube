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
	for(int i = 0; i < 5; i++) {
		int n = rand()%12;
		hlops[n].rot(c);
		printf("%c\n", hlops[n].name);
		c.display();
	}

	std::string soln = solution(c);
	std::cout << soln << std::endl;
}

