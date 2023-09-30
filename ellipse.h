#ifndef D_SURVES_HIERARCHY_ELLIPSE_H
#define D_SURVES_HIERARCHY_ELLIPSE_H

#include "curve.h"

class Ellipse: public Curve {
 public:
  Ellipse() = delete;
  Ellipse(double a, double b);
  Ellipse(const Ellipse& other);
  Ellipse(Ellipse&& other) noexcept;
  ~Ellipse();

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;

 private:
  double m_a;
  double m_b;
};

#endif // D_SURVES_HIERARCHY_ELLIPSE_H