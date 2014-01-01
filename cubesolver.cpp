#include "cube.h"

int main() {
	cube* a = new cube;
	std::vector<cube*>* v = a->neighbours();
	printf("%d\n", (*v)[0]->c[0][0]);
	int b[5];
	printf("%d\n", b[0]);
	
	printf("%d\n", a->solved());
	
	int** c = (int**) malloc(sizeof(int*) * 4);
	for(int i = 0; i < 4; i++) {
		c[i] = (int*) malloc(sizeof(int) * 3);
	}
	
	c[3][2] = 5;
	printf("%d\n", c[3][2]);
//	int j = 12;
}