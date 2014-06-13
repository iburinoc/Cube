#include <iostream>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "serial.h"

/*
void sync(int fd) {
sync:
	const char* conn = "SYN";
	const char* response = "SYN-ACK";
	const char* final = "ACK";
	write(fd, conn, 3);
	char b;
	int i = 0;
	while(response[i]) {
		while(read(fd, &b, 1) == 0);
		if(b != response[i]) {
			goto sync;
		} else {
			i++;
		}
	}
	write(fd, final, 3);
}
*/

int main(int argc, char** argv) {
	int fd = getserialfd(argv[1], B9600);
	while(1) {
		char c;
		if(read(fd, &c, 1) > 0) {
			putchar(c);
		}
		c = getchar();
		if(c != EOF) {
			write(fd, &c, 1);
		}
	}
}
