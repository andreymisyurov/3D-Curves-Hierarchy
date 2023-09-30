#include "funcs.h"

std::shared_ptr<Curve> getRandomShape() {
  static bool check = true;
  if (check) {
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

void printShapeVec(const shape_vec &curves) {
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

void fillOnlyCircles(const shape_vec &first, shape_vec &second) {
  std::vector<std::shared_ptr<Circle>> circlesContainer;
  for (auto &&el : first) {
    if (auto circlePtr = std::dynamic_pointer_cast<Circle>(el)) {
      second.push_back(circlePtr);
    }
  }
}

bool compareRadii(const std::shared_ptr<Curve> &a, const std::shared_ptr<Curve> &b) {
  auto circle_A = std::dynamic_pointer_cast<Circle>(a);
  auto circle_B = std::dynamic_pointer_cast<Circle>(b);
  if (nullptr == circle_A || nullptr == circle_B) {
    throw std::runtime_error("el is not a Circle");
  }
  return circle_A->getRadius() < circle_B->getRadius();
}

void sortCircle(shape_vec &circles) {
  std::sort(circles.begin(), circles.end(), compareRadii);
}



double getSumRadii(const shape_vec &circles) {
  auto lambda = [](double sum, const std::shared_ptr<Curve>& el) {
    auto tmp = std::dynamic_pointer_cast<Circle>(el);
    if(nullptr == tmp) {
      throw std::runtime_error("el is not a Circle");
    }
    return sum + tmp->getRadius();
  };

  return std::accumulate(circles.begin(), circles.end(), 0.0, lambda);

}