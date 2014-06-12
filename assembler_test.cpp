#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "cube.h"
#include "assembler.h"

void test_trie(Trie t, std::string key) {
	std::function<void(Cube&)> lops[128];
	lops[(int)'f'] = &Cube::roll;
	lops[(int)'r'] = &Cube::rotate_cw;
	lops[(int)'l'] = &Cube::rotate_ccw;
	lops[(int)'c'] = &Cube::turn_cw;
	lops[(int)'w'] = &Cube::turn_ccw;
	Cube a;
	for(int j = 0; j < key.size(); j++) {
		lops[key[j]](a);
	}
	Cube b;
	for(int j = 0; j < t.r.size(); j++) {
		lops[t.r[j]](b);
	}
	std::cout << key << std::endl << t.r << std::endl;
	if(a != b) {
		std::cout << key << std::endl << t.r << std::endl;
		a.display();
		b.display();
		abort();
	}
	for(int i = 0; i < t.subs.size(); i++) {
		test_trie(t.subs[i], key + t.subs[i].c);
	}
}

int main() {
	test_trie(lltrie, "");
}

int mains() {
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
		int len = rand() % 100 + 500;
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
		std::cout << s.size() << ":" << assembled.size() << std::endl;
		if(a != b) {
			a.display();
			b.display();
			return 1;
		}
	}
	return 0;
}

