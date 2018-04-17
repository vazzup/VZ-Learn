#ifndef _DATA_MANIP_

#define _DATA_MANIP_

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace vz_learn::data_manip
{
	const int DB_T = 0;
	const int ST_T = 1;
	const double EPS = 0.01;
	const int RAND_LIM = 10000;

	void trim_string(std::string& line);
	int check_data_type(const char* s);
	int check_data_type(const std::string& s);
	void convert_to_doubles(const boost::numeric::ublas::matrix\
		<std::string> &data_matrix_s,
		boost::numeric::ublas::matrix <double>& data_matrix,
		const bool OHE=false);
	void get_data_from_csv(boost::numeric::ublas::matrix <double>& data_matrix,
		const std::string& filepath, bool ignore_first_line=false,\
		bool clean_dataset=false, const bool OHE=false);
	void normalize_feature(boost::numeric::ublas::matrix <double>& data_matrix,\
		const int column_no);
	void one_hot_encode(boost::numeric::ublas::matrix <double>& data_matrix,\
		int column_no,\
		int threshold=0);
	void split_train_dev_test(const boost::numeric::ublas::matrix <double>& data_matrix,\
			boost::numeric::ublas::matrix <double>& data_matrix_train,\
			boost::numeric::ublas::matrix <double>& data_matrix_dev,\
			boost::numeric::ublas::matrix <double>& data_matrix_test,\
			const double train_ratio=0.6, const double dev_ratio=0.2);

	template <class T>
	void add_row_to_matrix(const std::vector <T>& data_row,
		boost::numeric::ublas::matrix <T>& data_matrix,
		const int row_no)
	{
		/* **************************************
		 * Function to Add Row to Matrix
		 * *************************************/
		int rows = data_matrix.size1();
		int columns = data_row.size();
		data_matrix.resize(rows + 1, columns, true); // Add new row to matrix
		for(int column=0; column<columns; column++)
		{
			// Copy all elements into matrix row
			data_matrix(rows, column) = data_row[column];
		}
	}

	template <class T>
	void print_head(const boost::numeric::ublas::matrix <T>& data_matrix)
	{
		/* *************************************************
		 * Function to print the first 5 lines of the matrix
		 * ************************************************/
		int rows = data_matrix.size1(), columns = data_matrix.size2();
		for(int i=0; i<std::min(rows, 5); i++)
		{
			for(int j=0; j<columns; j++)
			{
				std::cout << data_matrix(i, j) << " ";
			}
			std::cout << "\n";
		}
		return;
	}
}

#endif
