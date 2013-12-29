#include "cube.h"

int main() {
	cube* a = new cube;
	std::vector<cube*>* v = a->neighbours();
	printf("%d\n", (*v)[0]->c[0][0]);
	int b[5];
	printf("%d\n", b[0]);
}