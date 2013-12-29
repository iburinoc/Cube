#include "cube.cpp"

int main(int argv, char** argc) {
	cube a;
	std::cout << a.c[0][0] << std::endl;
	std::cout << a.c[5][3] << std::endl;
	
	cube b = *(a.transform_roll_z());
	
	std::cout << b.c[0][0] << std::endl;
	std::cout << b.c[5][0] << std::endl;
	
	std::cout << a.c[5][3] << std::endl;
	std::cout << a.transform_roll_z()->transform_roll_z()->transform_roll_z()->transform_roll_z()->c[5][3] << std::endl;
	
	std::cout << std::endl;
	
	cube** l = (cube**) malloc(5 * sizeof(cube*));
	l[0] = &a;
	l[1] = l[0]->transform_roll_z();
	l[2] = l[1]->transform_roll_z();
	l[3] = l[2]->transform_roll_z();
	l[4] = l[3]->transform_roll_z();
	
	std::cout << l[0]->c[5][3] << std::endl;
	std::cout << l[1]->c[1][3] << std::endl;
	std::cout << l[2]->c[3][3] << std::endl;
	std::cout << l[3]->c[0][5] << std::endl;
	std::cout << l[4]->c[5][3] << std::endl;
	
	std::cout << std::endl;
	display_side(l[0]->c[5], 2, 0);
	
	std::cout << std::endl;
	display_side(l[1]->c[1], 2, 0);
	
	std::cout << std::endl;
	display_side(l[2]->c[3], 2, 0);
	
	std::cout << std::endl;
	display_side(l[3]->c[0], 2, 0);
	
	std::cout << std::endl;
	display_side(l[4]->c[5], 2, 0);
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	l[1] = l[0]->transform_roll_x();
	l[2] = l[1]->transform_roll_x();
	l[3] = l[2]->transform_roll_x();
	l[4] = l[3]->transform_roll_x();
	
	std::cout << std::endl;
	display_side(l[0]->c[5], 2, 0);
	
	std::cout << std::endl;
	display_side(l[1]->c[5], 2, 0);
	
	std::cout << std::endl;
	display_side(l[2]->c[5], 2, 0);
	
	std::cout << std::endl;
	display_side(l[3]->c[5], 2, 0);
	
	std::cout << std::endl;
	display_side(l[4]->c[5], 2, 0);
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	//std::cout << a.c[5][3] << std::endl;
	display_side(a.c[5], 2, 0);
	std::cout << std::endl;
	
	rotate_side(a.c[5], 0);
	display_side(a.c[5], 2, 0);
	std::cout << std::endl;
	//std::cout << a.c[5][3] << std::endl;
	
	rotate_side(a.c[5], 0);
	display_side(a.c[5], 2, 0);
	std::cout << std::endl;
	//std::cout << a.c[5][3] << std::endl;
	
	rotate_side(a.c[5], 1);
	display_side(a.c[5], 2, 0);
	std::cout << std::endl;
	//std::cout << a.c[5][3] << std::endl;
	
	rotate_side(a.c[5], 1);
	//std::cout << a.c[5][3] << std::endl;
	
	display_side(a.c[5], 2, 0);
}