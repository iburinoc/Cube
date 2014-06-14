#include <iostream>

#include "cube.h"
#include "assembler.h"

int main(int argv, char** argc) {
	std::cout << assemble(argc[1]) << std::endl;
}

