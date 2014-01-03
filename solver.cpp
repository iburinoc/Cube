#include <queue>
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
	std::vector<uint128_t>* vis = new std::vector<uint128_t>;
	binary_insert(vis, start->serialize(), 0, 0);
	uint64_t size = 1;
	
	std::queue<cube*> q;
	q.push(start);
	while(!q.empty()) {
		cube* top = q.front();
		q.pop();
		if(top->solved()) {
			return top;
		} else {
			std::vector<cube*>* n = top->neighbours();
			for(int i = 0; i < 4; i++) {
				uint128_t s = (*n)[i]->serialize();
				if(binary_search(vis, s, 0, size) == -1) {
					binary_insert(vis, s, 0, size);
					size++;
					q.push((*n)[i]);
				} else {
					delete (*n)[i];
				}
			}
			delete n;
			delete top;
		}
	}
	
	
	delete vis;
	return 0;
}

void execute_soln(cube* solved) {
	// do something with solved->hist
}
