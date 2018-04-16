#ifndef _DATA_MANIP_

#define _DATA_MANIP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <exception>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace vz_learn::data_manip
{
	const int DB_T = 0;
	const int ST_T = 1;

	void _trim_string(std::string& line);
	void add_row_to_matrix(const std::vector <std::string>& separated_strings,
		boost::numeric::ublas::matrix <std::string>& data_matrix,
		const int row_no);
	int check_data_type(const char* s);
	int check_data_type(const std::string& s);
	void convert_to_doubles(const boost::numeric::ublas::matrix\
		<std::string> &data_matrix_s,
		boost::numeric::ublas::matrix <double>& data_matrix,
		const bool OHE=false);
	void get_data_from_csv(boost::numeric::ublas::matrix <double>& data_matrix,
		const std::string& filepath,\
		bool ignore_first_line=false, bool clean_dataset=false,\
		const std::vector<int>& ignored_columns=std::vector<int>());
	void normalize_feature(boost::numeric::ublas::matrix <double>& data_matrix,\
		const int column_no);
	void one_hot_encode(boost::numeric::ublas::matrix <double>& data_matrix,\
		int column_no,\
		int threshold=0);
	void print_head(const boost::numeric::ublas::matrix <double>& data_matrix);
	void print_head(const boost::numeric::ublas::matrix <std::string>& data_matrix);
}

#endif
