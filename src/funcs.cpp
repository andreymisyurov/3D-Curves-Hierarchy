#include <omp.h>

#include "funcs.h"

/**
 * Make random shape (Circle, Ellipse, Helix) with random numbers.
 * @return Pointer for created shape.
 */
std::shared_ptr<Curve> CurveUtils::getRandomShape() {
  static bool check = true;
  if (check) {
    srand(time(NULL));
    check = false;
  }

  double a = rand() % 10000 / 1000. + 1;
  double b = rand() % 10000 / 1000. + 1;

  auto createCircle = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Circle>(a + b);
  };

  auto createEllipse = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Ellipse>(a, b);
  };

  auto createHelix = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Helix>(a, b);
  };

  std::vector<std::function<std::shared_ptr<Curve>(double, double)>> creators{createCircle, createEllipse, createHelix};

  int index = rand() % 3;
  return creators[index](a, b);
}

/**
 * Print point and derivative from each shape in list at π/4.
 * @param curves List of shapes.
 */
void CurveUtils::printShapeVec(const shape_vec &curves) {
  std::cout << std::fixed << std::setprecision(3);
  for (auto &&el : curves) {
    auto point = el->getPoint(M_PI_4);
    auto derivative = el->getDerivative(M_PI_4);
    std::cout << "Point: ("
              << std::setw(7) << point.x << ", "
              << std::setw(7) << point.y << ", "
              << std::setw(7) << point.z << ")   "
              << "Derivative: ("
              << std::setw(7) << derivative.x << ", "
              << std::setw(7) << derivative.y << ", "
              << std::setw(7) << derivative.z << ")" << " - " << el->getName() << "\n";

  }
}

/**
 * Fill 'second' list only with Circle from 'first' list.
 * @param first Original list of shapes.
 * @param second Where to put Circles.
 */
void CurveUtils::fillOnlyCircles(const shape_vec &first, shape_vec &second) {
  std::vector<std::shared_ptr<Circle>> circlesContainer;
  for (auto &&el : first) {
    if (auto circlePtr = std::dynamic_pointer_cast<Circle>(el)) {
      second.push_back(circlePtr);
    }
  }
}

/**
 * Check which Circle bigger. Extra func for sort
 * @param a First Circle pointer.
 * @param b Second Circle pointer.
 * @return True if 'a' circle smaller than 'b' circle.
 */
bool CurveUtils::compareRadii(const std::shared_ptr<Curve> &a, const std::shared_ptr<Curve> &b) {
  auto circle_A = std::dynamic_pointer_cast<Circle>(a);
  auto circle_B = std::dynamic_pointer_cast<Circle>(b);
  if (nullptr == circle_A || nullptr == circle_B) {
    throw std::runtime_error("el is not a Circle");
  }
  return circle_A->getRadius() < circle_B->getRadius();
}

/**
 * Order list of Circles by their size.
 * @param circles List of Circles for ordering.
 */
void CurveUtils::sortCircle(shape_vec &circles) {
  std::sort(circles.begin(), circles.end(), compareRadii);
}

/**
 * Count all radii of Circles in list.
 * @param circles List of Circles.
 * @return Total of radii.
 */
double CurveUtils::getSumRadii(const shape_vec &circles) {
  auto lambda = [](double sum, const std::shared_ptr<Curve>& el) {
    auto tmp = std::dynamic_pointer_cast<Circle>(el);
    if(nullptr == tmp) {
      throw std::runtime_error("elem is not a Circle");
    }
    return sum + tmp->getRadius();
  };

  return std::accumulate(circles.begin(), circles.end(), 0.0, lambda);

}


// I have done multi-threading, but it's leaks if i use valgrind.
//double CurveUtils::getSumRadiiMultiThreading(const shape_vec &circles) {
//  double totalRadius = 0.0;
//
//#pragma omp parallel for reduction(+:totalRadius)
//  for (size_t i = 0; i < circles.size(); ++i) {
//    int thread_id = omp_get_thread_num();
//    std::cout << "Thread ID: " << thread_id << std::endl;
//    auto tmp = std::dynamic_pointer_cast<Circle>(circles[i]);
//    if(nullptr == tmp) {
//      throw std::runtime_error("elem is not a Circle");
//    }
//    totalRadius += tmp->getRadius();
//  }
//#pragma omp barrier
//  return totalRadius;
//}
