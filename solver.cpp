#include "solver.h"

cube* read_cube() {
	return new cube;
}

uint64_t binary_search(std::vector<uint128_t>* v, uint128_t t, uint64_t min, uint64_t max) {
	uint64_t mid = min + ((max - min) / 2);
//	std::cout << min << std::endl << mid << std::endl << max << std::endl << std::endl;
	if((*v)[mid] < t) {
		return binary_search(v, t, mid + 1, max);
	} else if((*v)[mid] > t){
		return binary_search(v, t, min, mid);
	}
	return mid;
}	             

void binary_insert(std::vector<uint128_t>* v, uint128_t t, uint64_t min, uint64_t max) {
	if(min == max) {
		v->insert(v->begin()+min, t);
		return;
	}
	
	uint64_t mid = min + ((max - min) / 2);
	if((*v)[mid] < t) {
		binary_insert(v, t, mid + 1, max);
		return;
	} else if((*v)[mid] > t){
		binary_insert(v, t, min, mid);
		return;
	}
	v->insert(v->begin()+mid, t);
}

cube* solve_cube(cube* start) {
	std::vector<uint128_t>* visited;
	return 0;
}

void execute_soln(cube* solved) {
	// do something with solved->hist
}
