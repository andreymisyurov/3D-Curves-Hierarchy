#include <iostream>
#include <vector>

#include "funcs.h"

using shape_vec = std::vector<std::shared_ptr<Curve>>;

int main() {
  shape_vec curves(10);
  for(auto &&el: curves)
    el = getRandomShape();

  printShapeVec(curves);

  shape_vec circles;
  fillOnlyCircles(curves,circles);
  sortCircle(circles);
  std::cout << std::endl;
  printShapeVec(circles);
  std::cout << std::endl;
  std::cout << getSumRadii(circles);
  return 0;
}