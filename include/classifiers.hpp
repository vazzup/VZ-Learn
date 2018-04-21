#ifndef _VZ_CLASSIFIERS_

#define _VZ_CLASSIFIERS_

#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

#include "data_manip.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

std::map< std::map< std::map< double > > > naive_bayes(\
	boost::numeric::ublas::matrix<double>& X,
	const int output_column);
double predict(boost::numeric::ublas::matrix <double>& matrix,
	std::map< std::map< std::map<double> > >& rules);
#endif
