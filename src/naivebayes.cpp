#include "naivebayes.hpp"

namespace vz_learn::algorithm
{

	void naive_bayes(const boost::numeric::ublas::matrix<double>& X,
		std::map<double, std::map<int, std::map<double, double> > >& rules,
		const int output_column)
	{
		/* **************************************
		 * Function to run naive bayes and return
		 * the probability rules for a particular table
		 * Expects all input columns have been discretized
		 * **************************************/
		int rows = X.size1(), columns = X.size2();
		std::set <int> unique_output_bins; // Set to check uniqueness of all bins
		std::vector <int> output_bins; // This stores all unique output column bins
		// probability = rules[output_bin][column_no][input_bin]
		for(int row=0; row<rows; row++)
		{
			// Figure out and store all the unique bins in the output column
			if(unique_output_bins.find(X(row, output_column))\
						== unique_output_bins.end())
			{
				unique_output_bins.insert(X(row, output_column));
				output_bins.push_back(X(row, output_column));
			}
		}

		for(int column=0; column<columns; column++)
		{
			// Count for each o/p bin, column, i/p bin triplet
			if(column == output_column) continue;
			for(int row=0; row<rows; row++)
			{
				rules[(int)X(row, output_column)]\
					[column][X(row, column)]++;
			}
		}

		for(int i=0; i<(int)output_bins.size(); i++)
		{
			// Divide count for each triplet by number of rows
			// That gives us absolute probability of that triplet
			int output = output_bins[i];
			for(int column=0; column<columns; column++)
			{
				for(auto it=rules[output][column].begin();\
					it!=rules[output][column].end(); it++)
				{
					rules[output][column][it->first] /= rows;
				}
			}
		}
	}

	double bayesian_predict(std::map<int, double>& column_value,
		std::map<double, std::map<int, std::map<double, double> > >& rules)
	{
		/* ********************************************
		 * Function to predict the class of a given input
		 * vector based on the rules set by previous input vectors
		 * ********************************************/
		double ans = -1, max_probability=-0.11;
		for(auto op_it=rules.begin(); op_it!=rules.end(); op_it++)
		{
			// For each possible outcome, calculate probability
			double probability = 1;
			for(auto it=column_value.begin();\
				it!=column_value.end(); it++)
			{
				// For each column with bin value given,
				// take out probability from rules and multiply
				probability *= (op_it->second)\
					       [it->first]\
					       [it->second];
			}
			if(probability > max_probability)
			{
				// This outcome is more probable
				max_probability = probability;
				ans = op_it->first;
			}
		}
		return ans;
	}
}
