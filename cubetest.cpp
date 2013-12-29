#include "cube.cpp"

#include <iostream>

int main(int argv, char** argc) {
	cube a;
	std::cout << a.c[0][0] << std::endl;
	
	cube b = *(a.transform_roll_z());
	
	std::cout << b.c[0][0] << std::endl;
}