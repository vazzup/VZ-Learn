#include "data_manip.hpp"

namespace vzlearn
{
	namespace data_manip
	{
		void split_at_char(boost::numeric::ublas::vector <std::string>\
				&separated_strings, const std::string& line, char& c)
		{
			std::string s = "";
			int sz = (int)line.size();
			bool just_inserted;
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
						separated_strings.size(), s);
			}
		}

		void get_data_from_csv(boost::ublas::numeric::matrix <data_t> &data_matrix
				const std::string& filepath,\
				const bool& ignore_first_line\
				)
		{
			int len = filepath.size();
			std::assert(filepath[len-3] == 'c' &&\
					filepath[len-2] == 's' &&\
					filepath[len-1] == 'v');
			std::ifstream infile;
			infile.open(filepath);
			if(infile.good())
			{
				std::string line;
				int row_no = 0;
				while(std::getline(file, line))
				{
					boost::numeric::ublas::vector\
						<std::string> separated_strings;
					split_at_char(separated_strings, line, ',');
					boost::numeric::ublas::vector\
						<data_t> data_row;
					conform_to_datatype(separated_strings,\
							data_row);
					add_row_to_matrix(data_row,\
							data_matrix, row_no);
					++row_no;
				}
			}
			else
			{ 
				exit(255);
			}
			return NULL;
		}

		int check_data_type(std::string s)
		{
			int len = s.size();
			if(len == 0)
			{
				return UN_T;
			}
			bool numeric = true, point = false;
			for(int i=0; i<len; i++)
			{
				if (s[i] == '.')
				{
					point = true;
				}
				else if(s[i] > '9' || s[i] < '0')
				{
					numeric = false;
				} 
			}
			if(numeric && point)
			{
				return DB_T;
			}
			else if(numeric && !point)
			{
				return LL_T;
			}
			else if(!numeric)
			{
				return ST_T;
			}
			return ST_T;
		}

	}
}
