#include "helix.h"

Helix::Helix(double r, double step) {
  if (r <= 0) {
    throw std::invalid_argument("Incorrect value");
  }

  m_r = r;
  m_step = step;

}

Helix::Helix(const Helix& other) : m_r(other.m_r), m_step(other.m_step) { }

Helix::Helix(Helix&& other) noexcept : m_r(other.m_r), m_step(other.m_step) { }

Helix::~Helix() { }

Point3D Helix::getPoint(double t) const {
  Point3D result = {
      .x = m_r * cos(t),
      .y = m_r * sin(t),
      .z = m_step * (t / (2 * M_PI))
  };
  return result;
}

Vector3D Helix::getDerivative(double t) const {
  Vector3D result = {
      .x = -m_r * sin(t),
      .y = m_r * cos(t),
      .z = m_step / (2 * M_PI)
  };
  return result;
}
