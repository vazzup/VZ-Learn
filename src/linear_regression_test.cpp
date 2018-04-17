#include "linear_regression.hpp"
#include "data_manip.hpp"
#include <boost/numeric/ublas/matrix.hpp>

double cost_function(boost::numeric::ublas::matrix <double>& input_matrix,\
	boost::numeric::ublas::matrix <double>& parameters)
{
	return 42.0;
}

int main()
{
	boost::numeric::ublas::matrix <double> input_matrix, parameters;
	vz_learn::algorithm::linear_regression(input_matrix, parameters,cost_function);
	return 0;
}
