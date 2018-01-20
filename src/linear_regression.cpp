#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main()
{
	boost::numeric::ublas::vector<double> v(3);
	for(unsigned int i = 0; i < v.size(); ++i) 
	{
		v(i) = i;
	}
	std::cout << v << std::endl;
	return 0;
}
