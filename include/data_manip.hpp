#ifndef _DATA_MANIP_

#define _DATA_MANIP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "data_t.hpp"

namespace vzlearn
{
	namespace data_manip
	{
		int check_data_type(const std::string& s);
		void conform_to_datatype(const boost::numeric::ublas::vector\
				<std::string>& separated_strings,\
				boost::numeric::ublas::vector <data_t>& data_row);
		boost::numeric::ublas::matrix <data_t> get_data_from_csv(\
				const std::string& filepath,\
				const bool& ignore_first_line);
		void one_hot_encode(boost::numeric::ublas::matrix <data_t> &data_matrix,\
				int column_no,\
				int threshold=0);
		void split_at_char(boost::numeric::ublas::vector <std::string>\
				&separated_strings, const std::string& line, char& c)
		void print_head(const boost::numeric::ublas::matrix <data_t>& data_matrix);
	}
}

#endif
