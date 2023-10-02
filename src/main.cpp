#include <iostream>
#include <vector>

#include "my_container.h"

int main() {

  MyContainer curves;

  std::cout << "Generating 25 random shapes...\n";
  curves.generateRandomShapes(25);

  std::cout << "\nAll generated shapes:\n";
  curves.printShapes();

  MyContainer only_circles;

  std::cout << "\nFiltering circles from the list of shapes...\n";
  only_circles.filterOnlyCircles(curves);

  std::cout << "\nSorting circles...\n";
  only_circles.sortCircles();

  std::cout << "\nList of sorted circles:\n";
  only_circles.printShapes();

  std::cout << "\nTotal sum of circle radii: ";
  std::cout << only_circles.getSumRadii() << std::endl;

// I have done multi-threading, but it's leaks if I use valgrind.
//  std::cout << only_circles.getSumRadiiMultiThreading() << std::endl;

  return 0;
}
