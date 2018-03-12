#include "data_manip.hpp"
#include <cassert>
#include <iostream>
#include <string>
int main()
{
	boost::numeric::ublas::matrix <vz_learn::data_manip::data_t> data_matrix;
	vz_learn::data_manip::get_data_from_csv(data_matrix,\
			std::string("../datasets/RealEstate.csv"), true);
	int rows = data_matrix.size1();
	int columns = data_matrix.size2();
	vz_learn::data_manip::print_head(data_matrix);
	vz_learn::data_manip::one_hot_encode(data_matrix, 1);
	vz_learn::data_manip::print_head(data_matrix);
	return 0;
}
