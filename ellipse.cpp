#include "ellipse.h"


Ellipse::Ellipse(double a, double b): Curve("Ellipse") {
  if (a <= 0 || b <= 0) {
    throw std::invalid_argument("Incorrect value");
  }
  m_a = a;
  m_b = b;
}

Ellipse::Ellipse(const Ellipse& other): Curve("Ellipse"), m_a(other.m_a), m_b(other.m_b) { }
Ellipse::Ellipse(Ellipse&& other) noexcept : Curve("Ellipse"), m_a(other.m_a), m_b(other.m_b) { }
Ellipse::~Ellipse() {};

Point3D Ellipse::getPoint(double t) const {
  Point3D result = {
      .x = m_a * cos(t),
      .y = m_b * sin(t),
      .z = 0.0
  };
  return result;
}

Vector3D Ellipse::getDerivative(double t) const {
  Vector3D result = {
      .x = -m_a * sin(t),
      .y = m_b * cos(t),
      .z = 0.0
  };
  return result;
}