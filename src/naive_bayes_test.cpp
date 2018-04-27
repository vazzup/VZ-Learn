#include <iostream>
#include <random>

#include "data_manip.hpp"
#include "naivebayes.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

int main()
{
	boost::numeric::ublas::matrix<double> input_matrix;
	std::string filepath="../datasets/spambase.csv";
	std::cout << "Reading from csv...\n";
	vz_learn::data_manip::get_data_from_csv(input_matrix,\
					filepath, false, true, false);
	std::cout << "Data loaded from CSV...\n";
	int rows=(int)input_matrix.size1(), columns=input_matrix.size2();
	std::vector <double> output_column;
	for(int row=0; row<rows; row++)
	{
		output_column.push_back(input_matrix(row, columns - 1));
	}
	columns = 48;
	input_matrix.resize(rows, columns, true);
	vz_learn::data_manip::add_column_to_matrix<double>(output_column, input_matrix, columns);
	vz_learn::data_manip::print_head<double>(input_matrix);
	std::cout << "Discretizing columns...\n";
	for(int column=0; column<columns; column++)
	{
		vz_learn::data_manip::discretize_feature(input_matrix, column);
	}
	std::cout << "Columns Discretized...\n";
	vz_learn::data_manip::print_head<double>(input_matrix);
	std::map<double, std::map<int, std::map<double, double> > > rules;
	std::cout << "Learning from data...\n";
	vz_learn::algorithm::naive_bayes(input_matrix, rules, columns);
	std::cout << "Rules Learnt...\n";
	double correct_predictions = 0;
	for(int row=0; row<rows; row++)
	{
		std::map<int, double> input_row;
		for(int column=1; column<columns; column++)
		{
			input_row[column] = input_matrix(row, column);
		}
		double prediction =\
			vz_learn::algorithm::bayesian_predict(input_row, rules);
		if(prediction == input_matrix(row, columns))
			correct_predictions++;
	}
	std::cout << "Accuracy of prediction is " <<\
			correct_predictions / rows << std::endl;
	std::random_device non_deterministic_generator;
	std::mt19937 generator(non_deterministic_generator());
	std::uniform_int_distribution<int> distribution(0, rows);
	std::cout << "Expected Classification | Actual Outcome" << std::endl;
	for(int i=0; i<10; i++)
	{
		int row = distribution(generator);
		std::map<int, double> input_row;
		for(int column=1; column<columns; column++)
		{
			input_row[column] = input_matrix(row, column);
		}
		double prediction =\
			vz_learn::algorithm::bayesian_predict(input_row, rules);
		std::cout << input_matrix(row, columns) << " | " << prediction << std::endl;
	}
	return 0;
}
