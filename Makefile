CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -fopenmp #-Werror
LDFLAGS = -lgtest -lgtest_main -pthread -fopenmp
LIB_LDFLAGS = -L. -lCurves -fopenmp
TARGET = 3DCurvesApp

all: $(TARGET) test_build

$(TARGET): build_library
	$(CXX) $(CXXFLAGS) -o $@ src/main.cpp $(LIB_LDFLAGS)

run: $(TARGET)
	LD_LIBRARY_PATH=$(PWD) ./$(TARGET)

tests: test_build
	LD_LIBRARY_PATH=$(PWD) ./tests

leaks: test_build
	LD_LIBRARY_PATH=$(PWD) valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f libCurves/*.o $(TARGET) tests libCurves.so

docker_build:
	docker build -t 3dcurves-tests .

docker_run:
	docker run --rm -it 3dcurves-tests

test_build: build_library
	$(CXX) $(CXXFLAGS) -o tests src/tests.cpp $(LDFLAGS) $(LIB_LDFLAGS)

build_library:
	@mkdir -p libCurves/
	@cp -r include/ libCurves/
	@cp src/circle.cpp src/ellipse.cpp src/helix.cpp src/funcs.cpp libCurves/
	@$(CXX) $(CXXFLAGS) -fPIC -c libCurves/circle.cpp -o libCurves/circle.o
	@$(CXX) $(CXXFLAGS) -fPIC -c libCurves/ellipse.cpp -o libCurves/ellipse.o
	@$(CXX) $(CXXFLAGS) -fPIC -c libCurves/helix.cpp -o libCurves/helix.o
	@$(CXX) $(CXXFLAGS) -fPIC -c libCurves/funcs.cpp -o libCurves/funcs.o
	g++ -shared -o libCurves.so libCurves/circle.o libCurves/ellipse.o libCurves/helix.o libCurves/funcs.o
	@rm -rf libCurves

.PHONY: all clean tests leaks build_library
