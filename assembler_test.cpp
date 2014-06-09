#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "cube.h"
#include "assembler.h"

/*
int main() {
	std::string moves = "DdUuFfRrBbLl";
	std::string ops = "";
	srand(time(NULL));
	for(int i = 0; i < 5; i++) {
		int n = rand() % 12;
		ops += moves[n];
	}
	puts(ops.c_str());
	puts(move_assembler(ops).c_str());
}

int main() {
	puts(remove_fours("dUUddddUUllll").c_str());
	puts(remove_undos_hl("dDUUu").c_str());
	puts(assemble("RUr").c_str());
	Trie t = construct_trie("RollResults.txt");
	puts(t.match("lllfff").result().c_str());
}
*/

int main() {
	std::function<void(Cube&)> hops[128];
	hops[(int)'D'] = &Cube::D;
	hops[(int)'d'] = &Cube::d;
	hops[(int)'U'] = &Cube::U;
	hops[(int)'u'] = &Cube::u;
	hops[(int)'F'] = &Cube::F;
	hops[(int)'f'] = &Cube::f;
	hops[(int)'R'] = &Cube::R;
	hops[(int)'r'] = &Cube::r;
	hops[(int)'B'] = &Cube::B;
	hops[(int)'b'] = &Cube::b;
	hops[(int)'L'] = &Cube::L;
	hops[(int)'l'] = &Cube::l;

	std::function<void(Cube&)> lops[128];
	lops[(int)'f'] = &Cube::roll;
	lops[(int)'r'] = &Cube::rotate_cw;
	lops[(int)'l'] = &Cube::rotate_ccw;
	lops[(int)'c'] = &Cube::turn_cw;
	lops[(int)'w'] = &Cube::turn_ccw;

	std::string moves = "DdUuFfRrBbLl";
	srand(time(NULL));
	for(int i = 0; i < 100; i++) {
		int len = rand() % 15 + 20;
		//int len = 3;
		std::string s = "";
		for(int j = 0; j < len; j++) {
			s += moves[rand()%moves.size()];
		}
		std::string assembled = assembler_O(s);
		Cube a;
		for(int j = 0; j < s.size(); j++) {
			hops[s[j]](a);
		}
		Cube b;
		for(int j = 0; j < assembled.size(); j++) {
			lops[assembled[j]](b);
		}
		std::cout << s << std::endl << assembled << std::endl;
		if(a != b) {
			a.display();
			b.display();
			return 1;
		}
	}
	return 0;
}
