#ifndef SERIAL_H
#define SERIAL_H

int getserialfd(char* port, int speed);

void set_blocking (int fd, int should_block);

#endif
