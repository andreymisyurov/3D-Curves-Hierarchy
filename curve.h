#include <cmath>


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
