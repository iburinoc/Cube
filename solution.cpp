#include <iostream>

#include "solution.h"
#define clookup(x, y, z) x.c[f[y][z/2]][4]
// Returns the colour of the centre of the face on the other side of a given edge piece.
#define elookup(x, y, z) x.c[f[y][z/2]][p[y][z/2]]
// Returns the colour of the other side of a given edge piece.
#define rlookup(x, y, z) x.c[f[y][m[z/2]/2]][r[y][z/2]]
// Returns the colour of the other side (going clockwise) of a given corner piece.
#define rclookup(x, y, z) x.c[f[y][m[z / 2] / 2]][4]
// Returns the colour of the centre of the face on the other side (going clockwise) of a given corner piece.

std::string solution(Cube c) {
	std::string a = ""; // The string containing the letter representation
						// of the high-level moves needed to solve the cube.
	std::cin >> a; //Debug so that we see the scramble output.
	a = "";
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
	const int p[6][4] = {{1, 1, 1, 1},
						 {7, 5, 3, 1},
						 {5, 5, 3, 5},
						 {7, 7, 7, 7},
						 {1, 5, 3, 7},
						 {3, 5, 3, 3}};
						 // Stores the index of the edge on the adjacent face
	// The following loop creates the top face.
	for (int t = 0; t < 6;) { // Loop through every color that can be on the opposite side of an edge that is on the top face.
								  // There are no pieces that have the same color as the top, 
								  // and no pieces that have the color of the opposite face,
								  // so those iterations of the loop will just do nothing.
		for (int i = 0; i < 6; i++) { 
			for (int j = 1; j < 9; j += 2) { // These two loops check every possible edge piece, from either side.
				if (c.c[i][j] == c.c[0][4] && elookup(c, i, j) == t) { // This locates the correct piece.
					if (i == 0) { // If the piece is in the top layer, with the correct side facing up.
						if (t != clookup(c, i, j)) { // Assuming the piece isn't in the correct location...
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
						if (t == clookup(c, i, j)) { // If the piece is on the correct side of the cube, but on the bottom...
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
								  //This is here as it appears in all cases anyway, so might as well do it now.
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
							t++; // t is incremented, as the piece is now in position.
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
		t++; // The piece does not exist and therefore we must increment t
		l:;
	}
	const int m[] = {3, 1, -1, 7, 5};
	const int r[6][5] = {{0, 0, -1, 0, 0},
						 {2, 8, -1, 0, 6},
						 {2, 2, -1, 2, 6},
						 {8, 8, -1, 8, 8},
						 {2, 0, -1, 8, 6},
						 {2, 6, -1, 6, 6}};
	for (int t = 0; t < 6;c.display()) { //Debug statement! Remove later!
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j += 2) {
				if (j == 4) {
					j = 6;
				}
				if (c.c[i][j] == c.c[0][4] && rlookup(c, i, j) == t) {
					if (i == 0) {
						if (rlookup(c, i, j) != rclookup(c, i, j)) {
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
								default:
									std::cout << "Wat1";
							}
						} else {
							t++;
						}
					} else if (i == 3) {
						if (j == 6) {
							a += "rdRDFDf";
							c.r();
							c.d();
							c.R();
							c.D();
							c.F();
							c.D();
							c.f();
						} else {
							a += "D";
							c.D();
						}
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
							default:
								std::cout << "Wat2";
						}
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
							default:
								std::cout << "Wat3";
						}
					} else if (j == 6) {
						if (c.c[i][4] == rlookup(c, i, j)) {
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
								default:
									std::cout << "Wat4";
							}
						} else {
							a += "D";
							c.D();
						}
					} else {
						if (rclookup(c, i, j) == rlookup(c, i, j)) {
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
								default:
									std::cout << "Wat5";
							}
						} else {
							a += "D";
							c.D();
						}
					}
					goto q;
				}
			}
		}
		t++;
		q:;
		std::cout << a;
	}	
	for (int t = 0; t < 6; t++) {
		c.display();
		int v;
		for (int i = 0; i < 6; i++) {
			if (c.c[i][4] == t) {
				v = i;
			}
		}
		if (t % 3 != c.c[0][4]) {
			for (int i = 0; i < 6; i++) {
				for (int j = 1; j < 9; j += 2) {
					if (c.c[i][j] == t && c.c[f[i][j / 2]][p[i][j / 2]] == c.c[f[v][5]][4]) {
						if (i == 3) {				
							a += "D";
							c.D();
							if (c.c[f[i][j / 2]][4] == c.c[f[v][5]][4]) {							
								switch (j) {
									case 1:
										a += "LdldfDF";										
										c.L();
										c.d();
										c.l();
										c.d();
										c.f();
										c.D();
										c.F();
										break;
									case 3:
										a += "FdfdrDR";
										c.F();
										c.d();
										c.f();
										c.d();
										c.r();
										c.D();
										c.R();
										break;
									case 5:
										a += "RdrdbDB";							
										c.R();
										c.d();
										c.r();
										c.d();
										c.b();
										c.D();
										c.B();
										break;
									case 7:
										a += "BdbdlDL";
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
								t--;
							}
						} else {
							if ((c.c[i][4] == t && j == 7) || j == 5) {
								a += "d";
								c.d();
								switch (i) {
									case 1:
										a += "rDRDFdf";
										c.r();
										c.D();
										c.R();
										c.D();
										c.F();
										c.d();
										c.f();
										break;
									case 2:
										a += "bDBDRdr";
										c.b();
										c.D();
										c.B();
										c.D();
										c.R();
										c.d();
										c.r();
										break;
									case 4:
										a += "lDLDBdb";
										c.f();
										c.D();
										c.F();
										c.D();
										c.L();
										c.d();
										c.l();
										break;
									case 5:
										a += "fDFDLdl";
										c.f();
										c.D();
										c.F();
										c.D();
										c.L();
										c.d();
										c.l();
										break;
								}
								if (j == 7) {
									t++;
								}
							} else if (j == 3) {
								switch (i) {
									case 1:
										a += "fDFDLdl";
										c.f();
										c.D();
										c.F();
										c.D();
										c.L();
										c.d();
										c.l();
										break;
									case 2:
										a += "rDRDFdf";
										c.r();
										c.D();
										c.R();
										c.D();
										c.F();
										c.d();
										c.f();
										break;
									case 4:
										a += "bDBDRdr";
										c.b();
										c.D();
										c.B();
										c.D();
										c.R();
										c.d();
										c.r();
										break;
									case 5:
										a += "lDLDBdb";
										c.f();
										c.D();
										c.F();
										c.D();
										c.L();
										c.d();
										c.l();
										break;
								}
							} else {
								a += "D";
								c.D();								
							}
							t--;
						}
						goto p;
					}
				}
			}
		}
		p:;
	}
	/*
	while (!(c.c[3][1] == c.c[3][4] && c.c[3][3] == c.c[3][4] && c.c[3][5] == c.c[3][4] && c.c[3][7] == c.c[3][4])) {		
		if (c.c[3][1] == c.c[3][4] || c.c[3][3] == c.c[3][4] || c.c[3][5] == c.c[3][4] || c.c[3][7] == c.c[3][4]) {
			if (c.c[3][3] == c.c[3][4]) {
				if (c.c[3][5] == c.c[3][4]) {
					a += "BRDrdb";
					c.B();
					c.R();
					c.D();
					c.r();
					c.d();
					c.b();
				} else {
					a += "BDRdrb";
					c.B();
					c.D();
					c.R();						
					c.d();
					c.r();
					c.b();
				}
			} else {
				a += "D";
				c.D();
			}
		} else {
			a += "BRDrdb";
			c.B();
			c.R();
			c.D();
			c.r();
			c.d();
			c.b();
		}
	}*/
	/*
	while (!(c.c[3][0] == c.c[3][4] && c.c[3][2] == c.c[3][4] && c.c[3][6] == c.c[3][4] && c.c[3][8] == c.c[3][4])) {
		int n = 0;
		for (int i = 0; i < 4; i++) {
			if (c.c[i][6] == c.c[3][4]) {
				n++;
			}
		}
		if (n % 3 == 1) {
			a += "RDrDRDDr";
			c.R();
			c.D();
			c.r();
			c.D();
			c.R();
			c.D();
			c.D();
			c.r();
		} else {
			a += "D";
			c.D();
		}
	}*/
	/*
	while (!(c.c[1][7] == c.c[1][4] && c.c[2][7] == c.c[2][4] && c.c[4][7] == c.c[4][4] && c.c[5][7] == c.c[5][4])) {
		if (c.c[1][7] == c.c[1][4]) {
			if (c.c[2][7] == c.c[2][4]) {
				a += "D";
				c.D();
			} else if (c.c[5][7] == c.c[5][4]) {
				a += "d";
				c.d();
			}
			a += "RRDRDrdrdrDr";
			c.R();
			c.R();
			c.D();
			c.R();
			c.D();
			c.r();
			c.d();
			c.r();
			c.d();
			c.r();
			c.D();
			c.r();
		} else {
			a += "D";
			c.D();
		}
	}*/
	/*
	while (!(c.c[1][8] == c.c[1][4] && c.c[2][8] == c.c[2][4] && c.c[4][8] == c.c[4][4] && c.c[5][8] == c.c[5][4])) {
		if (c.c[4][8] == c.c[4][4] || c.c[2][8] != c.c[4][4]) {
			a += "rBrFFRbrFFRR";
			c.r();
			c.B();
			c.r();
			c.F();
			c.F();
			c.R();
			c.b();
			c.r();
			c.F();
			c.F();
			c.R();
			c.R();
		} else {
			a += "lFlBBLflBBLL";
			c.l();
			c.F();
			c.l();
			c.B();
			c.B();
			c.L();
			c.f();
			c.l();
			c.B();
			c.B();
			c.L();
			c.L();
		}
	}*/
	c.display();
	return a;
}
