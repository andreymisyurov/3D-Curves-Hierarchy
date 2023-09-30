#ifndef RANDOM_SHAPE_H
#define RANDOM_SHAPE_H

#include <memory>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

std::shared_ptr<Curve> getRandomShape();

#endif // RANDOM_SHAPE_H
