#ifndef _VZ_KMEANS_

#define _VZ_KMEANS_

#include <cassert>
#include <iostream>
#include <limits>
#include <random>

#include "data_manip.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace vz_learn::algorithm
{
	void kmeans(const boost::numeric::ublas::matrix <double>& input_matrix,\
		double (*distance_function) (const std::vector<double>& row_one,\
					const std::vector<double>& row_two),\
		std::vector<std::vector<double> >& clusters,\
		const int number_of_clusters=2, const bool debug=false);
}
#endif
