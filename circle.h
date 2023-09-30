#include "curve.h"

class Circle: public Curve {
 public:
  Circle() = delete;
  Circle(double r);
  Circle(const Circle& other);
  Circle(Circle&& other) noexcept;
  ~Circle();

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;

 private:
  double m_radius;
};