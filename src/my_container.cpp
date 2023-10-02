//#include <omp.h>

#include "my_container.h"

/**
 * Default constructor.
 */
MyContainer::MyContainer() {
  m_curves.clear();
  srand(time(NULL));
}

/**
 * Make random shape (Circle, Ellipse, Helix) with random numbers.
 */
void MyContainer::generateRandomShapes(int count) {
  if (count <= 0) throw std::invalid_argument("Incorrect value");

  auto createCircle = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Circle>(a + b);
  };

  auto createEllipse = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Ellipse>(a, b);
  };

  auto createHelix = [](double a, double b) -> std::shared_ptr<Curve> {
    return std::make_shared<Helix>(a, b);
  };

  std::vector<std::function<std::shared_ptr<Curve>(double, double)>>
      creators{createCircle, createEllipse, createHelix};

  for (; count != 0; --count) {
    double a = rand() % 10000 / 1000. + 1;
    double b = rand() % 10000 / 1000. + 1;
    int index = rand() % 3;
    m_curves.push_back(creators[index](a, b));
  }

}

/**
 * Print point and derivative from each shape in list at π/4.
 */
void MyContainer::printShapes() {
  std::cout << std::fixed << std::setprecision(3);
  for (auto &&el : m_curves) {
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
 * Fill container only with Circle from 'other' container.
 * @param other Where to put Circles.
 */
void MyContainer::filterOnlyCircles(const MyContainer& other) {
  for (auto &&el : other.m_curves) {
    if (auto circlePtr = std::dynamic_pointer_cast<Circle>(el)) {
      m_curves.push_back(circlePtr);
    }
  }
}

/**
 * Order list of Circles by their size.
 */
void MyContainer::sortCircles() {
  std::sort(m_curves.begin(), m_curves.end(), compareRadii);
}

/**
 * Count all radii of Circles in list.
 * @return Total of radii.
 */
double MyContainer::getSumRadii() {
  auto lambda = [](double sum, const std::shared_ptr<Curve>& el) {
    auto tmp = std::dynamic_pointer_cast<Circle>(el);
    if(nullptr == tmp) {
      throw std::runtime_error("elem is not a Circle");
    }
    return sum + tmp->getRadius();
  };

  return std::accumulate(m_curves.begin(), m_curves.end(), 0.0, lambda);

}

/**
 * Check which Circle bigger. Extra func for sort
 * @param a First Circle pointer.
 * @param b Second Circle pointer.
 * @return True if 'a' circle smaller than 'b' circle.
 */
bool MyContainer::compareRadii(const std::shared_ptr<Curve> &a, const std::shared_ptr<Curve> &b) {
  auto circle_A = std::dynamic_pointer_cast<Circle>(a);
  auto circle_B = std::dynamic_pointer_cast<Circle>(b);
  if (nullptr == circle_A || nullptr == circle_B) {
    throw std::runtime_error("el is not a Circle");
  }
  return circle_A->getRadius() < circle_B->getRadius();
}

/**
 * I have done multi-threading, but it's leaks if I use valgrind. It's my first working with <omp.h> library.
 * Maybe valgrind is wrong =)
 * @return Total of radii.
 */
//double MyContainer::getSumRadiiMultiThreading() {
//  double totalRadius = 0.0;
//  omp_set_dynamic(0);
//  omp_set_num_threads(4);
//#pragma omp parallel for reduction(+:totalRadius)
//  for (size_t i = 0; i < m_curves.size(); ++i) {
//// Numbers of threads, just for logging
////    int thread_id = omp_get_thread_num();
////    std::cout << "Thread ID: " << thread_id << std::endl;
//    auto tmp = std::dynamic_pointer_cast<Circle>(m_curves[i]);
//    if(nullptr == tmp) {
//      throw std::runtime_error("elem is not a Circle");
//    }
//    totalRadius += tmp->getRadius();
//  }
//#pragma omp barrier
//  return totalRadius;
//}
