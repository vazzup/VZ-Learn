CXXFLAGS=-std=c++17 -fpic -ggdb -Wall -Wextra
BIN=../bin/
INCLUDE=../include/
LIBS=../libs/

.PHONY: check_dirs clean test all install 

all: check_dirs $(BIN)data_manip_test $(BIN)linear_regression_test $(BIN)naive_bayes_test

$(BIN)data_manip.o: data_manip.cpp $(INCLUDE)data_manip.hpp
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c data_manip.cpp -o $(BIN)data_manip.o

$(BIN)linear_regression.o: linear_regression.cpp $(INCLUDE)linear_regression.hpp $(BIN)data_manip.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c linear_regression.cpp $(BIN)data_manip.o -o $(BIN)linear_regression.o

$(BIN)naivebayes.o: naivebayes.cpp $(INCLUDE)naivebayes.hpp $(BIN)data_manip.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c naivebayes.cpp $(BIN)data_manip.o -o $(BIN)naivebayes.o

$(BIN)data_manip_test: data_manip_test.cpp $(BIN)data_manip.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) data_manip_test.cpp $(BIN)data_manip.o -o $(BIN)data_manip_test

$(BIN)linear_regression_test: linear_regression_test.cpp $(BIN)linear_regression.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) linear_regression_test.cpp $(BIN)linear_regression.o $(BIN)data_manip.o -o $(BIN)linear_regression_test

$(BIN)naive_bayes_test: naive_bayes_test.cpp $(BIN)naivebayes.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) naive_bayes_test.cpp $(BIN)naivebayes.o $(BIN)data_manip.o -o $(BIN)naive_bayes_test

clean:
	rm -rf ../bin/*
	rm -rf ../libs/*

check_dirs: 
	if [ ! -d "../bin" ]; then mkdir ../bin/; fi
	if [ ! -d "../lib" ]; then mkdir ../lib; fi

test: check_dirs all
	@echo -e "\n--------------------------------------"
	@echo -e "|TESTING DATA MANIP"
	@echo -e "--------------------------------------\n"
	chmod +x $(BIN)data_manip_test
	$(BIN)data_manip_test
	@echo -e "\n--------------------------------------"
	@echo -e "|TESTING LINEAR REGRESSION"
	@echo -e "--------------------------------------\n"
	chmod +x $(BIN)linear_regression_test
	$(BIN)linear_regression_test
	@echo -e "\n--------------------------------------"
	@echo -e "|TESTING NAIVE BAYES"
	@echo -e "--------------------------------------\n"
	chmod +x $(BIN)naive_bayes_test
	$(BIN)naive_bayes_test

install: test 
