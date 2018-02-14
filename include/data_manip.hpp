#ifndef _DATA_MANIP_
#define _DATA_MANIP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "data_t.hpp"

namespace vzlearn
{
	namespace data_manip
	{
		void split_at_char(boost::numeric::ublas::vector <std::string>\
				&separated_strings, const std::string& line, char& c)
		boost::numeric::ublas::matrix <data_t> get_data_from_csv(\
				const std::string& filepath,\
				const bool& ignore_first_line);
	}
}
#endif
