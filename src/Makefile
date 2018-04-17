CXXFLAGS=-std=c++17 -fpic -ggdb -Wall -Wextra
BIN=../bin/
INCLUDE=../include/
LIBS=../libs/

.PHONY: clean test all install

$(BIN)data_manip.o: data_manip.cpp $(INCLUDE)data_manip.hpp
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) -c data_manip.cpp -o $(BIN)data_manip.o

all: $(BIN)data_manip_test

clean:
	rm -rf ../bin/*
	rm -rf ../libs/*

$(BIN)data_manip_test: data_manip_test.cpp $(BIN)data_manip.o
	g++ $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) data_manip_test.cpp $(BIN)data_manip.o -o $(BIN)data_manip_test

test: all
	chmod +x $(BIN)data_manip_test
	$(BIN)data_manip_test

install: test 
