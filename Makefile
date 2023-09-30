CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -Iinclude
LDFLAGS = -lgtest -lgtest_main -pthread
TARGET = 3DCurvesApp

SRC = src/circle.cpp src/ellipse.cpp src/helix.cpp src/funcs.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

tests_compile:
	$(CXX) $(CXXFLAGS) -o tests src/circle.cpp src/ellipse.cpp src/helix.cpp src/tests.cpp src/funcs.cpp $(LDFLAGS)

tests: tests_compile
	./tests

leaks:
	valgrind --leak-check=full ./tests

clean:
	rm -f src/*.o $(TARGET) tests

docker_build:
	docker build -t 3dcurves-tests .

docker_run:
	docker run --rm -it 3dcurves-tests

.PHONY: all clean tests leaks
