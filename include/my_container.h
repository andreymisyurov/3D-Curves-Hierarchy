#ifndef MY_CONTAINER_H
#define MY_CONTAINER_H

#include <memory>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <numeric>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

class MyContainer {
 public:
  MyContainer();
  void generateRandomShapes(int count);
  void printShapes();
  void filterOnlyCircles(const MyContainer& other);
  void sortCircles();
  double getSumRadii();

  // I have done multi-threading, but it's leaks if I use valgrind. It's my first working with <omp.h> library.
  // Maybe valgrind is wrong =)
//  double getSumRadiiMultiThreading();

 private:
  bool static compareRadii(const std::shared_ptr<Curve> &a, const std::shared_ptr<Curve> &b);
  std::vector<std::shared_ptr<Curve>> m_curves;
};

#endif // MY_CONTAINER_H
