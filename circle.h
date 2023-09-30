#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"

class Circle: public Ellipse {
 public:
  Circle() = delete;
  Circle(double r);
  Circle(const Circle& other);
  Circle(Circle&& other) noexcept;
  ~Circle();
};

#endif // CIRCLE_H