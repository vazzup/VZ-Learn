#ifndef _VZ_DTREE_

#define _VZ_DTREE_

#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "data_manip.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>


namespace vz_learn::algorithm
{
	class dtreenode
	{
		public:
			const static int EQ = 0, LT = 1, GT = 2, NEQ = 3,\
								LTE = 4, GTE = 5;
			std::vector <dtreenode> children;
			int splitting_column_no; // The column that was split to make this one
			int splitting_comparator; // The comparator used to split into this node
			double value; // The value used with the comparator
	};

	void create_decision_tree(\
		boost::numeric::ublas::matrix <double>& input_matrix,\
		std::unordered_set <int> used_columns,\
		dtreenode& parent_node, const int output_column);
	
	double dt_entropy(const std::vector<double> class_frequencies);

	double predict_dtree(dtreenode& root, std::vector<double>& values);
}
#endif
