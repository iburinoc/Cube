#include <queue>
#include <time.h>
#include "solver.h"

/**
 * FOR DEBUGGING VECTORS
 */
void print_vect(std::vector<uint128_t>* p) {
	std::cout << "Vector: ";
	int i = p->size();
	for(int j = 0; j < i; j++){
		std::cout << (uint64_t) (*p)[j] << " ";
	}
	std::cout << std::endl;
}

cube* read_cube() {
	cube* c = new cube;
	srand(time(0));
	for(int i = 0; i < 25; i++) {
		//std::cout << c->hist << std::endl;
		int d = rand() % 4;
		cube* n = 0;
		switch(d) {
			case 0: n = c->transform_roll_z(); break;
			case 1: n = c->transform_roll_x(); break;
			case 2: n = c->transform_rot_l(); break;
			case 3: n = c->transform_rot_r(); break;
		}
		delete c;
		c = n;
	}
	std::cout << c->hist << std::endl;
	return c;
}

uint64_t binary_search(std::vector<uint128_t>* v, uint128_t t, uint64_t min, uint64_t max) {
	//	print_vect(v);
	if(min == max) {
		return -1;
	}
	uint64_t mid = min + ((max - min) / 2);
	//std::cout << min << std::endl << mid << std::endl << max << std::endl << std::endl;
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

bool etr_correct_orientation(cube* cube) {
    return (cube->c[1][5] == cube->c[1][4] && cube->c[3][3] == cube->c[3][4]);
}

cube* flip_edges_layer3(cube* start) {
    cube* current0 = start->copy();
    cube* current1;
    for (int i = 0; i < 4; i++) {
        if (etr_correct_orientation(current)) {
            current1 = current0;
            current0 = current0->rotate_etr();
            delete current1;
        }
        current1 = current0->transform_roll_z();
        delete current0;
        current0 = current1->transform_rot_r();
        delete current1;
        current1 = current0->transform_roll_z();
        delete current0;
        current0 = current1->transform_roll_z();
        delete current1;
        current1 = current0;
        current0 = current0->transform_roll_z();
        delete current1;
    }
}

cube* solve_last(cube* start) {
    cube* work0;
    cube* work1;
    work0 = align_edges_layer3(start);
    work1 = align_corners_layer3(work0);
    delete work0;
    work0 = flip_corners_layer3(work1);
    delete work1;
    work1 = flip_edges_layer3(work0);
    delete work0;
    return work1;
}

cube* solve_cube(cube* start) {
	start->hist = "";
	std::vector<uint128_t>* vis = new std::vector<uint128_t>;
	binary_insert(vis, start->serialize(), 0, 0);
	uint64_t size = 1;
	
	std::queue<cube*> q;
	q.push(start);
	while(!q.empty()) {
		cube* top = q.front();
		q.pop();
		if(top->solved()) {
			delete vis;
			std::cout << "return:" << std::endl;
			top->display();
			while(!q.empty()) {
				cube* f = q.front();
				q.pop();
				delete f;
			}
			return top;
		} else {
			std::vector<cube*>* n = top->neighbours();
			for(int i = 0; i < 4; i++) {
				LOG std::cout << (*n)[i]->hist << std::endl;
				LOG (*n)[i]->display();
				uint128_t s = (*n)[i]->serialize();
				LOG std::cout << "serialize" << std::endl;
				uint64_t loc = binary_search(vis, s, 0, size);
				LOG std::cout << loc << std::endl;
				if(loc == 0xffffffffffffffff) {
					binary_insert(vis, s, 0, size);
					size++;
					if((*n)[i]->solved()) {
						delete vis;
						std::cout << "return:" << std::endl;
						(*n)[i]->display();
						while(!q.empty()) {
							cube* f = q.front();
							q.pop();
							delete f;
						}
						delete top;
						return (*n)[i];
					}
					q.push((*n)[i]);
				} else {
					cube* dead = (*n)[i];
					delete dead;
				}
			}
			delete n;
			delete top;
		}
	}
	
	std::cout << "should not reach here" << std::endl;
	delete vis;
	return 0;
}

void execute_soln(cube* solved) {
	// do something with solved->hist
}
