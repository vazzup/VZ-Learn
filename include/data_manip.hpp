#ifndef _DATA_MANIP_
#define _DATA_MANIP_

#include "data_t.hpp"

#define _DM_UN_T -1
#define _DM_LL_T 0
#define _DM_ST_T 1
#define _DM_DB_T 2
#define _DM_CH_T 3
#define _DM_VD_T 4

namespace vzlearn
{
	namespace data_manip
	{
		boost::numeric::ublas::vector <string> split_at_char(\
				const string& line, char& c);
		boost::numeric::ublas::matrix <data_t> get_data_from_csv(\
				const string& filepath,\
				const bool& ignore_first_line);
	}
}
#endif
