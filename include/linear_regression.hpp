#include <cassert>
#include <iostream>

#include "data_manip.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace vz_learn::algorithm
{
	void linear_regression(boost::numeric::ublas::matrix <double>& input_matrix,\
		boost::numeric::ublas::matrix <double>& output_matrix,\
		boost::numeric::ublas::matrix <double>& parameters,\
		double (*hypothesis_function)(boost::numeric::ublas::matrix<double>&,\
						boost::numeric::ublas::matrix<double>&),\
		const double alpha=0.01, const bool debug=false);
}
