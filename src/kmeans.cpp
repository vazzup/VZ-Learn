#include "kmeans.hpp"

namespace vz_learn::algorithm
{
	void kmeans(const boost::numeric::ublas::matrix <double>& input_matrix,\
		double (*distance_function) (const std::vector<double>& row_one,\
					const std::vector<double>& row_two),\
		std::vector<std::vector<double> >& clusters,\
		const int number_of_clusters, const bool debug)
	{
		/* *****************************************
		 * Function to cluster data points together
		 * using the k means algorithm
		 * Expects user to pass the distance function
		 * as a parameter
		 * ******************************************/
		int rows = input_matrix.size1(), columns = input_matrix.size2();
		if(number_of_clusters > rows)
		{
			// Not possible
			std::cerr << "Error in KMEANS: number of clusters less\
				than number of data points\n";
		}
		std::random_device non_deterministic_generator;
		std::mt19937 generator(non_deterministic_generator());
		std::uniform_int_distribution<int> distribution(0, rows);
		std::vector<std::vector<double> > X;
		for(int row=0; row<rows; row++)
		{
			// Convert from ublas matrix to vector of vectors
			X.push_back(std::vector<double>(0));
			for(int column=0; column<columns; column++)
			{
				X[row].push_back(input_matrix(row, column));
			}
		}
		// Store indices of unique initial means
		// Initial means will be randomly chosen from original data points
		std::unordered_set <int> unique_cluster_means;
		// Store the current number_of_clusters means and the previous ones
		std::vector<std::vector<double> > cluster_means, previous_cluster_means;
		while((int)cluster_means.size() != number_of_clusters)
		{
			// Select new row randomly until
			// number_of_clusters unique means are selected
			int row = distribution(generator);
			if(unique_cluster_means.find(row) ==\
					unique_cluster_means.end())
			{
				unique_cluster_means.insert(row);
				cluster_means.push_back(X[row]);
			}
		}
		previous_cluster_means.resize(number_of_clusters);
		clusters.resize(number_of_clusters);
		for(int cluster=0; cluster<number_of_clusters; cluster++)
		{
			// Initalize previous means vector to -1
			previous_cluster_means[cluster].resize(columns);
			for(int column=0; column<columns; column++)
			{
				previous_cluster_means[cluster][column] = -1;
			}
		}
		int iter = 0;
		while(true)
		{
			for(int cluster=0; cluster<number_of_clusters; cluster++)
			{
				// Set the previous means to current means
				previous_cluster_means[cluster] = cluster_means[cluster];
			}
			clusters.resize(number_of_clusters); // Incase originally clusters is empty
			for(int cluster=0; cluster<number_of_clusters; cluster++)
			{
				// Remove all previous clusters
				clusters[cluster].clear();
			}
			for(int row=0; row<rows; row++)
			{
				// Calculate the nearest cluster for each row
				// and assign it to that cluster
				int nearest_cluster = -1;
				double min_distance =\
					std::numeric_limits<double>::max();
				for(int cluster=0;\
					cluster<number_of_clusters;\
					cluster++)
				{
					double distance = distance_function(\
						X[row], cluster_means[cluster]);
					if(distance < min_distance)
					{
						// Closest cluster mean
						min_distance = distance;
						nearest_cluster = cluster;
					}
				}
				clusters[nearest_cluster].push_back(row);
			}
			unique_cluster_means.clear();
			for(int cluster=0; cluster<number_of_clusters; cluster++)
			{
				// Calculate new cluster means
				for(int column=0; column<columns; column++)
				{
					// Clear all means
					cluster_means[cluster][column] = 0;
				}
				int data_points = clusters[cluster].size();
				if(data_points == 0)
				{
					// This cluster is empty
					// Assign it a new mean and continue
					int row;
					do
					{
						row = distribution(generator);
						unique_cluster_means.insert(row);
						cluster_means[cluster] = X[row];
						row = distribution(generator);
					} while(unique_cluster_means.find(row) !=\
							unique_cluster_means.end());
					continue;
				}
				for(int data_point=0;\
					data_point<data_points;\
					data_point++)
				{
					// For each data point in each cluster
					// Since data point is actually the row number
					int row = clusters[cluster][data_point];
					for(int column=0; column<columns; column++)
					{
						// Add the values of that
						// data point to the means vector
						cluster_means[cluster][column] +=\
								X[row][column];
					}
				}
				for(int column=0; column<columns; column++)
				{
					// To calculate mean, divide by
					// number of data points in that cluster
					cluster_means[cluster][column] /= data_points;
				}
			}
			bool no_change = true;
			if(debug)
			{
				std::cout << "Iteration #" << iter++ << ":\n";
				for(int cluster=0;\
					cluster<number_of_clusters;\
					cluster++)
				{
					// Print all cluster means
					std::cout << "\tCurrent cluster mean #"\
							<< cluster << ":\n\t\t";
					for(int column=0; column<columns; column++)
					{
						std::cout <<\
							cluster_means[cluster][column]\
							<< " ";
					}
					std::cout << "\n\tPrevious cluster mean #"\
							<< cluster << ":\n\t\t";
					for(int column=0; column<columns; column++)
					{
						std::cout <<\
							previous_cluster_means\
							[cluster][column] << " ";
					}
					std::cout << "\n";
				}
			}
			for(int cluster=0; cluster<number_of_clusters; cluster++)
			{
				// Check if the means have changed
				// If they haven't leave because we've fouund the clusters
				for(int column=0; column<columns; column++)
				{
					if(previous_cluster_means[cluster][column]
						!= cluster_means[cluster][column])
					{
						no_change = false;
						break;
					}
				}
				if(!no_change)
					break;
			}
			if(no_change)
			{
				break;
			}
			if(iter > 99) break;
		}
		if(debug)
		{
			std::cout << "The final clusters are:\n";
			for(int cluster=0; cluster<number_of_clusters; cluster++)
			{
				std::cout << "\tCluster mean #"\
					<< cluster << ":\n\t\t";
				for(int column=0; column<columns; column++)
				{
					std::cout <<\
						cluster_means[cluster][column]\
						<< " ";
				}
				std::cout << "\nThe rows in the cluster are:\n";
				int data_points = (int)clusters[cluster].size();
				for(int data_point=0;\
					data_point<data_points;\
					data_point++)
				{
					std::cout << data_point << " ";
				}
				std::cout << "\n";
			}
		}
	}
}
