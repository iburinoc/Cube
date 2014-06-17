#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>

#include "solution.h"
#include "cube.h"
#include "serial.h"
#include "assembler.h"

/* reads a face of the cube from stdin */
static void getface(std::string face, int side, Cube& c) {
	char sides[128];
	sides[(int)'w'] = 0;
	sides[(int)'r'] = 1;
	sides[(int)'g'] = 2;
	sides[(int)'o'] = 4;
	sides[(int)'b'] = 5;
	sides[(int)'y'] = 3;

	std::cout << face << std::endl;
	for(int i = 0; i < 9; i++) {
		char ch;
		std::cin >> ch;
		c.c[side][i] = sides[(int)ch];
	}
}

/* reads all 6 faces */
static Cube getcube() {
	Cube c;
	getface("top", 0, c);
	getface("front", 1, c);
	getface("right", 2, c);
	getface("back", 4, c);
	getface("left", 5, c);
	getface("bottom", 3, c);
	return c;
}

/* writes the moves out to serial port */
static void writeMoves(std::string moves, char* port) {
	int fd = getserialfd(port);
	char c = '\0';
	while(read(fd, &c, 1) == 0 || c != 'b');
	for(int i = 0; i < moves.size(); i++) {
		char c = moves[i];
		write(fd, &c, 1);
		while(read(fd, &c, 1) == 0 || c != moves[i]);
		putchar(c);
		/* sleep is important for healthy living */
		usleep(500 * 1000);
	}
	putchar('\n');
	close(fd);
}

int main(int argc, char** argv) {
	Cube c = getcube();
	std::string sol = solution(c);
	std::cout << sol << std::endl;
	std::string moves = assemble(sol);
	std::cout << moves << std::endl;
	moves += 'r';

	writeMoves(moves, argv[1]);
}

