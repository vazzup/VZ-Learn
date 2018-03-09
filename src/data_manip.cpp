#include "data_manip.hpp"

namespace vz_learn
{
	namespace data_manip
	{
		void add_row_to_matrix(boost::numeric::ublas::vector <data_t>& data_row,
				boost::numeric::ublas::matrix <data_t>& data_matrix,
				int row_no)
		{
			int rows = data_matrix.size1();
			int columns = data_row.size();
			data_matrix.resize(rows + 1, columns);
			for(int i=0; i<columns; i++)
			{
				data_matrix(rows, i) = data_row(i);
			}
		}

		int check_data_type(std::string& s)
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
			if(numeric)
			{
				return DB_T;
			}
			else if(!numeric)
			{
				return ST_T;
			}
			return ST_T;
		}

		void conform_to_datatype(const boost::numeric::ublas::vector\
				<std::string> &separated_strings,\
				boost::numeric::ublas::vector <data_t> &data_row)
		{
			data_row.resize(separated_strings.size());
			for(int i=0; i < separated_strings.size(); i++)
			{
				int data_type = check_data_type(separated_strings(i));
				switch(data_type)
				{
					case LL_T:
					case DB_T:
					{
						data_t temp = stod(separated_strings(i));
						data_row(i) = temp;
						break;
					}
					case ST_T:
					{
						data_t temp = separated_strings(i);
						data_row(i) = temp;
						break;
					}
					default:
					{
						std::cerr << "Unknown Data Type" << std::endl;
						abort();
					}
				}
			}
		}

		void get_data_from_csv(boost::numeric::ublas::matrix <data_t> &data_matrix,
				const std::string& filepath,\
				const bool& ignore_first_line\
				)
		{
			int len = filepath.size();
			assert(filepath[len-3] == 'c' &&\
					filepath[len-2] == 's' &&\
					filepath[len-1] == 'v');
			std::ifstream infile;
			infile.open(filepath);
			if(infile.good())
			{
				std::string line;
				int row_no = 0;
				while(std::getline(infile, line))
				{
					boost::numeric::ublas::vector\
						<std::string> separated_strings;
					boost::numeric::ublas::vector\
						<data_t> data_row;
					split_at_char(separated_strings, line, ',');
					conform_to_datatype(separated_strings,\
							data_row);
					add_row_to_matrix(data_row,\
							data_matrix, row_no);
					++row_no;
				}
			}
			else
			{ 
				abort();
			}
		}

		void one_hot_encode(boost::numeric::ublas::matrix <data_t> &data_matrix,\
				int column_no,\
				int threshold)
		{
			int rows, columns;
			rows = data_matrix.size1();
			if(rows == 0) {
				std::cerr << "Matrix sent to OHE is empty" << std::endl;
				return;
			}
			columns = data_matrix.size2();
			switch(data_matrix(0, column_no).data_type)
			{
				case ST_T:
				{
					std::unordered_set <std::string> nominal_values;
					std::unordered_map <std::string, int> column_mapping;
					int ohe_column_no = column_no;
					for(int i=0; i<rows; i++)
					{
						std::string nominal_value =\
							data_matrix(i, column_no).s;
						if(nominal_values\
							.find(nominal_value)\
							== nominal_values.end())
						{
							nominal_values.insert(nominal_value);
							column_mapping[nominal_value] =\
								ohe_column_no;
							if(ohe_column_no == column_no)
							{
								ohe_column_no = columns;
							}
							else
							{
								ohe_column_no++;
							}
						}
						data_matrix(i, column_no) = 0;
					}
					data_matrix.resize(rows,\
						columns + nominal_values.size());
					for(int i=0; i<rows; i++)
					{
						std::string nominal_value=\
							data_matrix(i, column_no).s;
						for(int j=columns;\
							j<columns+nominal_values.size(); j++)
						{
							data_matrix(i, j) = 0;
						}
						data_matrix(i, column_mapping[nominal_value]) = 1;
					}
				}
				default:
				{
					std::cerr << "Cannot One Hot Encode this Data Type"\
						<< std::endl;
					abort();
				}
			}
		}

		void split_at_char(boost::numeric::ublas::vector <std::string>\
				&separated_strings, const std::string& line, char c)
		{
			/* ************************************
			 * Function to split the string at a particular char into
			 * multiple strings and return as vector
			 * ********************************/
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

		void print_head(boost::numeric::ublas::matrix <data_t>& data_matrix)
		{
			/* *************************************************
			 * Function to print the first 5 lines of the matrix
			 * ************************************************/
			for(int i=0; i<5; i++)
			{
				for(int j=0; j<data_matrix.size2(); j++)
				{
					std::cout << data_matrix(i, j) << " ";
				}
			}
			return;
		}
	}
}
