int adj(int face, int index, Cube c) {
	int piece[][] = {{c.c[2][7], c.c[5][7], c.c[3][7], c.c[4][7]}, {c.c[2][1], c.c[5][1], c.c[3][1], c.c[4][1]}, {c.c[1][7], c.c[5][5], c.c[3][3], c.c[0][1]}, {c.c[1][5], c.c[2][5], c.c[4][3], c.c[0][5]}, {c.c[1][1], c.c[3][5], c.c[5][3], c.c[0][7]}, {c.c[1][3], c.c[4][5], c.c[2][3], c.c[0][3]}};
	return piece[face][index / 2];
}

string solution(Cube c) {
	string a = "";
	final int T = c.c[1][4], B = c.c[0][4];
	l:
	for (int t = 2; t < 6; t++) {	
		for (int i = 0; i < 6; i++) {
			for (int j = 1; j < 9; j += 2) {
				if (c.c[i][j] == c.c[1][4] && adj(i, j, c) == T) {
					if (i == 1) {
						if ((j == 1 && c.c[4][4] == T) || (j == 3 && c.c[5][4] == T) || (j == 5 && c.c[3][4] == T) || (j == 7 && c.c[2][4] == T)) {
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
						if ((j == 1 && c.c[2][4] == T) || (j == 3 && c.c[5][4] == T) || (j == 5 && c.c[3][4] == T) || (j == 7 && c.c[4][4] == T)) {
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
					} else if (j == 7) {
						if (c.c[i][4] == T) {
							switch (i) {
								case 1:
									a += "DRfr";
									c.D();
									c.R();
									c.f();
									c.r();
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
}
