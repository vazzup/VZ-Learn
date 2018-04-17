#include "data_manip.hpp"
#include <cassert>
#include <iostream>
#include <string>
int main()
{
	boost::numeric::ublas::matrix <double> data_matrix;
	vz_learn::data_manip::get_data_from_csv(data_matrix,\
		std::string("../datasets/RealEstate.csv"), true, true);
	int rows = data_matrix.size1();
	int columns = data_matrix.size2();
	vz_learn::data_manip::print_head<double>(data_matrix);
	std::cout << rows << " " << columns << "\n"; 
	return 0;
}
