#include "funcs.h"

std::shared_ptr<Curve> getRandomShape() {
  static bool check = true;
  if(check) {
    srand(time(NULL));
    check = false;
  }

  double a = rand() % 10000 / 1000.;
  double b = rand() % 10000 / 1000.;

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

void printShapeVec(const shape_vec& curves) {
  std::cout << std::fixed << std::setprecision(3);
  for (const auto &curve : curves) {
    auto point = curve->getPoint(M_PI_4);
    auto derivative = curve->getDerivative(M_PI_4);
    std::cout << "Point: ("
              << std::setw(7) << point.x << ", "
              << std::setw(7) << point.y << ", "
              << std::setw(7) << point.z << ")   "
              << "Derivative: ("
              << std::setw(7) << derivative.x << ", "
              << std::setw(7) << derivative.y << ", "
              << std::setw(7) << derivative.z << ")\n";

  }
}