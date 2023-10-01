#ifndef RANDOM_SHAPE_H
#define RANDOM_SHAPE_H

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

using shape_vec = std::vector<std::shared_ptr<Curve>>;

class CurveUtils {
 public:
  std::shared_ptr<Curve> static getRandomShape();
  void static printShapeVec(const shape_vec &curves);
  void static fillOnlyCircles(const shape_vec &first, shape_vec &second);
  bool static compareRadii(const std::shared_ptr<Curve> &a, const std::shared_ptr<Curve> &b);
  void static sortCircle(shape_vec &circles);
  double static getSumRadii(const shape_vec &circles);

  // I have done multi-threading, but it's leaks if I use valgrind. It's my first working with <omp.h> library.
  // Maybe valgrind is wrong =)

  //  double static getSumRadiiMultiThreading(const shape_vec &circles);
};

#endif // RANDOM_SHAPE_H
