#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>

#include "solution.h"
#include "cube.h"
#include "serial.h"
#include "assembler.h"

static void getface(std::string face, int side, Cube& c) {
	char sides[128];
	sides[(int)'w'] = 0;
	sides[(int)'r'] = 1;
	sides[(int)'g'] = 2;
	sides[(int)'o'] = 3;
	sides[(int)'b'] = 4;
	sides[(int)'y'] = 5;

	std::cout << face << std::endl;
	for(int i = 0; i < 9; i++) {
		char ch;
		std::cin >> ch;
		c.c[side][i] = sides[(int)ch];
	}
}

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

static void writeMoves(std::string moves, char* port) {
	int fd = getserialfd(port);
	char c = '\0';
	while(read(fd, &c, 1) == 0 || c != 'b');
	for(int i = 0; i < moves.size(); i++) {
		char c = moves[i];
		write(fd, &c, 1);
		while(read(fd, &c, 1) == 0);
		putchar(c);
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
