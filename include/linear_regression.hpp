#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "data_manip.hpp"

namespace vz_learn::algorithm
{
	void linear_regression(boost::numeric::ublas::matrix <double>& input_matrix,\
		boost::numeric::ublas::matrix <double>& parameters,\ 
		double (*cost_function)(boost::numeric::ublas::matrix<double>&,\
			boost::numeric::ublas::matrix<double>&), double alpha=0.01);
}
