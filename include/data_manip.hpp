#ifndef _DATA_MANIP_
#define _DATA_MANIP_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

#define _DM_UN_T -1
#define _DM_LL_T 0
#define _DM_ST_T 1
#define _DM_DB_T 2
#define _DM_CH_T 3
#define _DM_VD_T 4

namespace data_manip
{
	typedef struct data_t
	{
		union
		{
			long long int n;
			std::string s;
			double d;
			char c;
			void *p;
		} data;
		int data_type;
		struct data_t& operator=(const struct data_t class_obj);
		struct data_t& operator+(const struct data_t class_obj);
		struct data_t& operator-(const struct data_t class_obj);
		struct data_t& operator*(const struct data_t class_obj);
		struct data_t& operator/(const struct data_t class_obj);
		/* struct data_t& operator%(const struct data_t class_obj);
		struct data_t& operator+=(const struct data_t class_obj);
		struct data_t& operator-=(const struct data_t class_obj);
		struct data_t& operator*=(const struct data_t class_obj);
		struct data_t& operator/=(const struct data_t class_obj);
		struct data_t& operator%=(const struct data_t class_obj); */
	} data_t;
}
#endif
