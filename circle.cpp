#include "circle.h"

Circle::Circle(double r) : Ellipse(r, r) {
  m_name = "Circle";
}

Circle::Circle(const Circle& other): Ellipse(other) {
  m_name = "Circle";
}
Circle::Circle(Circle&& other) noexcept : Ellipse(std::move(other)) {
  m_name = "Circle";
}
Circle::~Circle() {};

double Circle::getRadius() const {
  return getA();
}
