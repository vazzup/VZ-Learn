#ifndef _VZ_LINEAR_REGRESSION_

#define _VZ_LINEAR_REGRESSION_

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#include <iostream>

#include "data_manip.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace vz_learn::algorithm
{
	void linear_regression(boost::numeric::ublas::matrix <double>& input_matrix,\
		boost::numeric::ublas::matrix <double>& output_matrix,\
		boost::numeric::ublas::matrix <double>& parameters,\
		void (*hypothesis_function)\
			(boost::numeric::ublas::matrix<double>& input_matrix,\
			boost::numeric::ublas::matrix<double>& parameters,\
			boost::numeric::ublas::matrix<double>& hypothesis),\
		const double alpha=1e-2, const int iterations=500, const bool debug=false);
}

#endif
