#include "solver.h"
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main() {
	signal(SIGSEGV, handler);
	cube* start = read_cube();
	start->display();
	cube* solved = solve_cube(start);
	std::cout << solved->hist << std::endl;
	execute_soln(solved);
}

/*
int main() {
	cube* a = new cube;
	std::vector<cube*>* v = a->neighbours();
	printf("%d\n", (*v)[0]->c[0][0]);
	int b[5];
	printf("%d\n", b[0]);
	
	printf("%d\n", a->solved());
	
	int** c = (int**) malloc(sizeof(int*) * 4);
	for(int i = 0; i < 4; i++) {
		c[i] = (int*) malloc(sizeof(int) * 3);
	}
	
	c[3][2] = 5;
	printf("%d\n", c[3][2]);
	
	delete a;
//	int j = 12;
}*/
