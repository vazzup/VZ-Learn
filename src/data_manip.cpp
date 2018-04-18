#include "data_manip.hpp"

namespace vz_learn::data_manip
{
	void trim_string(std::string& word)
	{
		/* *******************************
		 * Function to remove any trailing whitespaces (WS)
		 * or unwanted special characters like \r \b \n EOF etc.
		 * ******************************/
		int init_pos = 0, // Position of first non WS
			final_pos = (int)word.size(); // Position of last non WS
		int len = final_pos;

		while((init_pos < len) && (word[init_pos] == '\t'
			|| word[init_pos] == ' ' || word[init_pos] == '\n'
			|| word[init_pos] == '\r' || word[init_pos] == '\b'
			|| word[init_pos] == EOF))
		{
			init_pos++; // Until first non WS is encountered
		}

		while(--final_pos >= init_pos && (word[final_pos] == '\t'
			|| word[final_pos] == ' ' || word[final_pos] == '\n'
			|| word[final_pos] ==  '\r' || word[final_pos] == '\b'
			|| word[final_pos] == EOF))
			; // Runs until last non WS is encountered

		if(final_pos >= init_pos)
			// Return the Substring between first and last non WS
			word = word.substr(init_pos, final_pos - init_pos + 1);
		else
			word = ""; // String is only Only WS
	}

	int check_data_type(const char* s)
	{
		// In case of string literal
		return check_data_type(std::string(s));
	}

	int check_data_type(const std::string& s)
	{
		/* **********************************
		 * Function to check the data type of
		 * the information in given string
		 * returns DB_T if double
		 * returns ST_T if string
		 * **********************************/
		int len = s.size();
		if(len == 0)
		{
			return ST_T;
		}
		bool numeric = true, point = false;
		for(int i=0; i<len; i++)
		{
			if (s[i] == '.')
			{
				// Decimal is present
				point = true;
			}
			else if(!(s[i] <='9' && s[i] >= '0'))
			{
				// Non numeric character, also not decimal
				numeric = false;
			}
		}
		if(numeric)
		{
			// Only decimal and numeric characters encountered
			return DB_T;
		}
		else if(!numeric)
		{
			// Alpha / WS characters encountered
			return ST_T;
		}
		return ST_T;
	}

	void convert_to_doubles(
		const boost::numeric::ublas::matrix <std::string>& data_matrix_s,
		boost::numeric::ublas::matrix <double>& data_matrix,
		const bool OHE)
	{
		/* **********************************
		 * Function to convert from matrix
		 * of strings to matrix of doubles
		 * Does so column-wise
		 * Algorithm:-
		 * 1. Check data type of column
		 * 2. If numeric - copy as is
		 * 3. If non-numeric - one hot encode it? (or convert to numbers)?
		 * 4. Repeat for all columns
		 * *********************************/
		int rows = data_matrix_s.size1();
		int columns = data_matrix_s.size2();
		if(rows == 0) // Matrix is empty
			return;
		data_matrix.resize(rows, columns, true);
		std::vector <int> todo_ohe; // Column No's to be OHEd
		for(int column=0; column<columns; column++)
		{
			// Go Column Wise
			int data_type = check_data_type(data_matrix_s(0, column));
			switch(data_type)
			{
				case DB_T:
				{
					// If it's a double, convert string
					// to double and copy over for each row
					for(int row=0; row<rows; row++)
					{
						data_matrix(row, column) =\
							std::stod(data_matrix_s(row, column));
					}
					break;
				}
				case ST_T:
				{
					// Store which string is assigned which ID
					std::unordered_map <std::string, int> id_map;
					int id = 1; // Initial ID
					for(int row=0; row<rows; row++)
					{
						if(id_map[data_matrix_s(row, column)])
						{
							// String has already been assigned
							// an unique ID
							data_matrix(row, column) =\
								id_map[data_matrix_s(row, column)];
						}
						else
						{
							// New String encountered
							id_map[data_matrix_s(row, column)] = id;
							data_matrix(row, column) = id++;
						}
					}
					todo_ohe.push_back(column); // May have to applt OHE
					break;
				}
				default:
				{
					std::cerr << "Unknown Data Type\
						encountered while converting\
						string to double matrix\n";
					break;
				}
			};
		}

		if(OHE)
		{
			// User has told to apply OHE
			// Every String column in OHEd
			for(int column : todo_ohe)
			{
				one_hot_encode(data_matrix, column);
			}
		}
	}

	void get_data_from_csv(boost::numeric::ublas::matrix <double>& data_matrix,\
		const std::string& filepath, bool ignore_first_line,\
		bool clean_dataset, const bool OHE)
	{
		/* ***********************************************
		 * Flow of the function:-
		 * Read CSV line by line as string [DONE]
		 * separate by commas and store csv as matrix [DONE]
		 * Trim all values [DONE]
		 * Remove rows with NULL / EMPTY values [DONE]
		 * Convert string matrix to double matrix using OHE and other methods
		 * Return the double matrix
		 * *************************************************/
		boost::numeric::ublas::matrix <std::string> data_matrix_s;
		int len = filepath.size();
		// Check if path given is for csv
		assert(filepath[len-3] == 'c' &&\
			filepath[len-2] == 's' &&\
			filepath[len-1] == 'v');
		std::ifstream infile;
		infile.open(filepath); // Open the file as readonly
		if(infile.good()) // If file stream is good
		{

			std::string line;
			int row_no = 0;
			while(std::getline(infile, line)) // Read line by line
			{
				std::vector <std::string> separated_strings;

				if(ignore_first_line) // Ignore first line due to column titles
				{
					ignore_first_line = false;
					continue;
				}

				trim_string(line); // Remove any extra whitespaces
				boost::split(separated_strings, line,\
					[](char c) { return c == ','; });// Split along commas
				for(int i=0; i<separated_strings.size(); i++)
				{
					trim_string(separated_strings[i]); // Trim separated strings
				}

				if(clean_dataset)
				{
					// Get rid of rows with NULL / Empty columns
					bool null_ = false;
					for(std::string s : separated_strings)
					{
						if(s == "")
						{
							null_ = true;
							break;
						}
					}
					if(null_)
						continue;
				}

				add_row_to_matrix<std::string>(separated_strings, data_matrix_s, row_no);
				++row_no;
			}
		}
		else
		{
			std::cerr << "There's some issue with the file\n";
			abort();
		}
		print_head<std::string>(data_matrix_s);
		convert_to_doubles(data_matrix_s, data_matrix, OHE);
	}

	void normalize_feature(boost::numeric::ublas::matrix <double>& data_matrix,\
		const int column)
	{
		/* **************************************
		 * Function to normalize a column in data matrix
		 * Normalizes using feature scaling
		 * **************************************/
		int rows = data_matrix.size1(), columns = data_matrix.size2();
		if(rows == 0 || columns == 0)
			return; // Data Matrix is empty
		double min_value = std::numeric_limits<double>::max();
		double max_value = std::numeric_limits<double>::min();
		for(int row=0; row<rows; row++)
		{
			min_value = std::min(min_value, data_matrix(row, column));
			max_value = std::max(max_value, data_matrix(row, column));
		}
		for(int row=0; row<rows; row++)
		{
			data_matrix(row, column) -= min_value;
			data_matrix(row, column) /= (max_value - min_value);
		}
	}

	void one_hot_encode(boost::numeric::ublas::matrix <double> &data_matrix,\
		int column_no,\
		int threshold)
	{
		int rows, columns;
		rows = data_matrix.size1();
		if(rows == 0) {
			// Matrix is empty
			std::cerr << "Matrix sent for one hot encoding is empty" << std::endl;
			return;
		}
		columns = data_matrix.size2();
		std::unordered_set <double> nominal_values; // Unique Values Encountered
		std::unordered_map <double, int> column_mapping; // Value -> Col. No.
		int ohe_column_no = column_no; // Initial Column No
		// First unique value is assigned same column
		for(int i=0; i<rows; i++)
		{
			// Finding all unique nominal values
			double nominal_value =\
				data_matrix(i, column_no); // Value
			if(nominal_values\
				.find(nominal_value)\
				== nominal_values.end())
			{
				// Previously Unseen Value
				nominal_values.insert(nominal_value);
				column_mapping[nominal_value] =\
					ohe_column_no; //  Assign Column
				if(ohe_column_no == column_no)
				{
					// If this was the initial unique value
					// Move the column no to the end
					ohe_column_no = columns;
				}
				else
				{
					// Keep increasing by one
					ohe_column_no++;
				}
			}
		}
		// Resize matrix by number of unique values - 1
		// - 1 because 1 unique value is assigned to current column
		int num_unique_values = (int)nominal_values.size();
		data_matrix.resize(rows,\
			columns + (num_unique_values - 1), true);
		// Make value of all new columns in all rows 0
		// 1 If the value is same as the column mapped onto
		for(int row=0; row<rows; row++)
		{
			// Copy of row's nominal value
			double orig_val = data_matrix(row, column_no);
			for(auto it : nominal_values)
			{
				if(it == orig_val)
				{
					// This row had the same nominal value
					data_matrix(row, column_mapping[it]) = 1;
				}
				else
				{
					// Column on Nominal Value different from row
					data_matrix(row, column_mapping[it]) = 0;
				}
			}
		}
	}

	void random_initialization(boost::numeric::ublas::matrix <double>& data_matrix)
	{
		/* ***********************************************
		 * Function to initialize a matrix with random values between 0 and 1
		 * ***********************************************/
		std::random_device non_deterministic_generator;
		std::mt19937 generator(non_deterministic_generator());
		std::uniform_real_distribution<double> distribution(0, 1);
		int rows = data_matrix.size1(), columns = data_matrix.size2();
		for(int row=0; row<rows; row++)
		{
			for(int column=0; column<columns; column++)
			{
				data_matrix(row, column) = distribution(generator);
			}
		}
	}

	void split_train_dev_test(const boost::numeric::ublas::matrix <double>& data_matrix,\
			boost::numeric::ublas::matrix <double>& data_matrix_train,\
			boost::numeric::ublas::matrix <double>& data_matrix_dev,\
			boost::numeric::ublas::matrix <double>& data_matrix_test,\
			const double train_ratio, const double dev_ratio)
	{
		/* ***************************************
		 * Function to split a dataset into training set,
		 * dev set and training set.
		 * **************************************/
		// Sum of train and dev need to be less than or equal to 1
		if((1.0 - train_ratio + dev_ratio) <= 0)
		{
			std::cerr << "Ratios don't add up to 1.0 in split_train_dev_test\n";
			return;
		}
		int train_upper_limit = train_ratio * RAND_LIM;
		int dev_upper_limit = train_upper_limit + dev_ratio * RAND_LIM;
		int test_upper_limit = RAND_LIM;
		int rows = data_matrix.size1(), columns = data_matrix.size2();
		int train_row = 0, dev_row = 0, test_row = 0;
		std::vector <double> data_row(columns);
		std::random_device non_deterministic_generator;
		std::mt19937 generator(non_deterministic_generator());
		std::uniform_int_distribution<int> distribution(0, RAND_LIM - 1);
		for(int row=0; row<rows; row++)
		{
			for(int column=0; column<columns; column++)
			{
				data_row[column] = data_matrix(row, column);
			}
			int random_sample = distribution(generator);
			if(random_sample < train_upper_limit)
			{
				add_row_to_matrix<double>(data_row, data_matrix_train, train_row++);
			}
			else if(random_sample < dev_upper_limit)
			{
				add_row_to_matrix<double>(data_row, data_matrix_dev, dev_row++);
			}
			else if(random_sample < test_upper_limit)
			{
				add_row_to_matrix<double>(data_row, data_matrix_test, test_row++);
			}
		}
	}
}
