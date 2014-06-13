#include <iostream>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "serial.h"

bool inputAvailable() {
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return (FD_ISSET(0, &fds));
}

int main(int argc, char** argv) {
	int fd = getserialfd(argv[1], B9600);
	while(1) {
		char c;
		if(read(fd, &c, 1) > 0) {
			putchar(c);
		}
		if(inputAvailable()) {
			c = getchar();
			if(c != EOF) {
				write(fd, &c, 1);
			}
		}
	}
}
