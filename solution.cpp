int adj(int face, int index, Cube c) {
	int piece[][] = {{c.c[2][7], c.c[5][7], c.c[3][7], c.c[4][7]}, {c.c[2][1], c.c[5][1], c.c[3][1], c.c[4][1]}, {c.c[1][7], c.c[5][5], c.c[3][3], c.c[0][1]}, {c.c[1][5], c.c[2][5], c.c[4][3], c.c[0][5]}, {c.c[1][1], c.c[3][5], c.c[5][3], c.c[0][7]}, {c.c[1][3], c.c[4][5], c.c[2][3], c.c[0][3]}};
	return piece[face][index / 2];
}

string solution(Cube c) {
	final int T = c.c[1][4], B = c.c[0][4];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			if (c.c[i][j] == T && ) {
				
			}
		}
	}
}