#include <vector>
#include "constants.h"

class cube {
public:
	int c[6][9];
	
	std::vector<cube*>* neighbours();
};
