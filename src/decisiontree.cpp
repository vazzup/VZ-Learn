#include "decisiontree.hpp"

namespace vz_learn::algorithm
{
	void create_decision_tree(\
		boost::numeric::ublas::matrix <double>& input_matrix,\
		std::unordered_set <int> used_columns,\
		dtreenode& parent_node, const int output_column)
	{
		/* *******************************************
		 * Function to recursively create a decision tree
		 * Takes in a ublas matrix and a root "parent" node
		 * *******************************************/
		int rows = input_matrix.size1(), columns = input_matrix.size2();
		std::unordered_map<double, double> class_count;
		std::vector<double> class_frequencies, output_classes;
		for(int row=0; row<rows; row++)
		{
			// Find all unique outputs and their counts
			class_count[input_matrix(row, output_column)]++;
		}
		for(auto it=class_count.begin(); it!=class_count.end(); it++)
		{
			// Put all counts into a vector
			class_frequencies.push_back(it->second);
		}
		// Calculate class entropy
		double overall_entropy = dt_entropy(class_frequencies);
		double best_column = -1;
		double best_information_gain = 0;
		for(int column=0; column<columns; column++)
		{
			// Find the column where splitting will lead to most information gain
			if(used_columns.find(column) == used_columns.end())
			{
				// This column has not been used for previous splitting
				// So we calculate it's entropy of splitting
				// First we get all distinct classes in this column
				class_count.clear();
				for(int row=0; row<rows; row++)
				{
					class_count[input_matrix(row, column)]++;
				}
				std::vector <std::pair<double, double> > column_classes;
				for(auto it=class_count.begin();\
					it!=class_count.end();\
					it++)
				{
					// First store all unique classes in a vector
					column_classes.push_back(*it);
				}

				int number_column_classes = column_classes.size();
				double column_entropy = 0;
				for(int column_class=0;\
					column_class<number_column_classes;
					column_class++)
				{
					// Now for each unique value, we calculate entropy
					// and add after multiiplying it's probablity
					class_count.clear();
					class_frequencies.clear();
					double class_no = column_classes[\
								column_class\
							].first;
					double class_count_ = column_classes[\
								column_class\
							].second;
					for(int row=0; row<rows; row++)
					{
						// Find all unique outputs and their counts
						if(input_matrix(row, column) ==\
							class_no)
							class_count[input_matrix(
								row,\
								output_column\
								)]++;
					}
					for(auto it=class_count.begin();\
							it!=class_count.end();\
							it++)
					{
						// Put all counts into a vector
						class_frequencies.push_back(it->second);
					}
					// Calculate column class entropy
					double column_class_entropy =\
						dt_entropy(class_frequencies);
					// Add to overall column entropy
					column_entropy += (class_count_ / rows) *\
						column_class_entropy;
				}
				// Calculate the information gain upon splitting with this column
				double information_gain = overall_entropy - column_entropy;
				if(information_gain >= best_information_gain)
				{
					best_column = column;
					best_information_gain = information_gain;
				}
			}
		}
		if(best_column == -1)
			return; // Leaf node
		// We add the best column to the used columns
		used_columns.insert(best_column);
		// Once we've found the best splitting column
		// we Create a new node, split it there, and
		// then return the split node(s)
		// First we find all unique values for class
		class_count.clear();
		for(int row=0; row<rows; row++)
		{
			class_count[input_matrix(row, best_column)]++;
		}
		std::vector <std::pair<double, double> > column_classes;
		for(auto it=class_count.begin();\
			it!=class_count.end();\
			it++)
		{
			// First store all unique classes in a vector
			column_classes.push_back(*it);
		}
		// Then, we create new nodes for each class
		for(int column_class=0;\
			column_class<(int)column_classes.size();\
			column_class++)
		{
			dtreenode class_node;
			class_node.splitting_column_no = best_column;
			class_node.splitting_comparator = dtreenode::EQ;
			class_node.value = column_classes[column_class].first;
			boost::numeric::ublas::matrix<double> temp_input; // Matrix to be sent to below nodes
			temp_input.resize(0, columns);
			int temp_row = 0;
			for(int row=0; row<rows; row++)
			{
				if(input_matrix(row, best_column) ==\
					column_classes[column_class].first)
				{
					temp_input.resize(temp_row + 1,\
							columns);
					for(int column=0; column<columns; column++)
					{
						temp_input(temp_row, column) =\
							input_matrix(row, column);
					}
				}
			}
			// If the best column is the output column,
			// We create a leaf node, else we split further
			if(best_column != output_column) // Not a leaf node
				create_decision_tree(temp_input, used_columns,\
							class_node, output_column);
			// Add node to the parent node
			parent_node.children.push_back(class_node);
		}
	}

	double dt_entropy(const std::vector<double> class_frequencies)
	{
		int size = (int)class_frequencies.size();
		int total_no = 0;
		for(int i=0; i<size; i++)
		{
			total_no += class_frequencies[i];
		}
		double entropy = 0;
		for(int i=0; i<size; i++)
		{
			if(class_frequencies[i] == 0)
				continue;
			entropy -= (class_frequencies[i]/total_no)*\
					log2(class_frequencies[i]/total_no);
		}
		return entropy;
	}

	double predict_dtree(dtreenode& root, std::vector<double>& values)
	{
		if((int)root.children.size() == 0)
			return root.value;
		int splitting_column = root.children[0].splitting_column_no;
		double value = values[splitting_column];
		for(int child=0; child<(int)root.children.size(); child++)
		{
			if(root.children[child].value == value)
			{
				return predict_dtree(root.children[child], values);
			}
		}
		return 0;
	}
}
