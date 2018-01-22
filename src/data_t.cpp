#include <iostream>
#include <cstring>
#include <cstdlib>
#include "data_t.hpp"

namespace vz_learn
{
	namespace data_manip
	{
		data_t::U::U()
		{
			std::memset(this, 0, sizeof(U));
		}

		data_t::U::~U()
		{
		}

		data_t::data_t()
		{
			this->data.p = NULL;
			this->data_type = UN_T;
		}

		data_t::data_t(const int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const long int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const short int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const long long int x)
		{
			this->data.n = x;
			this->data_type = LL_T;
		}

		data_t::data_t(const unsigned int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned long int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned short int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const unsigned long long int x)
		{
			data_t((long long int)x);
		}

		data_t::data_t(const std::string s)
		{
			this->data.s = s;
			this->data_type = ST_T;
		}

		data_t::data_t(const char c)
		{
			this->data.c = c;
			this->data_type = CH_T;
		}

		data_t::data_t(const double d) 
		{
			this->data.d = d;
			this->data_type = DB_T;
		}

		data_t::data_t(const void *p) 
		{
			this->data.p = (void *)p;
			this->data_type = VD_T;
		}

		void data_t::operator=(const data_t& class_obj)
		{
			/*
			 * Operator Overloading =
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
					this->data.n = class_obj.data.n;
					break;
				}
				case ST_T:
				{
					this->data.s = class_obj.data.s;
					break;
				}
				case DB_T:
				{
					this->data.d = class_obj.data.d;
					break;
				}
				case CH_T:
				{
					this->data.c = class_obj.data.c;
					break;
				}
				case VD_T:
				{
					this->data.p = class_obj.data.p;
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

		void data_t::operator+(const data_t& class_obj)
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
					this->data.n = class_obj.data.n + this->data.n;
				}
				case ST_T:
				{
					this->data.s = class_obj.data.s + this->data.s;
					break;
				}
				case DB_T:
				{
					this->data.d = class_obj.data.d + this->data.d;
					break;
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

		void data_t::operator-(const data_t& class_obj)
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
					this->data.n = this->data.n - class_obj.data.n;
					break;
				}
				case DB_T:
				{
					this->data.d = this->data.d - class_obj.data.d;
					break;
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


		void data_t::operator*(const data_t& class_obj)
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
					this->data.n = class_obj.data.n * this->data.n;
					break;
				}
				case DB_T:
				{
					this->data.d = class_obj.data.d * this->data.d;
					break;
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

		void data_t::operator/(const data_t& class_obj)
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
					this->data.n = this->data.n / class_obj.data.n;
					break;
				}
				case DB_T:
				{
					this->data.d = this->data.d / class_obj.data.d;
					break;
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

		void data_t::operator=(const int& class_obj)
		{
			*this = (long long int)class_obj;
		}

		void data_t::operator=(const long int& class_obj)
		{
			*this = (long long int)class_obj;
		}
		
		void data_t::operator=(const long long int& class_obj)
		{
			data_t res(class_obj);
			*this = res;
		}

		void data_t::operator=(const short int& class_obj)
		{
			*this = (long long int)class_obj;
		}

		void data_t::operator=(const unsigned int& class_obj)
		{
			*this = (long long int)class_obj;
		}

		void data_t::operator=(const unsigned long int& class_obj)
		{
			*this = (long long int)class_obj;
		}
		
		void data_t::operator=(const unsigned long long int& class_obj)
		{
			*this = (long long int)class_obj;
		}

		void data_t::operator=(const unsigned short int& class_obj)
		{
			*this = (long long int)class_obj;
		}

		void data_t::operator=(const std::string s)
		{
			data_t res(s);
			*this = res;
		}

		void data_t::operator=(const char c)
		{
			data_t res(c);
			*this = res;
		}

		void data_t::operator=(const double d)
		{
			data_t res(d);
			*this = res;
		}

		void data_t::operator=(const void *p)
		{
			data_t res(p);
			*this = res;
		}
	}

}
