#include "linear_regression.hpp"

namespace vz_learn::algorithm
{
	std::vector<double> linear_regression(\
		boost::numeric::ublas::matrix <double>& input_matrix,\
		boost::numeric::ublas::matrix <double>& output_matrix,\
		boost::numeric::ublas::matrix <double>& parameters,\
		void (*hypothesis_function)\
			(boost::numeric::ublas::matrix<double>& input_matrix,\
			boost::numeric::ublas::matrix<double>& parameters,\
			boost::numeric::ublas::matrix<double>& hypothesis),\
		const double alpha, const int iterations, const bool debug)
	{
		if(debug)
			std::cout << "Starting Linear Regression...\n";
		std::vector<double> cost_vector;
		assert(input_matrix.size2() == parameters.size1());
		assert(input_matrix.size1() == output_matrix.size1());
		assert(parameters.size2() == output_matrix.size2());
		assert(parameters.size2() == 1);
		boost::numeric::ublas::matrix <double> hypothesis;
		boost::numeric::ublas::matrix <double> delta_parameters;
		int input_rows = input_matrix.size1(),\
			input_columns = input_matrix.size2();
		int output_rows = output_matrix.size1(),\
			output_columns = output_matrix.size2();
		int parameter_rows = parameters.size1(),\
			parameter_columns = parameters.size2();
		for(int iteration=0; iteration<iterations; iteration++)
		{
			hypothesis_function(input_matrix, parameters, hypothesis);
			assert(hypothesis.size1() == output_matrix.size1());
			assert(hypothesis.size2() == output_matrix.size2());
			hypothesis = output_matrix - hypothesis; // Error
			hypothesis = prod(trans(hypothesis), hypothesis); // Square Error
			// Mean Square Error
			double cost =\
				boost::numeric::ublas::sum(boost::numeric::ublas::prec_prod(
					boost::numeric::ublas::scalar_vector<double>\
					(hypothesis.size1()), hypothesis))\
						/ (2.0 * output_matrix.size1());
			cost_vector.push_back(cost);
			if(debug)
				std::cout << iteration << "th Iteration - Cost is: " << cost << "\n";
			delta_parameters = boost::numeric::ublas::zero_matrix\
				<double> (parameter_rows, parameter_columns);
			for(int input_row=0; input_row<input_rows; input_row++)
			{
				for(int parameter_row=0;\
					parameter_row<parameter_rows;\
					parameter_row++)
				{
					boost::numeric::ublas::matrix <double>\
						input_row_matrix, output_row_matrix;
					input_row_matrix = subrange(input_matrix,\
							input_row, input_row+1,\
							0, input_columns);
					output_row_matrix = subrange(output_matrix,\
							input_row, input_row+1,\
							0, output_columns);
					hypothesis_function(input_row_matrix,\
							parameters, hypothesis);
					delta_parameters(parameter_row, 0) +=\
						((hypothesis - output_row_matrix)\
						* input_matrix(input_row,\
							parameter_row))(0, 0);
				}
			}
			delta_parameters *= alpha;
			delta_parameters /= parameter_rows;
			parameters = parameters - delta_parameters;
		}
		hypothesis_function(input_matrix, parameters, hypothesis);
		assert(hypothesis.size1() == output_matrix.size1());
		assert(hypothesis.size2() == output_matrix.size2());
		hypothesis = output_matrix - hypothesis; // Error
		hypothesis = prod(trans(hypothesis), hypothesis); // Square Error
		// Mean Square Error
		double cost =\
			boost::numeric::ublas::sum(boost::numeric::ublas::prec_prod(
				boost::numeric::ublas::scalar_vector<double>\
				(hypothesis.size1()), hypothesis))\
					/ (2.0 * output_matrix.size1());
		cost_vector.push_back(cost);
		return cost_vector;
	}
}
