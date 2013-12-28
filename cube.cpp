//#include <vector>
#include "cube.hpp"

std::vector<cube*>* cube::neighbours() {
	std::vector<cube*>* v = new std::vector<cube*>;
	v->push_back(new cube);
	return v;
}

int main() {
	cube* a = new cube;
	std::vector<cube*>* v = a->neighbours();
	
}