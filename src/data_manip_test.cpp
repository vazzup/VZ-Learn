#include "data_manip.hpp"
#include <cassert>
#include <iostream>
#include <string>

#include <boost/numeric/ublas/matrix_proxy.hpp>

int main()
{
	boost::numeric::ublas::matrix <double> X, X_train, X_dev, X_test;
	boost::numeric::ublas::matrix <double> Y, Y_train, Y_dev, Y_test;
	vz_learn::data_manip::get_data_from_csv(X,\
		std::string("../datasets/RealEstate.csv"), true, true, false);
	int rows = X.size1();
	int columns = X.size2();
	std::cout << "After reading from csv...\n";
	vz_learn::data_manip::print_head<double>(X);
	Y = subrange(X, 0, X.size1(), 6, 7);
	std::cout << "Splitting into train, test, dev...\n";
	vz_learn::data_manip::split_train_dev_test(X, Y, X_train, X_dev, X_test,\
							Y_train, Y_dev, Y_test);
	std::cout << "The split matrices are...\nTrain:-\n";
	vz_learn::data_manip::print_head<double>(X_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(X_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(X_test);
	std::cout << "The output matrices are...\nTrain\n";
	vz_learn::data_manip::print_head<double>(Y_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(Y_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(Y_test);
	std::cout << "The input matrix without OP is...\nTrain\n";
	vz_learn::data_manip::print_head<double>(X_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(X_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(X_test);
	vz_learn::data_manip::normalize_feature(X_train, 2);
	std::cout << "The input matrix after normalization of column 2 is...\n";
	vz_learn::data_manip::print_head<double>(X_train);
	std::cout << "Testing Random initialization...\n";
	vz_learn::data_manip::random_initialization(X_dev);
	vz_learn::data_manip::print_head<double>(X_dev);
	std::cout << "Testing Copy Matrix...\n";
	vz_learn::data_manip::copy_matrix<double>(X_dev, X_test);
	vz_learn::data_manip::print_head<double>(X_test);
	X_dev(0, 0) = 1.5;
	std::cout << X_dev(0, 0) << " " << X_test(0, 0) << "\n";
	std::cout << "Testing Remove Column...\n";
	vz_learn::data_manip::remove_column_from_matrix<double>(X, 0);
	vz_learn::data_manip::print_head<double>(X);
	std::cout << "Testing Column Discretization...\n";
	vz_learn::data_manip::print_head<double>(Y);
	std::vector bins = vz_learn::data_manip::discretize_feature(Y, 0);
	for(auto bin:bins)
	{
		std::cout << bin << " ";
	}
	std::cout << "\n";
	vz_learn::data_manip::print_head<double>(Y);
	return 0;
}
