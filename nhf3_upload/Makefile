
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 -g -ggdb -DMEMTRACE -DCPORTA -D_JPORTA_STAT

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)