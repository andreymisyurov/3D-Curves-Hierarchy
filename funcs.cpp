#include "funcs.h"

std::shared_ptr<Curve> getRandomShape() {
  srand(time(NULL));

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