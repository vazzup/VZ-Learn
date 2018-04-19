#include "linear_regression.hpp"
#include "data_manip.hpp"

#include <cstdio>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

void hypothesis_function(boost::numeric::ublas::matrix <double>& input_matrix,\
	boost::numeric::ublas::matrix <double>& parameters,\
	boost::numeric::ublas::matrix <double>& hypothesis)
{
	assert(input_matrix.size2() == parameters.size1());
	hypothesis = prod(input_matrix, parameters);
}

int main()
{
	boost::numeric::ublas::matrix <double> X, theta, Y;
	boost::numeric::ublas::matrix <double> X_train, X_dev, X_test;
	boost::numeric::ublas::matrix <double> Y_train, Y_dev, Y_test;
	std::string filepath = "../datasets/RealEstate.csv";
	vz_learn::data_manip::get_data_from_csv(X, filepath,\
			true, true, false);
	// Create output matrix
	Y = subrange(X, 0, X.size1(), 2, 3);
	// Normalize the size feature
	vz_learn::data_manip::normalize_feature(X, 5);
	// Remove Status
	vz_learn::data_manip::remove_column_from_matrix(X, 7);
	// Remove price/sq.ft
	vz_learn::data_manip::remove_column_from_matrix(X, 6);
	// Remove output column
	vz_learn::data_manip::remove_column_from_matrix(X, 2);
	// Replace Listing ID with 1s for theta_0 (bias value)
	for(int row=0; row<(int)X.size1(); row++)
	{
		X(row, 0) = 1;
	}
	// One Hot encode Location
	vz_learn::data_manip::one_hot_encode(X, 1);
	vz_learn::data_manip::print_head<double>(X);
	// Split into train, dev, and test
	vz_learn::data_manip::split_train_dev_test(X, Y, X_train, X_dev, X_test,\
							Y_train, Y_dev, Y_test);
	vz_learn::data_manip::print_head<double>(X_train);
	theta.resize(X_train.size2(), Y_train.size2());
	vz_learn::data_manip::random_initialization(theta);
	std::vector <double> cost;
	cost = vz_learn::algorithm::linear_regression(X_train, Y_train, theta,\
					hypothesis_function, 0.006, 10000, false);
	std::cout << "Initial Cost: " << cost[0] << "\n";
	std::cout << "Final Cost:" << cost[cost.size() - 1] << "\n";
	return 0;
}
