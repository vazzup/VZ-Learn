#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "data_manip.hpp"
#include "data_t.hpp"

namespace vzlearn
{
	namespace data_manip
	{
		boost::numeric::ublas::vector <std::string> split_at_char(\
				const std::string& line, char& c)
		{
			vector <string> separated_strings;
			string s = "";
			int sz = (int)line.size();
			bool just_inserteda;
			for(int i=0; i<sz; i++)
			{
				just_inserted = false;
				if(line[i] == c)
				{
					separated_strings.insert_element(\
							separated_strings.size(), s);
					s = "";
				}
				just_inserted = true;
			}
			if(!just_inserted)
			{
				separated_strings.insert_element(
						seperated_strings.size(), s);
			}
			return separated_strings;
		}

		boost::numeric::ublas::matrix <data_t> get_data_from_csv(\
				const std::string& filepath,\
				const bool& ignore_first_line)
		{
			int len = filepath.size();
			std::assert(filepath[len-3] == 'c' &&\
					filepath[len-2] == 's' &&\
					filepath[len-1] == 'v');
			std::ifstream infile;
			infile.open(filepath);
			
			return NULL;
		}

	}
}
