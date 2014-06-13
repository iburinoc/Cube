#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "cube.h"
#include "assembler.h"
#include "trie.h"

#ifdef TRIE_DEBUG
void test_trie(Trie t, std::string key) {
	Cube a;
	a.apply_ll(key);
	Cube b;
	b.apply_ll(t.r);
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
#else
int main() {
	std::string moves = "DdUuFfRrBbLl";
	srand(time(NULL));
	for(int i = 0; i < 500; i++) {
		int len = rand() % 100 + 2000;
		//int len = 3;
		std::string s = "";
		for(int j = 0; j < len; j++) {
			s += moves[rand()%moves.size()];
		}
		std::cout << s << std::endl;
		std::string assembled = assemble(s);
		Cube a;
		a.apply_hl(s);
		Cube b;
		b.apply_ll(assembled);
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
#endif
