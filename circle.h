#ifndef D_SURVES_HIERARCHY_CIRCLE_H
#define D_SURVES_HIERARCHY_CIRCLE_H

#include "ellipse.h"

class Circle: public Ellipse {
 public:
  Circle() = delete;
  Circle(double r);
  Circle(const Circle& other);
  Circle(Circle&& other) noexcept;
  ~Circle();
};

#endif // D_SURVES_HIERARCHY_CIRCLE_H