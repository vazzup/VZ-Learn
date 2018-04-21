#include <iostream>

#include "data_manip.hpp"
#include "classifiers.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

int main()
{
	boost::numeric::ublas::matrix<double> input_matrix;
	std::string filepath = "../datasets/spambase.csv";
	vz_learn::data_manip::get_data_from_csv(input_matrix, filepath, false, true, false);
	int rows = input_matrix.size1(), columns = input_matrix.size2();
	input_matrix.resize(rows, 49, true);
	columns = input_matrix.size2();
	std::vector< std::vector<int> >  bins(columns);
	for(int column=1; column<columns; column++)
	{
		bins[column] = vz_learn::data_manip::discretize_feature(input_matrix, column);
	}
	std::vector< std::vector > rules = naive_bayes(input_matrix, 1);
	double prediction = predict(rules, predict_matrix);
	std::cout << "The prediction for the given input is " << prediction << "\n";
	return 0;
}
