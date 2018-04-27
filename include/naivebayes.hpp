#ifndef _VZ_NAIVEBAYES_

#define _VZ_NAIVEBAYES_

#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

#include "data_manip.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace vz_learn::algorithm
{
	void naive_bayes(const boost::numeric::ublas::matrix<double>& X,\
		std::map<double, std::map<int, std::map<double, double> > >& rules,\
		const int output_column);

	double bayesian_predict(std::map<int, double>& column_value,\
		std::map<double, std::map<int, std::map<double, double> > >& rules);
}
#endif
