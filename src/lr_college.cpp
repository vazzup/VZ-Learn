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
	/* ***************************************
	 * Program to predict price / sq. ft. of house based on
	 * size, bedrooms, bathrooms, and location
	 * Demonstrates use of normalization and all
	 * ******************************************/
	boost::numeric::ublas::matrix <double> X, theta, Y;
	boost::numeric::ublas::matrix <double> X_train, X_dev, X_test;
	boost::numeric::ublas::matrix <double> Y_train, Y_dev, Y_test;
	std::string filepath = "../datasets/lr_dataset.csv";
	vz_learn::data_manip::get_data_from_csv(X, filepath,\
			true, true, false);
	// Create output matrix
	Y = subrange(X, 0, X.size1(), (int)X.size2() - 1, X.size2());
	for(int column=2; column<(int)X.size2()- 1; column++)
	{
		// Normalize the columns
		vz_learn::data_manip::normalize_feature(X, column);
	}
	// Remove output column
	vz_learn::data_manip::remove_column_from_matrix(X, (int)X.size2() - 1);
	// Remove roll no
	vz_learn::data_manip::remove_column_from_matrix(X, 0);
	// Remove name
	vz_learn::data_manip::remove_column_from_matrix(X, 1);
	std::cout << "After cleaning data..\n";
	vz_learn::data_manip::print_head<double>(X);
	// Split into train, dev, and test
	vz_learn::data_manip::split_train_dev_test(X, Y, X_train, X_dev, X_test,\
							Y_train, Y_dev, Y_test);
	vz_learn::data_manip::print_head<double>(X_train);
	theta.resize(X_train.size2(), Y_train.size2());
	vz_learn::data_manip::random_initialization(theta);
	std::vector <double> cost;
	cost = vz_learn::algorithm::linear_regression(X_train, Y_train, theta,\
					hypothesis_function, 0.01, 10000, true);
	std::cout << "Initial Training Cost: " << cost[0] << "\n";
	std::cout << "Final Training Cost:" << cost[cost.size() - 1] << "\n";
	boost::numeric::ublas::matrix<double> hypothesis;
	hypothesis_function(X_dev, theta, hypothesis);
	hypothesis = Y_dev - hypothesis; // Error
	hypothesis = prod(trans(hypothesis), hypothesis); // Square Error
	// Mean Square Error
	double dev_cost =\
		boost::numeric::ublas::sum(boost::numeric::ublas::prec_prod(
			boost::numeric::ublas::scalar_vector<double>\
			(hypothesis.size1()), hypothesis))\
				/ (2.0 * Y_dev.size1());
	std::cout << "Dev Cost: " << dev_cost << "\n";
	hypothesis_function(X_test, theta, hypothesis);
	hypothesis = Y_test - hypothesis; // Error
	hypothesis = prod(trans(hypothesis), hypothesis); // Square Error
	// Mean Square Error
	double test_cost =\
		boost::numeric::ublas::sum(boost::numeric::ublas::prec_prod(
			boost::numeric::ublas::scalar_vector<double>\
			(hypothesis.size1()), hypothesis))\
				/ (2.0 * Y_test.size1());
	std::cout << "Test Cost: " << test_cost << "\n";
	return 0;
}
