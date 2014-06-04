#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstdint>
#include <thread>

#include "cube.h"

#define THREADS 5

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

volatile bool solved;
Cube* soln;

void solve(Cube target, int threadnum) {
	for(int n = 2; !solved; n++) {
		int* ops = new int[n-1];
		memset(ops, 0, sizeof(int) * (n-1));

		do {
			Cube c;
			llops[threadnum].rot(c);
			for(int i = 1; i < n-1; i+=2) {
				llops[ops[i]].rot(c);
			}

			if(c == target) {
				solved = true;
				*soln = c;
				return;
			}
		} while(addonecarry(ops, n-1, 5) == 0 && !solved);

		delete ops;
	}
}

Cube solve_master(Cube target) {
	Cube solv;
	if(solv == target) {
		return solv;
	}

	for(int i = 0; i < 5; i++) {
		Cube c;
		llops[i].rot(c);
		if(c == target) {
			return c;
		}
	}

	std::vector<std::thread> slaves;
	solved = false;

	Cube sol;
	soln = &sol;

	for(int i = 0; i < THREADS; i++) {
		slaves.push_back(std::thread(solve, target, i));
	}

	while(!solved);

	for(int i = 0; i < THREADS; i++) {
		slaves[i].join();
	}

	return sol;
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
		std::cout << solve_master(c).hist << std::endl << std::endl;
	} while(addonecarry(r, n) == 0);
}

int main(int argc, char** argv) {
	optimize(2);
}
