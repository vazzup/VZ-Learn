CXXFLAGS=-std=c++17 -fpic -ggdb -Wall -Wextra
BIN=../bin/
INCLUDE=../include/
LIBS=../libs/

.PHONY: clean test all install

$(BIN)data_t.o: data_t.cpp $(INCLUDE)data_t.hpp
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c data_t.cpp -o $(BIN)data_t.o

$(LIBS)libdatat.so: $(BIN)data_t.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared $(BIN)data_t.o -o $(LIBS)libdatat.so

$(BIN)data_manip.o: data_manip.cpp $(INCLUDE)data_manip.hpp $(BIN)data_t.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c data_manip.cpp $(BIN)data_t.o -o $(BIN)data_manip.o

$(LIBS)libdatamanip.so: $(BIN)data_manip.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared $(BIN)data_manip.o -o $(LIBS)libdatamanip.so 

liblinearregression.so: linear_regression.cpp $(INCLUDE)linear_regression.hpp $(BIN)data_manip.so $(BIN)data_t.so
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -shared linear_regression.cpp -o $(LIBS)liblinearregression.so -ldata_manip -ldata_t

all: $(LIBS)libdatat.so $(LIBS)libdatamanip.so

clean:
	rm -rf ../bin/*
	rm -rf ../libs/*

test: all
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) data_t_test.cpp -o $(BIN)data_t_test -ldatat -Wl,-rpath,"\$$ORIGIN/../libs"
	chmod +x $(BIN)data_t_test
	$(BIN)data_t_test
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) data_manip_test.cpp -o $(BIN)data_manip_test -ldatamanip -ldatat -Wl,-rpath,"\$$ORIGIN/../libs"
	chmod +x $(BIN)data_manip_test
	$(BIN)data_manip_test

install: test 
