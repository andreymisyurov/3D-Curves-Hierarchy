#ifndef D_SURVES_HIERARCHY_CURVE_H
#define D_SURVES_HIERARCHY_CURVE_H

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
  virtual ~Curve() {}
};

#endif // D_SURVES_HIERARCHY_CURVE_H