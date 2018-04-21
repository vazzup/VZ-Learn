namespace vz_learn::algorithm
{

	std::map< std::map< std::map< double > > > naive_bayes(\
		boost::numeric::ublas::matrix<double>& X,
		const int output_column);
	{
		int rows = X.size1(), columns = X.size2(), output
		std::set <int> unique_output_bins;
		std::vector <int> output_bins;
		std::map< std::map< std::map< double > > > rules;
		std::map < std::pair<double, double>, double> rules;

		for(int row=0; row<rows; row++)
		{
			if(unique_output_bins.find(X(row, output_column))\
						== unique_output_bins.end())
			{
				unique_output_bins.insert(X(row, output_column));
				output_bins.push_back(X(row, output_column));
			}
		}

		for(int column=0; column<columns; column++)
		{
			if(column == output_column) continue;
			for(int row=0; row<rows; row++)
			{
				rules[column][X(row, output_column)][X(row, column)]++;
			}
		}

		return rules;
	}

	double predict(const std::map<int, double>  
		const std::map< std::map< std::map<double> > >& rules)
	{
		asssert(column_nos.size() == matrix.
		double ans = -1, max_probability=-0.11;
		for(std::map< std::map< std::map<double> > >::iterator op_it=rules.begin();\
			op_it!=rules.end(); op_it++)
		{
		}
	}
}
