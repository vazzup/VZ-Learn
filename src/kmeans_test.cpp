#include <cmath>
#include <iostream>
#include <vector>

#include "data_manip.hpp"
#include "kmeans.hpp"

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

double distance_function(const std::vector <double>& row_one,\
				const std::vector<double>& row_two)
{
	double dist = 0;
	int size = (int)row_one.size();
	assert(row_one.size() == row_two.size());
	for(int i=0; i<size; i++)
	{
		dist += pow(row_one[i] - row_two[i], 2);
	}
	// Avoiding square root as this distance is only
	// used for comparison and sq. root doesn't effect that
	// Also, sq. root leads to precision loss in doubles
	return dist;
}

int main()
{
	boost::numeric::ublas::matrix <double> input_matrix;
	std::string filepath = "../datasets/knn_Wholesale_customers_data.csv";
	vz_learn::data_manip::get_data_from_csv(input_matrix, filepath,\
							true, true, false);
	vz_learn::data_manip::print_head<double>(input_matrix);
	int rows = (int)input_matrix.size1(), columns = (int)input_matrix.size2();
	for(int column=2; column<columns; column++)
	{
		vz_learn::data_manip::normalize_feature(input_matrix, column);
	}
	for(int column=0; column<2; column++)
	{
		vz_learn::data_manip::one_hot_encode(input_matrix, column);
	}
	vz_learn::data_manip::print_head<double>(input_matrix);
	std::vector<std::vector<double> > clusters;
	vz_learn::algorithm::kmeans(input_matrix, distance_function, clusters, 4, true);
}
