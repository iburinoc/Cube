#include <iostream>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstdio>

#include "serial.h"

int main(int argc, char** argv) {
	int fd = getserialfd(argv[1], B9600);
}
