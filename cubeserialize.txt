byte vref[6][6][6];
byte rvref[32][3];
byte eref[6][6];
byte reref[32][3];
for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 6; k++) {
            vref[i][j][k] = 31; 
            if (i == 2 && j == 5 && k == 1) {
                vref[i][j][k] = 0;
            } else if (i == 1 && j == 2 && k == 5) {
                vref[i][j][k] = 1;
            } else if (i == 5 && j == 1 && k == 2) {
                vref[i][j][k] = 2;       
            } else if (i == 2 && j == 1 && k == 3) {
                vref[i][j][k] = 4;
            } else if (i == 3 && j == 2 && k == 1) {
                vref[i][j][k] = 5;
            } else if (i == 1 && j == 3 && k == 2) {
                vref[i][j][k] = 6;
            } else if (i == 2 && j == 0 && k == 5) {
                vref[i][j][k] = 8;
            } else if (i == 5 && j == 2 && k == 0) {
                vref[i][j][k] = 9;
            } else if (i == 0 && j == 5 && k == 2) {
                vref[i][j][k] = 10;
            } else if (i == 2 && j == 3 && k == 0) {
                vref[i][j][k] = 12;
            } else if (i == 0 && j == 2 && k == 3) {
                vref[i][j][k] = 13;
            } else if (i == 3 && j == 0 && k == 2) {
                vref[i][j][k] = 14;
            } else if (i == 4 && j == 1 && k == 5) {
                vref[i][j][k] = 16;
            } else if (i == 5 && j == 4 && k == 1) {
                vref[i][j][k] = 17;
            } else if (i == 1 && j == 5 && k == 4) {
                vref[i][j][k] = 18;
            } else if (i == 4 && j == 3 && k == 1) {
                vref[i][j][k] = 20;
            } else if (i == 1 && j == 4 && k == 3) {
                vref[i][j][k] = 21;
            } else if (i == 3 && j == 1 && k == 4) {
                vref[i][j][k] = 22;
            } else if (i == 4 && j == 5 && k == 0) {
                vref[i][j][k] = 24;
            } else if (i == 0 && j == 4 && k == 5) {
                vref[i][j][k] = 25;
            } else if (i == 5 && j == 0 && k == 4) {
                vref[i][j][k] = 26;
            } else if (i == 4 && j == 0 && k == 3) {
                vref[i][j][k] = 28;
            } else if (i == 3 && j == 4 && k == 0) {
                vref[i][j][k] = 29;
            } else if (i == 0 && j == 3 && k == 4) {
                vref[i][j][k] = 30;
            }
        }
    }
}

for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
        eref[i][j] = 31;
        if (i == 2 && j == 1) {
            eref[i][j] = 0;
        } else if (i == 1 && j == 2) {
            eref[i][j] = 1;
        } else if (i == 2 && j == 3) {
            eref[i][j] = 2;
        } else if (i == 3 && j == 2) {
            eref[i][j] = 3;
        } else if (i == 2 && j == 0) {
            eref[i][j] = 4;
        } else if (i == 0 && j == 2) {
            eref[i][j] = 5;
        } else if (i == 2 && j == 5) {
            eref[i][j] = 6;
        } else if (i == 5 && j == 2) {
            eref[i][j] = 7;
        } else if (i == 1 && j == 3) {
            eref[i][j] = 8;
        } else if (i == 3 && j == 1) {
            eref[i][j] = 9;
        } else if (i == 3 && j == 0) {
            eref[i][j] = 10;
        } else if (i == 0 && j == 3) {
            eref[i][j] = 11;
        } else if (i == 0 && j == 5) {
            eref[i][j] = 12;
        } else if (i == 5 && j == 0) {
            eref[i][j] = 13;
        } else if (i == 5 && j == 1) {
            eref[i][j] = 14;
        } else if (i == 1 && j == 5) {
            eref[i][j] = 15;
        } else if (i == 4 && j == 1) {
            eref[i][j] = 16;
        } else if (i == 1 && j == 4) {
            eref[i][j] = 17;
        } else if (i == 4 && j == 3) {
            eref[i][j] = 18;
        } else if (i == 3 && j == 4) {
            eref[i][j] = 19;
        } else if (i == 4 && j == 0) {
            eref[i][j] = 20;
        } else if (i == 0 && j == 4) {
            eref[i][j] = 21;
        } else if (i == 4 && j == 5) {
            eref[i][j] = 22;
        } else if (i == 5 && j == 4) {
            eref[i][j] = 23;
        }
    }
}

//THIS GOES IN THE METHOD.
uint128_t value = 0;
value += vref[c[2][0]][c[5][8]][c[1][6]] << 0;
value += vref[c[2][2]][c[1][8]][c[3][6]] << 5;
value += vref[c[2][6]][c[0][0]][c[5][6]] << 10;
value += vref[c[2][8]][c[3][8]][c[0][2]] << 15;
value += vref[c[4][6]][c[1][0]][c[5][2]] << 20;
value += vref[c[4][8]][c[3][0]][c[1][2]] << 25;
value += vref[c[4][0]][c[5][0]][c[0][6]] << 30;
value += vref[c[4][2]][c[0][8]][c[3][2]] << 35;
value += eref[c[2][1]][c[1][7]] << 40;
value += eref[c[2][5]][c[3][7]] << 45;
value += eref[c[2][7]][c[0][1]] << 50;
value += eref[c[2][3]][c[5][7]] << 55;
value += eref[c[1][5]][c[3][3]] << 60;
value += eref[c[3][5]][c[0][5]] << 65;
value += eref[c[0][3]][c[5][3]] << 70;
value += eref[c[5][5]][c[1][3]] << 75;
value += eref[c[4][7]][c[1][1]] << 80;
value += eref[c[4][5]][c[3][1]] << 85;
value += eref[c[4][1]][c[0][7]] << 90;
value += eref[c[4][3]][c[5][1]] << 95;
value += c[2][4] << 100;
value += c[1][4] << 103;
value += c[3][4] << 106;
value += c[0][4] << 109;
value += c[5][4] << 112;
value += c[4][4] << 115;


//DESERIALIZE AND UNFINISHED CODE IS BELOW! DO NOT USE!

c[2][0] = rvref[(value>>>0)%32][0];
c[5][8] = rvref[(value>>>0)%32][1];
c[1][6] = rvref[(value>>>0)%32][2];
c[2][2] = rvref[(value>>>5)%32][0];
c[1][8] = rvref[(value>>>5)%32][1];
c[3][6] = rvref[(value>>>5)%32][2];
c[2][6] = rvref[(value>>>10)%32][0];
c[0][0] = rvref[(value>>>10)%32][1];
c[5][6] = rvref[(value>>>10)%32][2];
c[2][8] = rvref[(value>>>15)%32][0];
c[3][8] = rvref[(value>>>15)%32][1];
c[0][2] = rvref[(value>>>15)%32][2];
c[4][6] = rvref[(value>>>20)%32][0];
c[1][0] = rvref[(value>>>20)%32][1];
c[5][2] = rvref[(value>>>20)%32][2];
c[4][8] = rvref[(value>>>25)%32][0];
c[3][0] = rvref[(value>>>25)%32][1];
c[1][2] = rvref[(value>>>25)%32][2];
c[4][0] = rvref[(value>>>30)%32][0];
c[5][0] = rvref[(value>>>30)%32][1];
c[0][6] = rvref[(value>>>30)%32][2];
c[4][2] = rvref[(value>>>35)%32][0];
c[0][8] = rvref[(value>>>35)%32][1];
c[3][2] = rvref[(value>>>35)%32][2];
c[2][1] = reref[(value>>>40)%32][0];
c[1][7] = reref[(value>>>40)%32][1];
c[2][5] = reref[(value>>>45)%32][0];
c[3][7] = reref[(value>>>45)%32][1];
c[2][7] = reref[(value>>>50)%32][0];
c[0][1] = reref[(value>>>50)%32][1];
c[2][3] = reref[(value>>>55)%32][0];
c[5][7] = reref[(value>>>55)%32][1];
c[1][5] = reref[(value>>>60)%32][0];
c[3][3] = reref[(value>>>60)%32][1];
c[3][5] = reref[(value>>>65)%32][0];
c[0][5] = reref[(value>>>65)%32][1];
c[0][3] = reref[(value>>>70)%32][0];
c[5][3] = reref[(value>>>70)%32][1];
c[5][5] = reref[(value>>>75)%32][0];
c[1][3] = reref[(value>>>75)%32][1];
c[4][7] = reref[(value>>>80)%32][0];
c[1][1] = reref[(value>>>80)%32][1];
c[4][5] = reref[(value>>>85)%32][0];
c[3][1] = reref[(value>>>85)%32][1];
c[4][1] = reref[(value>>>90)%32][0];
c[0][7] = reref[(value>>>90)%32][1];
c[4][3] = reref[(value>>>95)%32][0];
c[5][1] = reref[(value>>>95)%32][1];
c[2][4] = (value>>>100)%8;
c[1][4] = (value>>>103)%8;
c[3][4] = (value>>>106)%8;
c[0][4] = (value>>>109)%8;
c[5][4] = (value>>>112)%8;
c[4][4] = (value>>>115)%8;
