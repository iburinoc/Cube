#include "solver.cpp"

void test_binary_search() {
	std::vector<uint128_t> v;
	v.push_back(5);
	v.push_back(12);
	v.push_back(17);
	v.push_back(18);
	v.push_back(100000);
	v.push_back(100001);
	
	std::cout << (binary_search(&v, 100002, 0, 6) == -1);
}

int main() {
	test_binary_search();
}