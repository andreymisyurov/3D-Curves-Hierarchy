#include "circle.h"

Circle::Circle(double r) : Ellipse(r, r) { }

Circle::Circle(const Circle& other): Ellipse(other) {}
Circle::Circle(Circle&& other) noexcept : Ellipse(std::move(other)) {}
Circle::~Circle() {};
