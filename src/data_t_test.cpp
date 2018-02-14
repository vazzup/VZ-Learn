#include "data_t.hpp"
#include <iostream>

int main() {
	std::cout << "Starting tests...\n";
	vz_learn::data_manip::data_t test_data(10), test_data2("Hello World");
	std::cout << test_data2 << "\n";
	std::cout << "Changing value of test_data2 to 4 using assignment operator...\n";
	test_data2 = 4;
	std::cout << test_data << "\n";
	std::cout << test_data2 << "\n";
	std::cout << "The sum is " << test_data + test_data2 << std::endl;
	std::cout << "The difference is " << test_data - test_data2 << std::endl;
	std::cout << "The product is " << test_data * test_data2 << std::endl;
	std::cout << "The quotient is " << test_data / test_data2 << std::endl;
	std::cout << "Using assignment operator to set them to strings...\n";
	test_data = "Hello charlie";
	test_data2 = "This is the world";
	std::cout << "The resulting string is " << test_data + ", " + test_data2 << "\n";
	return 0;
}
