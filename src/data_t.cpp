#include "data_t.hpp"

namespace vz_learn
{
	namespace data_manip
	{
		data_t::data_t()
		{
			/* ********************
			 * Default Constructor
			 * *******************/
			n = 0;
			s = "";
			d = 0;
			c = '\0';
			p = NULL;
			data_type = UN_T;
		}

		data_t::data_t(const int x)
			: data_t((long long int)x)
		{
		}

		data_t::data_t(const long int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const short int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const long long int x)
			: data_t((double)x)
		{
		}

		data_t::data_t(const unsigned int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned long int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned short int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned long long int x)
			: data_t((long long int)x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const char c_s[])
			: data_t()
		{
			std::string s = c_s;
			this->s = s;
			this->data_type = ST_T;
		}

		data_t::data_t(const std::string s)
			: data_t()
		{
			this->s = s;
			this->data_type = ST_T;
		}

		data_t::data_t(const char c)
			:data_t()
		{
			this->c = c;
			this->data_type = CH_T;
		}

		data_t::data_t(const double d)
			: data_t()
		{
			this->d = d;
			this->data_type = DB_T;
		}

		data_t::data_t(const void *p)
			: data_t()
		{
			this->p = (void *)p;
			this->data_type = VD_T;
		}

		void data_t::operator=(const data_t& class_obj)
		{
			/*
			 * Operator Overloading =
			 */
			switch(class_obj.data_type)
			{
				case LL_T:
				{
					this->n = class_obj.n;
					break;
				}
				case ST_T:
				{
					this->s = class_obj.s;
					break;
				}
				case DB_T:
				{
					this->d = class_obj.d;
					break;
				}
				case CH_T:
				{
					this->c = class_obj.c;
					break;
				}
				case VD_T:
				{
					this->p = class_obj.p;
					break;
				}
				case UN_T:
				default:
				{
					std::cerr << "This operation cannot be performed\
						on this data type" << std::endl;
					abort();
				}
			};
		}

		data_t data_t::operator+(const data_t& class_obj)
		{
			/*
			 * Operator Overloading +
			 */
			if(this->data_type != class_obj.data_type)
			{
				std::cerr << "Data Types do not match" << std::endl;
				abort();
			}
			switch(this->data_type)
			{
				case LL_T:
				{
					return data_t((long long)(this->n + class_obj.n));
				}
				case ST_T:
				{
					return data_t((std::string)(this->s + class_obj.s));
				}
				case DB_T:
				{
					return data_t((double)(this->d + class_obj.d));
				}
				case UN_T:
				case CH_T:
				case VD_T:
				default:
				{
					std::cerr << "This operation cannot be performed\
						on this data type" << std::endl;
					abort();
				}
			};
		}

		data_t data_t::operator-(const data_t& class_obj)
		{
			/*
			 * Operator Overloading -
			 */
			if(this->data_type != class_obj.data_type)
			{
				std::cerr << "Data Types do not match" << std::endl;
				abort();
			}
			switch(this->data_type)
			{
				case LL_T:
				{
					return data_t(this->n - class_obj.n);
				}
				case DB_T:
				{
					return data_t(this->d - class_obj.d);
				}
				case ST_T:
				case UN_T:
				case CH_T:
				case VD_T:
				default:
				{
					std::cerr << "This operation cannot be performed\
						on this data type" << std::endl;
					abort();
				}
			};
		}


		data_t data_t::operator*(const data_t& class_obj)
		{
			/*
			 * Operator Overloading *
			 */
			if(this->data_type != class_obj.data_type)
			{
				std::cerr << "Data Types do not match" << std::endl;
				abort();
			}
			switch(this->data_type)
			{
				case LL_T:
				{
					return data_t(this->n * class_obj.n);
				}
				case DB_T:
				{
					return data_t(this->d * class_obj.d);
				}
				case ST_T:
				case UN_T:
				case CH_T:
				case VD_T:
				default:
				{
					std::cerr << "This operation cannot be performed\
						on this data type" << std::endl;
					abort();
				}
			};
		}

		data_t data_t::operator/(const data_t& class_obj)
		{
			/*
			 * Operator Overloading /
			 */
			if(this->data_type != class_obj.data_type)
			{
				std::cerr << "Data Types do not match" << std::endl;
				abort();
			}
			switch(this->data_type)
			{
				case LL_T:
				{
					return data_t(this->n / class_obj.n);
				}
				case DB_T:
				{
					return data_t(this->d / class_obj.d);
				}
				case UN_T:
				case CH_T:
				case VD_T:
				case ST_T:
				default:
				{
					std::cerr << "This operation cannot be performed\
						on this data type" << std::endl;
					abort();
				}
			};
		}

		bool data_t::operator==(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d == class_obj.d;
				}
				case ST_T:
				{
					return this->s == class_obj.s;
				}
				case CH_T:
				{
					return this->c == class_obj.c;
				}
				case VD_T:
				{
					return this->p ==  class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}

		bool data_t::operator!=(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d != class_obj.d;
				}
				case ST_T:
				{
					return this->s != class_obj.s;
				}
				case CH_T:
				{
					return this->c != class_obj.c;
				}
				case VD_T:
				{
					return this->p !=  class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}

		bool data_t::operator>(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d > class_obj.d;
				}
				case ST_T:
				{
					return this->s > class_obj.s;
				}
				case CH_T:
				{
					return this->c > class_obj.c;
				}
				case VD_T:
				{
					return this->p > class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}

		bool data_t::operator<(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d < class_obj.d;
				}
				case ST_T:
				{
					return this->s < class_obj.s;
				}
				case CH_T:
				{
					return this->c < class_obj.c;
				}
				case VD_T:
				{
					return this->p < class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}

		bool data_t::operator>=(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d >= class_obj.d;
				}
				case ST_T:
				{
					return this->s >= class_obj.s;
				}
				case CH_T:
				{
					return this->c >= class_obj.c;
				}
				case VD_T:
				{
					return this->p >= class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}


		bool data_t::operator<=(const data_t &class_obj)
		{
			/*
			 * Comparator Operator Overloading ==
			 */
			
			if(this->data_type != class_obj.data_type)
			{
				return false;
			}
			switch(this->data_type)
			{
				case LL_T:
				case DB_T:
				{
					return this->d <= class_obj.d;
				}
				case ST_T:
				{
					return this->s <= class_obj.s;
				}
				case CH_T:
				{
					return this->c <= class_obj.c;
				}
				case VD_T:
				{
					return this->p <= class_obj.p;
				}
				default:
				{
					return false;
				}
			}
		}

		void data_t::operator=(const int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const long int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}
		
		void data_t::operator=(const long long int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const short int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const unsigned int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const unsigned long int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}
		
		void data_t::operator=(const unsigned long long int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const unsigned short int& class_obj)
		{
			this->d = class_obj;
			this->data_type = DB_T;
		}

		void data_t::operator=(const std::string s)
		{
			this->s = s;
			this->data_type = ST_T;
		}

		void data_t::operator=(const char *c_s)
		{
			std::string s(c_s);
			this->s = s;
			this->data_type = ST_T;
		}

		void data_t::operator=(const char c)
		{
			this->c = c;
			this->data_type = CH_T;
		}

		void data_t::operator=(const double d)
		{
			this->d = d;
			this->data_type = DB_T;
		}

		void data_t::operator=(const void *p)
		{
			this->p = (void *) p;
			this->data_type = VD_T;
		}
		
		// Special Addition Operator Overloading  
		data_t data_t::operator+(const int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const short int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const long int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const long long int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const unsigned long long int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const unsigned long int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const unsigned short int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const unsigned int &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const double &x)
		{
			return *this + data_t(x);
		}
		data_t data_t::operator+(const std::string s)
		{
			return *this + data_t(s);
		}
		data_t data_t::operator+(const char *c_s)
		{
			return *this + data_t(c_s);
		}


		// Special Subtraction Operator Overloading  
		data_t data_t::operator-(const int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const short int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const long int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const long long int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const unsigned long long int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const unsigned long int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const unsigned short int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const unsigned int &x)
		{
			return *this - data_t(x);
		}

		data_t data_t::operator-(const double &x)
		{
			return *this - data_t(x);
		}



		// Special Multiplication Operator Overloading  
		data_t data_t::operator*(const int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const short int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const long int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const long long int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const unsigned long long int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const unsigned long int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const unsigned short int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const unsigned int &x)
		{
			return *this * data_t(x);
		}

		data_t data_t::operator*(const double &x)
		{
			return *this * data_t(x);
		}

		// Special Division Operator Overloading  
		data_t data_t::operator/(const int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const short int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const long int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const long long int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const unsigned long long int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const unsigned long int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const unsigned short int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const unsigned int &x)
		{
			return *this / data_t(x);
		}

		data_t data_t::operator/(const double &x)
		{
			return *this / data_t(x);
		}

		bool data_t::operator==(const int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const short int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const long int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const long long int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const unsigned long long int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const unsigned long int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const unsigned short int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(const unsigned int &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(double &x)
		{
			return *this == data_t(x);
		}

		bool data_t::operator==(std::string &s)
		{
			return *this == data_t(s);
		}

		bool data_t::operator==(char *c_s)
		{
			return *this == data_t(c_s);
		}

		bool data_t::operator!=(const int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const short int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const long int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const long long int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const unsigned long long int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const unsigned long int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const unsigned short int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(const unsigned int &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(double &x)
		{
			return *this != data_t(x);
		}

		bool data_t::operator!=(std::string &s)
		{
			return *this != data_t(s);
		}

		bool data_t::operator!=(char *c_s)
		{
			return *this != data_t(c_s);
		}

		bool data_t::operator>(const int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const short int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const long int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const long long int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const unsigned long long int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const unsigned long int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const unsigned short int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(const unsigned int &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(double &x)
		{
			return *this > data_t(x);
		}

		bool data_t::operator>(std::string &s)
		{
			return *this > data_t(s);
		}

		bool data_t::operator>(char *c_s)
		{
			return *this > data_t(c_s);
		}

		bool data_t::operator<(const int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const short int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const long int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const long long int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const unsigned long long int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const unsigned long int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const unsigned short int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(const unsigned int &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(double &x)
		{
			return *this < data_t(x);
		}

		bool data_t::operator<(std::string &s)
		{
			return *this < data_t(s);
		}

		bool data_t::operator<(char *c_s)
		{
			return *this < data_t(c_s);
		}

		bool data_t::operator>=(const int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const short int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const long int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const long long int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const unsigned long long int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const unsigned long int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const unsigned short int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(const unsigned int &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(double &x)
		{
			return *this >= data_t(x);
		}

		bool data_t::operator>=(std::string &s)
		{
			return *this >= data_t(s);
		}

		bool data_t::operator>=(char *c_s)
		{
			return *this >= data_t(c_s);
		}
		bool data_t::operator<=(const int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const short int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const long int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const long long int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const unsigned long long int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const unsigned long int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const unsigned short int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(const unsigned int &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(double &x)
		{
			return *this <= data_t(x);
		}

		bool data_t::operator<=(std::string &s)
		{
			return *this <= data_t(s);
		}

		bool data_t::operator<=(char *c_s)
		{
			return *this <= data_t(c_s);
		}
	}
}

std::ostream & operator << (std::ostream &out, const vz_learn::data_manip::data_t &class_obj)
{
	switch(class_obj.data_type)
	{
		case vz_learn::data_manip::LL_T:
		{
			out << std::to_string(class_obj.n);
			break;
		}
		case vz_learn::data_manip::ST_T:
		{
			out << class_obj.s;
			break;
		}
		case vz_learn::data_manip::DB_T:
		{
			out << std::to_string(class_obj.d);
			break;
		}
		default:
		{
			out << "<Object of type data_t>";
		}
	}
	return out;
}
