all:
	g++ main.cpp circle.cpp
tests: clean
	g++ -std=c++11 -o tests circle.cpp tests.cpp -lgtest -lgtest_main -pthread
	./tests
clean:
	-rm tests a.out