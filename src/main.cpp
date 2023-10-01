#include <iostream>
#include <vector>

#include "funcs.h"

using shape_vec = std::vector<std::shared_ptr<Curve>>;

int main() {
  shape_vec curves(25);

  std::cout << "Generating 25 random shapes...\n";
  for(auto &&el: curves)
    el = CurveUtils::getRandomShape();

  std::cout << "\nAll generated shapes:\n";
  CurveUtils::printShapeVec(curves);

  shape_vec circles;

  std::cout << "\nFiltering circles from the list of shapes...\n";
  CurveUtils::fillOnlyCircles(curves, circles);

  std::cout << "\nSorting circles...\n";
  CurveUtils::sortCircle(circles);

  std::cout << "\nList of sorted circles:\n";
  CurveUtils::printShapeVec(circles);

  std::cout << "\nTotal sum of circle radii: ";
  std::cout << CurveUtils::getSumRadii(circles) << std::endl;

  // I have done multi-threading, but it's leaks if i use valgrind.
  //  std::cout << CurveUtils::getSumRadiiMultiThreading(circles) << std::endl;

  return 0;
}