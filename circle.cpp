#include "circle.h"

Circle::Circle(double r) {
  if (r <= 0) {
    throw std::invalid_argument("Incorrect radius");
  }
  m_radius = r;
}
Circle::Circle(const Circle& other):m_radius(other.m_radius) {}
Circle::Circle(Circle&& other) noexcept : m_radius(other.m_radius) {}
Circle::~Circle() {};

Point3D Circle::getPoint(double t) const {
  Point3D result = {
    .x = m_radius * cos(t),
    .y = m_radius * sin(t),
    .z = 0.0
  };
  return result;
}
Vector3D Circle::getDerivative(double t) const {
  Vector3D result = {
      .x = -m_radius * sin(t),
      .y = m_radius * cos(t),
      .z = 0.0
  };
  return result;
}
