#include <iostream>
#include <vector>

#include "funcs.h"

using shape_vec = std::vector<std::shared_ptr<Curve>>;

int main() {
  shape_vec curves();

  std::shared_ptr<Curve> temp = getRandomShape();
  std::cout << temp->getDerivative(0.).x << " " << temp->getDerivative(0.).y << " " << temp->getDerivative(0.).z << std::endl;
  return 0;
}