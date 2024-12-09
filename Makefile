CXX = g++
CXXFLAGS = -Wall -g

SRC = src/main.cpp src/kbHook.cpp

OBJ = $(SRC:.cpp=.o)

EXEC = main

LDFLAGS = -lws2_32

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
