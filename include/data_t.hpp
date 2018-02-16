#ifndef _DATA_T_
#define _DATA_T_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

namespace vz_learn
{
	namespace data_manip
	{
		const int UN_T =  -1; // Undefined Type
		const int LL_T = 0; // Long Long Int
		const int ST_T = 1; // String Type
		const int DB_T = 2; // Double Type
		const int CH_T = 3; // Character Type
		const int VD_T = 4; // Void Pointer Type
		class data_t
		{
			/* **********************
			 * DESCRIPTION
			 * **********************
			 * Struct which holds the data and remembers the data type
			 * **********************
			 * MEMBERS
			 * **********************
			 * data - union to store whatever the information is
			 * 		stores only in one format at a time
			 * data_type - stores data type number as defined in MACROS
			 * **********************
			 * FUNCTIONS
			 * **********************
			 * operator overloading functions, nothing more
			 */
			public:

			// Members of the class
			long long int n;
			std::string s;
			double d;
			char c;
			void *p;
			
			int data_type; // Tells the data type

			// Constructors
			data_t();
			data_t(const int x);
			data_t(const long int x);
			data_t(const long long int x);
			data_t(const short int x);
			data_t(const unsigned int x);
			data_t(const unsigned long int x);
			data_t(const unsigned long long int x);
			data_t(const unsigned short int x);
			data_t(const char c_s[]);
			data_t(const std::string s);
			data_t(const char c);
			data_t(const double d);
			data_t(const void *p);
			data_t(const data_t&);

			// Basic Operator Overloading
			void operator=(const struct data_t& class_obj);
			data_t operator+(const struct data_t& class_obj);
			data_t operator-(const struct data_t& class_obj);
			data_t operator*(const struct data_t& class_obj);
			data_t operator/(const struct data_t& class_obj);
			bool operator==(const struct data_t& class_obj);
			bool operator!=(const struct data_t& class_obj);
			bool operator>(const struct data_t& class_obj);
			bool operator<(const struct data_t& class_obj);
			bool operator>=(const struct data_t& class_obj);
			bool operator<=(const struct data_t& class_obj);

			// Assignment Operator Special Overloading
			void operator=(const int& class_obj);
			void operator=(const long int& class_obj);
			void operator=(const long long int& class_obj);
			void operator=(const short int& class_obj);
			void operator=(const unsigned int& class_obj);
			void operator=(const unsigned long int& class_obj);
			void operator=(const unsigned long long int& class_obj);
			void operator=(const unsigned short int& class_obj);
			void operator=(const std::string s);
			void operator=(const char *c_s);
			void operator=(const char c);
			void operator=(const double d);
			void operator=(const void *p);

			// Special Addition Operator Overloading  
			data_t operator+(const int &x);
			data_t operator+(const short int &x);
			data_t operator+(const long int &x);
			data_t operator+(const long long int &x);
			data_t operator+(const unsigned long long int &x);
			data_t operator+(const unsigned long int &x);
			data_t operator+(const unsigned short int &x);
			data_t operator+(const unsigned int &x);
			data_t operator+(const double &x);
			data_t operator+(const std::string s);
			data_t operator+(const char *c_s);


			// Special Subtraction Operator Overloading  
			data_t operator-(const int &x);
			data_t operator-(const short int &x);
			data_t operator-(const long int &x);
			data_t operator-(const long long int &x);
			data_t operator-(const unsigned long long int &x);
			data_t operator-(const unsigned long int &x);
			data_t operator-(const unsigned short int &x);
			data_t operator-(const unsigned int &x);
			data_t operator-(const double &x);


			// Special Multiplication Operator Overloading  
			data_t operator*(const int &x);
			data_t operator*(const short int &x);
			data_t operator*(const long int &x);
			data_t operator*(const long long int &x);
			data_t operator*(const unsigned long long int &x);
			data_t operator*(const unsigned long int &x);
			data_t operator*(const unsigned short int &x);
			data_t operator*(const unsigned int &x);
			data_t operator*(const double &x);

			// Special Division Operator Overloading  
			data_t operator/(const int &x);
			data_t operator/(const short int &x);
			data_t operator/(const long int &x);
			data_t operator/(const long long int &x);
			data_t operator/(const unsigned long long int &x);
			data_t operator/(const unsigned long int &x);
			data_t operator/(const unsigned short int &x);
			data_t operator/(const unsigned int &x);
			data_t operator/(const double &x);

			// Special == Comparators
			bool operator==(const int &x);
			bool operator==(const short int &x);
			bool operator==(const long int &x);
			bool operator==(const long long int &x);
			bool operator==(const unsigned long long int &x);
			bool operator==(const unsigned long int &x);
			bool operator==(const unsigned short int &x);
			bool operator==(const unsigned int &x);
			bool operator==(double &x);
			bool operator==(std::string &s);
			bool operator==(char *c_s);

			// Special != Comparators
			bool operator!=(const int &x);
			bool operator!=(const short int &x);
			bool operator!=(const long int &x);
			bool operator!=(const long long int &x);
			bool operator!=(const unsigned long long int &x);
			bool operator!=(const unsigned long int &x);
			bool operator!=(const unsigned short int &x);
			bool operator!=(const unsigned int &x);
			bool operator!=(double &x);
			bool operator!=(std::string &s);
			bool operator!=(char *c_s);

			// Special > Comparators
			bool operator>(const int &x);
			bool operator>(const short int &x);
			bool operator>(const long int &x);
			bool operator>(const long long int &x);
			bool operator>(const unsigned long long int &x);
			bool operator>(const unsigned long int &x);
			bool operator>(const unsigned short int &x);
			bool operator>(const unsigned int &x);
			bool operator>(double &x);
			bool operator>(std::string &s);
			bool operator>(char *c_s);

			// Special < Comparators
			bool operator<(const int &x);
			bool operator<(const short int &x);
			bool operator<(const long int &x);
			bool operator<(const long long int &x);
			bool operator<(const unsigned long long int &x);
			bool operator<(const unsigned long int &x);
			bool operator<(const unsigned short int &x);
			bool operator<(const unsigned int &x);
			bool operator<(double &x);
			bool operator<(std::string &s);
			bool operator<(char *c_s);

			// Special >= Comparators
			bool operator>=(const int &x);
			bool operator>=(const short int &x);
			bool operator>=(const long int &x);
			bool operator>=(const long long int &x);
			bool operator>=(const unsigned long long int &x);
			bool operator>=(const unsigned long int &x);
			bool operator>=(const unsigned short int &x);
			bool operator>=(const unsigned int &x);
			bool operator>=(double &x);
			bool operator>=(std::string &s);
			bool operator>=(char *c_s);

			// Special <= Comparators
			bool operator<=(const int &x);
			bool operator<=(const short int &x);
			bool operator<=(const long int &x);
			bool operator<=(const long long int &x);
			bool operator<=(const unsigned long long int &x);
			bool operator<=(const unsigned long int &x);
			bool operator<=(const unsigned short int &x);
			bool operator<=(const unsigned int &x);
			bool operator<=(double &x);
			bool operator<=(std::string &s);
			bool operator<=(char *c_s);
		};
	}
}

std::ostream & operator << (std::ostream &out, const vz_learn::data_manip::data_t &class_obj);

#endif
