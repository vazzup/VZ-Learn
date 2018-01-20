#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "data_manip.hpp"

namespace data_manip
{
	struct data_t& struct data_t::operator+(const struct data_t& class_obj)
	{
		data_t res;
		if(this->data_type != class_obj.data_type)
		{
			std::cerr << "Data Types do not match" << endl;
			abort();
		}
		res.data_type = this->data_type;
		switch(this->data_type)
		{
			case _DM_LL_T:
			{
				res.n = class_obj.n + this->n;
			}
			case _DM_ST_T:
			{
				res.s = class_obj.s + this->s;
				break;
			}
			case _DM_DB_T:
			{
				res.d = class_obj.d + this->d;
				break;
			}
			case _DM_UN_T:
			case _DM_CH_T:
			case _DM_VD_T:
			default:
			{
				std::cerr << "This operation cannot be performed\
					on this data type" << endl;
				abort();
			}
		};
		return res;
	}

	struct data_t& struct data_t::operator-(const struct data_t& class_obj)
	{
		data_t res;
		if(this->data_type != class_obj.data_type)
		{
			std::cerr << "Data Types do not match" << endl;
			abort();
		}
		res.data_type = this->data_type;
		switch(this->data_type)
		{
			case _DM_LL_T:
			{
				res.n = this->n - class_obj.n;
				break;
			}
			case _DM_DB_T:
			{
				res.d = this->d - class_obj.d;
				break;
			}
			case _DM_ST_T:
			case _DM_UN_T:
			case _DM_CH_T:
			case _DM_VD_T:
			default:
			{
				std::cerr << "This operation cannot be performed\
					on this data type" << endl;
				abort();
			}
		};
		return res;
	}


	struct data_t& struct data_t::operator+(const struct data_t& class_obj)
	{
		data_t res;
		if(this->data_type != class_obj.data_type)
		{
			std::cerr << "Data Types do not match" << endl;
			abort();
		}
		res.data_type = this->data_type;
		switch(this->data_type)
		{
			case _DM_LL_T:
			{
				res.n = class_obj.n + this->n;
			}
			case _DM_ST_T:
			{
				res.s = class_obj.s + this->s;
				break;
			}
			case _DM_DB_T:
			{
				res.d = class_obj.d + this->d;
				break;
			}
			case _DM_UN_T:
			case _DM_CH_T:
			case _DM_VD_T:
			default:
			{
				std::cerr << "This operation cannot be performed\
					on this data type" << endl;
				abort();
			}
		};
		return res;
	}

	struct data_t& struct data_t::operator+(const struct data_t& class_obj)
	{
		data_t res;
		if(this->data_type != class_obj.data_type)
		{
			std::cerr << "Data Types do not match" << endl;
			abort();
		}
		res.data_type = this->data_type;
		switch(this->data_type)
		{
			case _DM_LL_T:
			{
				res.n = class_obj.n + this->n;
			}
			case _DM_ST_T:
			{
				res.s = class_obj.s + this->s;
				break;
			}
			case _DM_DB_T:
			{
				res.d = class_obj.d + this->d;
				break;
			}
			case _DM_UN_T:
			case _DM_CH_T:
			case _DM_VD_T:
			default:
			{
				std::cerr << "This operation cannot be performed\
					on this data type" << endl;
				abort();
			}
		};
		return res;
	}

	boost::numeric::ublas::matrix <data_t> get_data_from_csv(const string& filepath, const bool& ignore_first_line)
	{
		int len = filepath.size();
		std::assert(filepath[len-3] == 'c' && filepath[len-2] && filepath[len-1]);
		std::ifstream infile;
		infile.open(filepath);
		
		return NULL;
	}

	boost::numeric::ublas::vector <string> split_at_char(const string& line, char& c)
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
				separated_strings.insert_element(separated_strings.size(), s);
				s = "";
			}
			just_inserted = true;
		}
		if(!just_inserted)
		{
			separated_strings.insert_element(seperated_strings.size(), s);
		}
		return separated_strings;
	}
}
