#include "data_t.hpp"
#include <cassert>
#include <iostream>

int main() {
	std::cout << "Starting tests...\n";
	vz_learn::data_manip::data_t td(10), td2("Hello World");
	assert(td == 10);
	assert(td2 == "Hello World");
	td2 = 11;
	assert((td2 > td) && (td2 >= td));
	assert((td < td2) && (td <=td2));
	assert(td != td2);
	td2 = 10.0;
	assert((td2 == td) && (td2 >= td) && (td2 <= td));
	assert(td + td2 == 20);
	assert(td - td2 == 0);
	assert(td / td2 == 1);
	assert(td * td2 == 100);
	assert(td + 10 == 20);
	assert(td - 10 == 0);
	assert(td / 10 == 1);
	assert(td * 10 == 100);
	td = "ABC";
	td2 = "XYZ";
	assert((td < td2) && (td2 > td));
	td2 = "ABC";
	assert((td2 == td) && (td2 >= td) && (td2 <= td));
	assert(td + td2 == "ABCABC");
	assert(td + "ABC" == "ABCABC");
	std::cout << "All tests on libdatat.so complete!\n";
	return 0;
}
