#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdint>
#include <fstream>

#include "cube.h"

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

struct op llops[] = {
	{ &Cube::rotate_cw, 'r' },
	{ &Cube::rotate_ccw, 'l' },
	{ &Cube::turn_cw, 'c' },
	{ &Cube::turn_ccw, 'w' },
	{ &Cube::roll, 'f' }
};

static int addonecarry(int* c, int size, int max = 12) {
	for(int i = 0; i < size; i++) {
		c[i]++;
		c[i] %= max;
		if(c[i] != 0) {
			return 0;
		}
	}
	return 1;
}

Cube solve(Cube target) {
	Cube solved;
	long int z = 0;

	if(target == solved) {
		return solved;
	}

	size_t len = target.hist.size();
	for(int n = len % 2 == 0 ? 2 : 1; n < len; n+=2) {
		int* ops = new int[n];
		memset(ops, 0, sizeof(int) * n);

		bool done = false;
		do {
			Cube c;
			for(int i = 0; i < n; i++) {
				llops[ops[i]].rot(c);
			}
			if(c == target) {
				return c;
			}
		} while(addonecarry(ops, n, 5) == 0);

		delete[] ops;
	}
	return target;
}

void optimize(const int n) {
	int r[n];
	memset(r, 0, sizeof(int) * n);

	std::ofstream out;
	out.open("optimized.txt");
	do {
		Cube c;
		for(int i = 0; i < n; i++) {
			hlops[r[i]].rot(c);
			std::cout << hlops[r[i]].name;
			out << hlops[r[i]].name;
		}
		out << "->";
		std::cout << std::endl;
		c.display();
		std::cout << c.hist << std::endl;
		Cube s = solve(c);
		std::cout << s.hist << std::endl << std::endl;
		out << s.hist << std::endl;
	} while(addonecarry(r, n) == 0);
}

int main(int argc, char** argv) {
	int count = 2;
	if(argc >= 2) {
		count = atoi(argv[1]);
	}
	optimize(count);
}
