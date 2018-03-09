#include "data_manip.hpp"
#include <cassert>
#include <iostream>
#include <string>
int main()
{
	boost::numeric::ublas::matrix <vz_learn::data_manip::data_t> data_matrix;
	vz_learn::data_manip::get_data_from_csv(data_matrix,
			string("../datasets/RealEstate.csv"), true);
	return 0;
}
