#include <iostream>
#include <fstream>
#include <functional>

#include "cube.h"

int main() {
	std::function<void(Cube&)> lops[128];
	lops[(int)'f'] = &Cube::roll;
	lops[(int)'r'] = &Cube::rotate_cw;
	lops[(int)'l'] = &Cube::rotate_ccw;
	lops[(int)'c'] = &Cube::turn_cw;
	lops[(int)'w'] = &Cube::turn_ccw;

	std::ifstream in;
	in.open("ltol.txt");
	int linenum = 0;
	std::string line;

	while(!in.eof() && (in >> line, line) != "") {
		int ind = line.find("->");
		if(ind == -1) {
			throw "Invalid file";
		}
		std::string key = line.substr(0, ind);
		std::string res = line.substr(ind + 2);

		Cube a, b;
		for(int i = 0; i < key.size(); i++) {
			lops[(int)key[i]](a);
		}
		for(int i = 0; i < res.size(); i++) {
			lops[(int)res[i]](a);
		}
		if(a != b) {
			a.display();
			b.display();
			std::cout << linenum << ": " << line << std::endl;
		}
		linenum++;
	}
}

