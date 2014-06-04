#include "solution.h"

std::string solution(Cube c) {
	std::string a = "";
	const int T = c.c[0][4], f[][] = {{4, 5, 2, 1}, {0, 5, 2, 3}, {0, 1, 4, 3}, {1, 5, 2, 4}, {0, 2, 5, 3}, {0, 4, 1, 3}}, p[][] = {{c.c[4][1], c.c[5][1], c.c[2][1], c.c[1][1]}, {c.c[0][7], c.c[5][5], c.c[2][3], c.c[3][1]}, {c.c[0][5], c.c[1][5], c.c[4][3], c.c[3][5]}, {c.c[1][7], c.c[5][7], c.c[2][7], c.c[4][7]}, {c.c[0][1], c.c[2][5], c.c[5][3], c.c[3][7]}, {c.c[0][3], c.c[4][5], c.c[1][3], c.c[3][3]}}
	for (int t = 0; t < 6; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 1; j < 9; j += 2) {
				if (c.c[i][j] == T && p[i][j / 2] == t) {
					if (i == 0)
						if (t != c.c[f[i][j / 2]][4]) {
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
						}
						t--;
					} else if (i == 3) {
						if (t == c.c[f[i][j / 2]][4]) {
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
						}
					} else if (j == 1) {
						switch (i) {
							case 1:
								a += "FF";
								c.F();
								c.F();
								break;
							case 2:
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
					} else if (j == 7) {
						a += "D";
						c.D();
						if (t != f[i][j / 2]) {
							t--;
						} else {
							switch (i) {							
								case 1:
									a += "Rfr";
									c.R();
									c.f();
									c.r();
									break;
								case 2:
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
									break;
								case 5:
									a += "Flf";
									c.F();
									c.l();
									c.f();
									break;
							}
						}
					} else {
						switch (i) {
							case 1:
								a += "F";
								c.F();
								break;
							case 2:
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
					}
				}
			}
		}
	}
	return a;
}
