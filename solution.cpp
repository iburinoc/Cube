#include "solution.h"

std::string solution(Cube c) {
	std::string a = ""; // The string containing the letter representation
                        // of the high-level moves needed to solve the cube.
	const int T = c.c[0][4]; // The color of the top face.
	const int f[6][4] = {{4, 5, 2, 1},
						 {0, 5, 2, 3},
						 {0, 1, 4, 3},
						 {1, 5, 2, 4},
						 {0, 2, 5, 3},
						 {0, 4, 1, 3}};
                         // Stores the number of the face as it is adjacent to another face.
                         // If face n has an edge piece in position m,
                         // then f[n][k/2] contains the number of the face
                         // that the other part of the edge is on.
                         // We do k/2 as k will be either 1, 3, 5 or 7 if the piece is an edge piece.
	const int p[6][4] = {{c.c[4][1], c.c[5][1], c.c[2][1], c.c[1][1]},
						 {c.c[0][7], c.c[5][5], c.c[2][3], c.c[3][1]},
						 {c.c[0][5], c.c[1][5], c.c[4][3], c.c[3][5]},
						 {c.c[1][7], c.c[5][7], c.c[2][7], c.c[4][7]},
						 {c.c[0][1], c.c[2][5], c.c[5][3], c.c[3][7]},
						 {c.c[0][3], c.c[4][5], c.c[1][3], c.c[3][3]}};
                         // Same as above, only this contains the color on the other side of the edge.
    // The following loop creates the top face.
	for (int t = 0; t < 6; c.display()) { // Loop through every color that can be on the opposite side of an edge that is on the top face.
                                  // There are no pieces that have the same color as the top, 
                                  // and no pieces that have the color of the opposite face,
                                  // so those iterations of the loop will just do nothing.
		for (int i = 0; i < 6; i++) { 
			for (int j = 1; j < 9; j += 2) { // These two loops check every possible edge piece, from either side.
				if (c.c[i][j] == T && p[i][j / 2] == t) { // This locates the correct piece.
					if (i == 0) { // If the piece is in the top layer, with the correct side facing up.
						if (p[i][j/2] != c.c[f[i][j / 2]][4]) { // Assuming the piece isn't in the correct location...
							switch (j) { // Put the piece in the bottom layer, facing down.
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
						} else {
                            t++;
                        }
					} else if (i == 3) { // If the piece is in the bottom layer, with the top face's color facing down.
						if (p[i][j/2] == c.c[f[i][j / 2]][4]) { // If the piece is on the correct side of the cube, but on the bottom...
							switch (j) {
								case 1: // Move it to the top layer, facing up.
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
                            // The piece is now in place, so we do not decrement t.
                            t++;
						} else { // If the piece is on the bottom layer, but on the wrong side.
							a += "D"; // Rotate the bottom layer, to eventually move the piece into the correct side.
							c.D();
						}
					} else if (j == 1) { // If the piece is in the top layer, but with the color inverted.
						switch (i) { // Move it to the bottom layer, facing outward.
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
					} else if (j == 7) { // If the piece is in the bottom layer, with the top face's color facing outwards...
						a += "D"; // Rotate the bottom face. 
                                  //This is here as it appears in both cases anyway, so might as well do it now.
						c.D();
						if (t == c.c[i][4]) { // If the piece is on the right side... 
							switch (i) { // We move the piece into position via this fancy sequence of moves.
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
                            t++;// t is not decremented, as the piece is now in position.
						} else {
						}
					} else if (j == 3) { // If the piece is in the middle layer...
						switch (i) { // We rotate it into either the top or the bottom. The other cases will the take care of it.
							case 1:
								a += "LDl";
								c.L();
								c.D();
								c.l();
								break;
							case 2:
								a += "FDf";
								c.F();
								c.D();
								c.f();
								break;
							case 4:
								a += "RDr";
								c.R();
								c.D();
								c.r();
								break;
							case 5:
								a += "BDb";
								c.B();
								c.D();
								c.b();
								break;
						}
					} else {
						switch (i) {
							case 1:
								a += "rDR";
								c.r();
								c.D();
								c.R();
								break;
							case 2:
								a += "bDB";
								c.b();
								c.D();
								c.B();
								break;
							case 4:
								a += "lDL";
								c.l();
								c.D();
								c.L();
								break;
							case 5:
								a += "fDF";
								c.f();
								c.D();
								c.F();
								break;
						}
					}
					goto l;
				}
			}
		}
        t++;
		l:;
		a += "@";
	}
	/*
	const int r[6][5] = {{c.c[5][0], c.c[4][0], -1, c.c[1][0], c.c[2][0]},
						 {c.c[5][2], c.c[0][8], -1, c.c[3][0], c.c[2][6]},
						 {c.c[1][2], c.c[0][2], -1, c.c[3][2], c.c[4][6]},
						 {c.c[5][8], c.c[1][8], -1, c.c[4][8], c.c[2][8]},
						 {c.c[2][2], c.c[0][0], -1, c.c[3][8], c.c[5][6]},
						 {c.c[4][2], c.c[0][6], -1, c.c[3][6], c.c[1][6]}};
	const int m[] = {3, 1, -1, 7, 5};
	for (int t = 0; t < 6; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j += 2) {
				if (c.c[i][j] == T && r[i][j / 2] == t) {
					if (i == 0) {
						if (t != c.c[f[i][m[j / 2] / 2]][4]) {
							switch (j) {
								case 0:
									a += "BDb";
									c.B();
									c.D();
									c.b();
									break;
								case 2:
									a += "RDr";
									c.R();
									c.D();
									c.r();
									break;
								case 6:
									a += "LDl";
									c.L();
									c.D();
									c.l();
									break;
								case 8:
									a += "FDf";
									c.F();
									c.D();
									c.f();
									break;
							}
							t--;							
						}
					} else if (i == 3) {
						if (j == 6) {
							a += "rdR";
							c.r();
							c.d();
							c.R();							
						} else {
							a += "D";
							c.D();
						}
						t--;
					} else if (j == 0) {
						switch (i) {
							case 1:
								a += "Ldl";
								c.L();
								c.d();
								c.l();
								break;
							case 2:
								a += "Fdf";
								c.F();
								c.d();
								c.f();
								break;
							case 4:
								a += "Rdr";
								c.R();
								c.d();
								c.r();
								break;
							case 5:
								a += "Bdb";
								c.B();
								c.d();
								c.b();
								break;
						}
						t--;
					} else if (j == 2) {
						switch (i) {
							case 1:
								a += "rDR";
								c.r();
								c.D();
								c.R();
								break;
							case 2:
								a += "bDB";
								c.b();
								c.D();
								c.B();
								break;
							case 4:
								a += "lDL";
								c.l();
								c.D();
								c.L();
								break;
							case 5:
								a += "fDF";
								c.f();
								c.D();
								c.F();
								break;
						}
						t--;
					} else if (j == 6) {
						if (c.c[i][4] == p[i][m[j / 2] / 2]) {
							switch (i) {
								case 1:
									a += "fdF";
									c.f();
									c.d();
									c.F();
									break;
								case 2:
									a += "rdR";
									c.r();
									c.d();
									c.R();
									break;
								case 4:
									a += "bdB";
									c.b();
									c.d();
									c.B();
									break;
								case 5:
									a += "ldL";
									c.l();
									c.d();
									c.L();
									break;
							}						
						} else {
							a += "D";
							c.D();
							t--;
						}
					} else {
						if (c.c[f[i][m[j / 2] / 2]][4] == p[i][m[j / 2] / 2]) {
							switch (i) {
								case 1:
									a += "FDf";
									c.F();
									c.D();
									c.f();
									break;
								case 2:
									a += "RDr";
									c.R();
									c.D();
									c.r();
									break;
								case 4:
									a += "BDb";
									c.B();
									c.D();
									c.b();
									break;
								case 5:
									a += "LDl";
									c.L();
									c.D();
									c.l();
									break;
							}
						} else {
							a += "D";
							c.D();
							t--;
						}
					}
					goto q;
				}
			}
		}
		q:;
	}*/
	/*
	for (int t = 0; t < 6; t++) {
		if (t % 3 != 0) {
			for (int i = 0; i < 6; i++) {
				for (int j = 1; j < 9; j += 2) {
					if (c.c[i][j] == t && p[i][j / 2] == c.c[f[t][5]][4]) {
						if (i == 3) {
							if (f[i][j / 2] == t) {
								switch (j) {
									case 1:
										a += "DDFdfdrDR";
										c.D();
										c.D();
										c.F();
										c.d();
										c.f();
										c.d();
										c.r();
										c.D();
										c.R();
										break;
									case 3:
										a += "DDLdldfdF";
										c.D();
										c.D();
										c.L();
										c.d();
										c.l();
										c.d();
										c.f();
										c.d();
										c.F();
										break;
									case 5:
										a += "DDRdrdbdB";
										c.D();
										c.D();
										c.R();
										c.d();
										c.r();
										c.d();
										c.b();
										c.d();
										c.B();										
										break;
									case 7:
										a += "DDBdbdlDL";
										c.D();
										c.D();
										c.B();
										c.d();
										c.b();
										c.d();
										c.l();
										c.D();
										c.L();
										break;
								}
							} else {
								a += "D";
								c.D();
								t--;
							}
						} else {
							if (c.c[i][4] == t || j != 7) {
								switch (i) {
									case 1:
										a += "FdfdrDR";
										c.F();
										c.d();
										c.f();
										c.d();
										c.r();
										c.D();
										c.R();
										break;
									case 2:
										a += "RdrdbdB";
										c.R();
										c.d();
										c.r();
										c.d();
										c.b();
										c.d();
										c.B();										
										break;
									case 4:
										a += "BdbdlDL";
										c.B();
										c.d();
										c.b();
										c.d();
										c.l();
										c.D();
										c.L();
										break;
									case 5:
										a += "LdldfdF";
										c.L();
										c.d();
										c.l();
										c.d();
										c.f();
										c.d();
										c.F();
										break;
								}
								if (j != 7) {
									t--;
								}
							} else {
								a += "D";
								c.D();
								t--;
							}
						}
						goto p;
					}
				}
			}
		}
		p:;
	}*/
	c.display();
	return a;
}
