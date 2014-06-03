#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stdint.h>

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
	{ &Cube::roll, 'f' },
	{ &Cube::rotate_cw, 'r' },
	{ &Cube::rotate_ccw, 'l' },
	{ &Cube::turn_cw, 'c' },
	{ &Cube::turn_ccw, 'w' }
};

int addonecarry(int* c, int size) {
	for(int i = 0; i < size; i++) {
		c[i]++;
		c[i] %= 12;
		if(c[i] != 0) {
			return 0;
		}
	}
	return 1;
}

Cube solve(Cube target) {
	Cube c;
	long int z = 0;

	if(target == c) {
		return c;
	}

	std::queue<Cube> q;
	q.push(c);

	while(1) {
		Cube top = q.front();
		q.pop();
		z++;
		if((z & ~0xffff) == z) {
			printf("%lx\n", z);
		}

		for(int i = 0; i < sizeof(llops)/sizeof(llops[0]); i++) {
			Cube tmp = top;
			llops[i].rot(tmp);
			if(target == tmp) {
				return tmp;
			}

			q.push(tmp);
		}
	}
}

void optimize(const int n) {
	int r[n];
	memset(r, 0, sizeof(int) * n);

	do {
		Cube c;
		for(int i = 0; i < n; i++) {
			hlops[r[i]].rot(c);
			std::cout << hlops[r[i]].name;
		}
		std::cout << std::endl;
		c.display();
		std::cout << c.hist << std::endl;
		std::cout << solve(c).hist << std::endl << std::endl;
	} while(addonecarry(r, n) == 0);
}

int main(int argc, char** argv) {
	optimize(3);
}
