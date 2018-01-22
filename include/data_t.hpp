#ifndef _DATA_T_
#define _DATA_T_


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
		typedef struct data_t
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
			union U
			{
				long long int n;
				std::string s;
				double d;
				char c;
				void *p;
				U();
				~U();
			} data;	// Holds the data 
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
			data_t(const std::string s);
			data_t(const char c);
			data_t(const double d);
			data_t(const void *p);
			// Basic Operator Overloading
			void operator=(const struct data_t& class_obj);
			void operator+(const struct data_t& class_obj);
			void operator-(const struct data_t& class_obj);
			void operator*(const struct data_t& class_obj);
			void operator/(const struct data_t& class_obj);
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
			void operator=(const char c);
			void operator=(const double d);
			void operator=(const void *p);
		} data_t;
	}
}
#endif
