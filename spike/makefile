CXX=g++
CXXFLAGS=-g -Wall -std=c++11
LDFLAGS=
BIN=Main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all:	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(BIN) $^

%.o:	%.c
		$(CXX) $(CXXFLAGS) $@ -c $<

clean:
		rm -f *.o
		rm $(BIN)


