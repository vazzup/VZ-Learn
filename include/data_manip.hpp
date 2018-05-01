#ifndef _VZ_DATA_MANIP_

#define _VZ_DATA_MANIP_

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
#include <random>
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

	int check_data_type(const char* s);
	int check_data_type(const std::string& s);
	void convert_to_doubles(const boost::numeric::ublas::matrix\
		<std::string> &data_matrix_s,
		boost::numeric::ublas::matrix <double>& data_matrix,
		const bool OHE=false);
	std::vector<double> discretize_feature(boost::numeric::ublas::matrix <double>& data_matrix,\
		const int column, const int bins=10);
	void get_data_from_csv(boost::numeric::ublas::matrix <double>& data_matrix,
		const std::string& filepath, bool ignore_first_line=false,\
		const bool clean_dataset=false, const bool OHE=false);
	void normalize_feature(boost::numeric::ublas::matrix <double>& data_matrix,\
		const int column_no);
	void one_hot_encode(boost::numeric::ublas::matrix <double>& data_matrix,\
		int column_no);
	void random_initialization(boost::numeric::ublas::matrix <double>& data_matrix);
	void split_train_dev_test(const boost::numeric::ublas::matrix <double>& X,\
		boost::numeric::ublas::matrix <double>& Y,\
		boost::numeric::ublas::matrix <double>& X_train,\
		boost::numeric::ublas::matrix <double>& X_dev,\
		boost::numeric::ublas::matrix <double>& X_test,\
		boost::numeric::ublas::matrix <double>& Y_train,\
		boost::numeric::ublas::matrix <double>& Y_dev,\
		boost::numeric::ublas::matrix <double>& Y_test,\
		const double train_ratio=0.6, const double dev_ratio=0.2);
	void SVD(const boost::numeric::ublas::matrix <double>& data_matrix,\
		boost::numeric::ublas::matrix <double>& U,\
		boost::numeric::ublas::matrix <double>& S,\
		boost::numeric::ublas::matrix <double>& V);
	void trim_string(std::string& line);

	template <class T>
	void add_column_to_matrix(const std::vector <T>& data_column,
		boost::numeric::ublas::matrix <T>& data_matrix,
		const int column_no)
	{
		/* **************************************
		 * Function to Add Row to Matrix
		 * *************************************/
		int rows = data_matrix.size1();
		int columns = data_matrix.size2();
		data_matrix.resize(rows, columns + 1, true); // Add new row to matrix
		for(int row=0; row<rows; row++)
		{
			// Copy all elements into matrix row
			data_matrix(row, columns) = data_column[row];
		}
	}


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

	template<class T>
	void remove_column_from_matrix(boost::numeric::ublas::matrix <T>& data_matrix,\
		const int column)
	{
		int rows = data_matrix.size1(), columns = data_matrix.size2();
		if(column != columns - 1)
		{
			for(int row=0; row<rows; row++)
			{
				data_matrix(row, column) = data_matrix(row, columns - 1);
			}
		}
		data_matrix.resize(rows, columns - 1, true);
	}

	template <class T>
	void copy_matrix(const boost::numeric::ublas::matrix <T>& from,
		boost::numeric::ublas::matrix <T>& to)
	{
		int rows = from.size1(), columns = from.size2();
		to.resize(rows, columns);
		for(int row=0; row<rows; row++)
		{
			for(int column=0; column<columns; column++)
			{
				to(row, column) = from(row, column);
			}
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
