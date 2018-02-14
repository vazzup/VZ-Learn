CXXFLAGS=-std=c++14 -fpic -ggdb -Wall -Wextra
BIN=../bin/
INCLUDE=../include/
LIBS=../libs

.PHONY: clean test all install

liblinearregression.so: linear_regression.cpp $(INCLUDE)linear_regression.hpp $(BIN)data_manip.so $(BIN)data_t.so
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared linear_regression.cpp -o $(LIBS)liblinearregression.so -ldata_manip -ldata_t

libdatamanip.so: data_manip.cpp $(INCLUDE)data_manip.hpp data_t.so
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared data_manip.cpp  -o $(LIBS)libdatamanip.so -ldata_t

libdatat.so: data_t.cpp $(INCLUDE)data_t.hpp
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared data_t.cpp -o $(LIBS)libdatat.so

all: libdatat.so

clean:
	rm -rf ../bin/*

test: all
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) data_t_test.cpp -o $(BIN)data_t_test -ldatat -Wl,-rpath,"\$$ORIGIN/../libs"
	chmod +x $(BIN)data_t_test
	$(BIN)data_t_test

install: test 
