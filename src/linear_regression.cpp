#include "linear_regression.hpp"

namespace vz_learn::algorithm
{
	void linear_regression(boost::numeric::ublas::matrix <double>& input_matrix,\
		boost::numeric::ublas::matrix <double>& output_matrix,\
		boost::numeric::ublas::matrix <double>& parameters,\
		double (*hypothesis_function)(boost::numeric::ublas::matrix<double>&,\
						boost::numeric::ublas::matrix<double>&),\
		const double alpha, const bool debug)
	{
		assert(input_matrix.size2() == parameters.size1());
		assert(input_matrix.size1() == output_matrix.size1());
		assert(parameters.size2() == output_matrix.size2());
		double cost = 0, prev_cost = -1e20;
		while(abs(cost - prev_cost < 
	}

}
