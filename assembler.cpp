#include <string>
#include <functional>

#include "assembler.h"
#include "cube.h"

std::string assembler_O0(std::string in);

std::string remove_fours(std::string moves) {
	for(int i = 0; i + 4 <= moves.size(); i++) {
		/* test if theres a contiguous block of 4 chars */
		bool same = true;
		for(int j = i + 1; same && (j < i + 4); j++) {
			same = moves[j] == moves[i];
		}
		if(same) {
			moves = moves.substr(0, i) + moves.substr(i+4);
			/* i must be set back in case removing moves in the middle made a new set */
			i = i - 4 < -1 ? -1 : i - 4;
		}
	}
	return moves;
}

std::string assemble(std::string hlm) {
	return assembler_O0(hlm);
}

std::string assembler_O0(std::string in) {
	std::function<void(Cube&)> ops[128];
	ops[(int)'D'] = &Cube::D;
	ops[(int)'d'] = &Cube::d;
	ops[(int)'U'] = &Cube::U;
	ops[(int)'u'] = &Cube::u;
	ops[(int)'F'] = &Cube::F;
	ops[(int)'f'] = &Cube::f;
	ops[(int)'R'] = &Cube::R;
	ops[(int)'r'] = &Cube::r;
	ops[(int)'B'] = &Cube::B;
	ops[(int)'b'] = &Cube::b;
	ops[(int)'L'] = &Cube::L;
	ops[(int)'l'] = &Cube::l;
	Cube c;
	for(int i = 0; i < in.size(); i++) {
		ops[(int)in[i]](c);
	}
	return c.hist;
}
