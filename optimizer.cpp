#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstdint>

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
	for(int n = 2; n < len; n+=2) {
		int* ops = new int[n];
		memset(ops, 0, sizeof(int) * n);

		bool done = false;
		Cube* c = new Cube[n];
		for(int i = 1; i < n; i++) {
			Cube tmp = c[i-1];
			llops[ops[i]].rot(tmp);
			c[i] = tmp;
		}
		int lastchanged = n-1;
		do {
			Cube tmp;
			if(lastchanged != 0) {
				tmp = c[lastchanged-1];
			}
			for(;lastchanged < n; lastchanged++) {
				llops[ops[lastchanged]].rot(tmp);
			}
			if(tmp == target) {
				return tmp;
			}
			for(lastchanged = n-1; lastchanged >= 0; lastchanged--) {
				ops[lastchanged]++;
				ops[lastchanged]%=5;
				if(ops[lastchanged] != 0) {
					goto done;
				}
			}
			done:;
		} while(!done);

		delete ops;
		delete c;
	}
	return target;
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
	optimize(2);
}
