#ifndef ELLIPSE_H
#define ELLIPSE_H

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
  double getA() const;
  double getB() const;

 private:
  double m_a;
  double m_b;
};

#endif // ELLIPSE_H