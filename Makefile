all:
	g++ main.cpp circle.cpp ellipse.cpp helix.cpp funcs.cpp
tests: clean
	g++ -std=c++11 -g -o tests circle.cpp tests.cpp ellipse.cpp helix.cpp -lgtest -lgtest_main -pthread
	./tests
leaks:
	valgrind --leak-check=full ./tests
clean:
	-rm tests a.out