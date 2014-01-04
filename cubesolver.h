#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stdint.h>
#include <iostream>

#define RUBIXS_CUBE  

#define WHITE 0
#define GREEN 1
#define ORANGE 2

#define DEBUG  

#define LOG_LVL 0

#define L(x) if(LOG_LVL >= x)
#define LOG L(1)

typedef __uint128_t uint128_t;