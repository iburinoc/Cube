#include "solver.h"

cube* read_cube() {
	return new cube;
}

uint64_t binary_search(std::vector<uint128_t>* v, uint128_t t, uint64_t min, uint64_t max) {
	if(min == max) {
		return -1;
	}
	
	uint64_t mid = min + ((max - min) / 2);
	std::cout << min << std::endl << mid << std::endl << max << std::endl << std::endl;
	if((*v)[mid] == t) {
		return mid;
	} else if((*v)[mid] < t) {
		return binary_search(v, t, mid + 1, max);
	} else {
		return binary_search(v, t, min, mid);
	}
	std::cout << "shouldnt reach here" << std::endl;
	std::cout << (uint64_t) t << ";" << mid << ";" << (uint64_t) ((*v)[mid]) << std::endl;
	return -1;
}	             

void binary_insert(std::vector<uint128_t>* v, uint128_t i, uint64_t min, uint64_t max) {
	
}

cube* solve_cube(cube* start) {
	vector<uint128>* visited;
	return 0;
}

void execute_soln(cube* solved) {
	// do something with solved->hist
}
