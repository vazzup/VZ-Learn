CXXFLAGS=-std=c++14 -fpic -g
BIN=../bin/
INCLUDE=../include/

linear_regression: linear_regression.cpp
	g++ linear_regression.cpp $(CXXFLAGS) -o $(BIN)linear_regression

clean:
	rm -rf ../bin/

data_manip.o: data_manip.cpp $(INCLUDE)data_manip.hpp data_t.o
	g++ -I$(INCLUDE) -L$(BIN) $(CXXFLAGS) -c data_manip.cpp  -o $(BIN)data_manip.o

data_t.o: data_t.cpp $(INCLUDE)data_t.hpp
	g++ -I$(INCLUDE) $(CXXFLAGS) -c data_t.cpp -o $(BIN)data_t.o
