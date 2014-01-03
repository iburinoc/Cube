#include "solver.cpp"

void print_vect(std::vector<uint128_t>* p) {
	std::cout << "Vector: ";
	int i = p->size();
	for(int j = 0; j < i; j++){
		std::cout << (uint64_t) (*p)[j] << " ";
	}
	std::cout << std::endl;
}

void test_binary_search() {
	std::vector<uint128_t> v;
	v.push_back(5);
	v.push_back(12);
	v.push_back(17);
	v.push_back(18);
	v.push_back(100000);
	v.push_back(100001);
	
	std::cout << binary_search(&v, 100000, 0, 6) << std::endl;
}

void test_binary_insert() {
	std::vector<uint128_t> v;
	uint64_t k = -1;
	uint64_t size = 0;
	while(k != 0) {
		std::cin >> k;
		binary_insert(&v, k, 0, size);
		size++;
		print_vect(&v);
	}
}

int main() {
	test_binary_search();
	test_binary_insert();
}