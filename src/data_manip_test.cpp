#include "data_manip.hpp"
#include <cassert>
#include <iostream>
#include <string>

#include <boost/numeric/ublas/matrix_proxy.hpp>
int main()
{
	boost::numeric::ublas::matrix <double> data_matrix, X_train, X_dev, X_test;
	vz_learn::data_manip::get_data_from_csv(data_matrix,\
		std::string("../datasets/RealEstate.csv"), true, true, false);
	int rows = data_matrix.size1();
	int columns = data_matrix.size2();
	std::cout << "After reading from csv...\n";
	vz_learn::data_manip::print_head<double>(data_matrix);
	std::cout << "Splitting into train, test, dev...\n";
	vz_learn::data_manip::split_train_dev_test(data_matrix, X_train, X_dev, X_test);
	std::cout << "The split matrices are...\nTrain:-\n";
	vz_learn::data_manip::print_head<double>(X_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(X_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(X_test);
	boost::numeric::ublas::matrix <double> Y_train = subrange(X_train, 0, X_train.size1(), X_train.size2() - 1, X_train.size2());
	boost::numeric::ublas::matrix <double> Y_dev = subrange(X_dev, 0, X_dev.size1(), X_dev.size2() - 1, X_dev.size2());
	boost::numeric::ublas::matrix <double> Y_test= subrange(X_test, 0, X_test.size1(), X_test.size2() - 1, X_test.size2());
	std::cout << "The output matrices are...\nTrain\n";
	vz_learn::data_manip::print_head<double>(Y_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(Y_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(Y_test);
	data_matrix = subrange(data_matrix, 0, data_matrix.size1(), 0, data_matrix.size2() - 1);
	std::cout << "The input matrix without OP is...\nTrain\n";
	vz_learn::data_manip::print_head<double>(X_train);
	std::cout << "Dev:-\n";
	vz_learn::data_manip::print_head<double>(X_dev);
	std::cout << "Test:-\n";
	vz_learn::data_manip::print_head<double>(X_test);
	vz_learn::data_manip::normalize_feature(X_train, 2);
	std::cout << "The input matrix after normalization of column 2 is...\n";
	vz_learn::data_manip::print_head<double>(X_train);
	return 0;
}
