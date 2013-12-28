#include <vector>

using namespace std;

typedef struct {
	int cube[6][9];
} cube;

vector<cube*>* neighbours(cube*);
