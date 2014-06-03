#include "Cube.h"
#include <iomanip>

int main(int argv, char** argc) {
	Cube c;
	c.display();

	c.turn_cw();
	c.display();

	c.roll();

	c.rotate_ccw();
	c.display();
}

