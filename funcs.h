#ifndef RANDOM_SHAPE_H
#define RANDOM_SHAPE_H

#include <memory>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <iostream>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using shape_vec = std::vector<std::shared_ptr<Curve>>;

std::shared_ptr<Curve> getRandomShape();
void printShapeVec(const shape_vec& curves);
void fillOnlyCircles(const shape_vec& first, shape_vec& second);

#endif // RANDOM_SHAPE_H
