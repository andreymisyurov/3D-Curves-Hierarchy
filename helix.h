#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

class Helix: public Curve {
 public:
  Helix() = delete;
  Helix(double r, double step);
  Helix(const Helix& other);
  Helix(Helix&& other) noexcept;
  ~Helix();

  Point3D getPoint(double t) const override;
  Vector3D getDerivative(double t) const override;

 private:
  double m_r;
  double m_step;
};

#endif // HELIX_H