#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "cube.h"
#include "assembler.h"

/*
int main() {
	std::string moves = "DdUuFfRrBbLl";
	std::string ops = "";
	srand(time(NULL));
	for(int i = 0; i < 5; i++) {
		int n = rand() % 12;
		ops += moves[n];
	}
	puts(ops.c_str());
	puts(move_assembler(ops).c_str());
}
*/

int main() {
	puts(remove_fours("dUUddddUUllll").c_str());
	puts(remove_undos_hl("dDUUu").c_str());
	puts(assemble("RUr").c_str());
}
