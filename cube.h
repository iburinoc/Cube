#include <string>
#include <cstdint>

typedef __uint128_t uint128_t;

class Cube {
public:
	int c[6][9];
	std::string hist;

	Cube();

	Cube(Cube const& c);

	bool equals(Cube const& c) const;

	void roll();

	void rotate_cw();
	
	void rotate_ccw();

	void turn_cw();

	void turn_ccw();

	void D();
	void d();
	void U();
	void u();
	void F();
	void f();
	void R();
	void r();
	void B();
	void b();
	void L();
	void l();

	bool solved();

	void display();

	__uint128_t serialize() const;
};

void init_ref_arr();

bool operator==(Cube const& a, Cube const& b);

namespace std {
	template <>
	class hash<Cube> {
	public:
		size_t operator()(Cube const& cube) const;
	};
}
