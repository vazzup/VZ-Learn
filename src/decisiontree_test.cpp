#include <iostream>
#include <set>
#include <vector>

#include "decisiontree.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

int main()
{
	boost::numeric::ublas::matrix <double> X;
	std::string filepath="../datasets/titanic.csv";
	vz_learn::data_manip::get_data_from_csv(X, filepath, true, true, false);
	vz_learn::data_manip::print_head<double>(X);
	// Discretize age
	vz_learn::data_manip::discretize_feature(X, 4);
	// Discretize age
	vz_learn::data_manip::discretize_feature(X, 7);
	vz_learn::data_manip::remove_column_from_matrix<double>(X, 2);
	vz_learn::algorithm::dtreenode root;
	std::unordered_set<int> used_columns;
	vz_learn::algorithm::create_decision_tree(X, used_columns, root, 0);
	int rows = (int) X.size1(), columns = (int) X.size2();
	int tp = 0, fp = 0, tn = 0, fn = 0;
	for(int row=0; row<rows; row++)
	{
		std::vector <double> test;
		for(int column=0; column<columns; column++)
		{
			test.push_back(X(row, column));
		}
		double prediction = predict_dtree(root, test);
		if(prediction == X(row, 0) && prediction == 1)
		{
			tp++;
		}
		else if(prediction == X(row, 0) && prediction == 0)
		{
			tn++;
		}
		else if(prediction != X(row, 0) && prediction == 0)
		{
			fn++;
		}
		else if(prediction != X(row, 0) && prediction == 1)
		{
			fp++;
		}
	}
	std::cout  << "True Positives: " << tp << "\n";
	std::cout  << "False Positives: " << fp << "\n";
	std::cout  << "True Negatives: " << tn << "\n";
	std::cout  << "False Negatives: " << fn << "\n";
	return 0;
}
