CXXFLAGS='-std=c++14'
BIN=../bin/
INCLUDE=../include/

linear_regression: linear_regression.cpp
	g++ linear_regression.cpp $(CXXFLAGS) -o $(BIN)linear_regression

clean:
	rm -rf ../bin/

data_manip.o: data_manip.cpp $(INCLUDE)data_manip.hpp
	g++ -I$(INCLUDE) $(CXXFLAGS) -c data_manip.cpp  -o $(BIN)data_manip.o

