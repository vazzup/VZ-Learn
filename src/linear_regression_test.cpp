#include "linear_regression.hpp"
#include "data_manip.hpp"
#include <boost/numeric/ublas/matrix.hpp>

double hypothesis_function(boost::numeric::ublas::matrix <double>& input_matrix,\
	boost::numeric::ublas::matrix <double>& parameters,\
	boost::numeric::ublas::matrix <double>& hypothesis)
{
	assert(input_matrix.size2() == parameters.size1());
	hypothesis = prod(input_matrix, parameters);
}

int main()
{
	boost::numeric::ublas::matrix <double> input_matrix, parameters,\
		output_matrix;
	std::string filepath = "../datasets/RealEstate.csv";
	vz_learn::data_manip::get_data_from_csv(input_matrix, filepath, true, true, false);
	return 0;
}
