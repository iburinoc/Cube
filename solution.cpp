#include "solution.h"

std::string solution(Cube c) {
	std::string a = "";
	const int T = c.c[1][4], B = c.c[0][4];
	const int p[][] = {{c.c[2][7], c.c[5][7], c.c[3][7], c.c[4][7]}, {c.c[2][1], c.c[5][1], c.c[3][1], c.c[4][1]}, {c.c[1][7], c.c[5][5], c.c[3][3], c.c[0][1]}, {c.c[1][5], c.c[2][5], c.c[4][3], c.c[0][5]}, {c.c[1][1], c.c[3][5], c.c[5][3], c.c[0][7]}, {c.c[1][3], c.c[4][5], c.c[2][3], c.c[0][3]}};
	l:
	for (int t = 2; t < 6; t++) {	
		for (int i = 0; i < 6; i++) {
			for (int j = 1; j < 9; j += 2) {
				if (c.c[i][j] == c.c[1][4] && p[face][index / 2] == T) {
					if (i == 1) {
						if ((j == 1 && c.c[4][4] == t) || (j == 3 && c.c[5][4] == t) || (j == 5 && c.c[3][4] == t) || (j == 7 && c.c[2][4] == t)) {
							continue l;
						} else {
							switch (j) {
								case 1:
									a += "BB";
									c.B();
									c.B();
									break;
								case 3:
									a += "LL";
									c.L();
									c.L();
									break;
								case 5:
									a += "RR";
									c.R();
									c.R();
									break;
								case 7:
									a += "FF";
									c.F();
									c.F();
									break;
							}
							t--;
							continue l;
						}
					} else if (i == 0) {
						if ((j == 1 && c.c[2][4] == t) || (j == 3 && c.c[5][4] == t) || (j == 5 && c.c[3][4] == t) || (j == 7 && c.c[4][4] == t)) {
							switch (j) {
								case 1:
									a += "FF";
									c.F();
									c.F();
									break;
								case 3:
									a += "LL";
									c.L();
									c.L();
									break;
								case 5:
									a += "RR";
									c.R();
									c.R();
									break;
								case 7:
									a += "BB";
									c.B();
									c.B();
									break;
							}
						} else {
							a += "D";
							c.D();
							t--;
							continue l;
						}
					} else if (j == 1) {
						switch (i) {
							case 2:
								a += "FF";
								c.F();
								c.F();
								break;
							case 3:
								a += "RR";
								c.R();
								c.R();								
								break;
							case 4:
								a += "BB";
								c.B();
								c.B();
								break;
							case 5:
								a += "LL";
								c.L();
								c.L();
								break;
						}
						t--;
						continue l;
					} else if (j != 7) {
						switch (i) {
							case 2:
								a += "F";
								c.F();
								break;
							case 3:
								a += "R";
								c.R();
								break;
							case 4:
								a += "B";
								c.B();
								break;
							case 5:
								a += "L";
								c.L();
								break;
						}
						t--;
						continue l;
					} else {
						if (c.c[i][4] == T) {
							switch (i) {
								a += "D";
								c.D();
								case 2:
									a += "Rfr";									
									c.R();
									c.f();
									c.r();
									break;
								case 3:
									a += "Brb";
									c.B();
									c.r();
									c.b();
									break;
								case 4:
									a += "Lbl";
									c.L();
									c.b();
									c.l();
								case 5:
									a += "Flf";
									c.F();
									c.l();
									c.f();
									break;
							}
						} else {
							a += "D";
							c.D();
							t--;
							continue l;
						}
					}
				}
			}
		}
	}
	return a;
}

