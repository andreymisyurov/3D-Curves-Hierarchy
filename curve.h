#ifndef CURVE_H
#define CURVE_H

#include <cmath>
#include <stdexcept>
#include <utility>


struct Point3D {
  double x;
  double y;
  double z;
};

struct Vector3D {
  double x;
  double y;
  double z;
};

class Curve {
 public:
  virtual Point3D getPoint(double t) const = 0;
  virtual Vector3D getDerivative(double t) const = 0;
  virtual std::string getName() const {
    return m_name;
  }
  virtual ~Curve() {}
 protected:
  std::string m_name;
  explicit Curve(const std::string& name) : m_name(name) {}

};

#endif // CURVE_H