#include "circle.h"
#include <gtest/gtest.h>
#include "ellipse.h"
#include "helix.h"
#include "funcs.h"

// Tests for circle

TEST(CircleTest, Constructor) {
Circle circle(5.0);
}

TEST(CircleTest, ConstructorZero) {
EXPECT_THROW(Circle circle(0.0), std::invalid_argument);
}

TEST(CircleTest, ConstructorNegative) {
EXPECT_THROW(Circle circle(-5.0), std::invalid_argument);
}

TEST(CircleTest, GetPointTest) {
Circle c(1);
Point3D p = c.getPoint(0);
ASSERT_NEAR(p.x, 1.0, 1e-6);
ASSERT_NEAR(p.y, 0.0, 1e-6);
ASSERT_NEAR(p.z, 0.0, 1e-6);
}

TEST(CircleTest, GetDerivativeTest) {
Circle c(1);
Vector3D v = c.getDerivative(0);
ASSERT_NEAR(v.x, 0.0, 1e-6);
ASSERT_NEAR(v.y, 1.0, 1e-6);
ASSERT_NEAR(v.z, 0.0, 1e-6);
}

TEST(CircleTest, CopyConstructorTest) {
Circle c1(5);
Circle c2(c1);
ASSERT_NEAR(c1.getPoint(0).x, c2.getPoint(0).x, 1e-6);
ASSERT_NEAR(c1.getPoint(0).y, c2.getPoint(0).y, 1e-6);
}

TEST(CircleTest, MoveConstructorTest) {
Circle c1(5);
Circle c2(std::move(c1));
ASSERT_NEAR(c2.getPoint(0).x, 5.0, 1e-6);
ASSERT_NEAR(c2.getPoint(0).y, 0.0, 1e-6);
}

// Tests for ellipse

TEST(EllipseTest, Constructor) {
Ellipse ellipse(3.0, 4.0);
}

TEST(EllipseTest, ConstructorInvalidA) {
EXPECT_THROW(Ellipse ellipse(0.0, 4.0), std::invalid_argument);
}

TEST(EllipseTest, ConstructorInvalidB) {
EXPECT_THROW(Ellipse ellipse(3.0, 0.0), std::invalid_argument);
}

TEST(EllipseTest, GetPointTest) {
Ellipse e(3, 4);
Point3D p = e.getPoint(0);
ASSERT_NEAR(p.x, 3.0, 1e-6);
ASSERT_NEAR(p.y, 0.0, 1e-6);
ASSERT_NEAR(p.z, 0.0, 1e-6);
}

TEST(EllipseTest, GetDerivativeTest) {
Ellipse e(3, 4);
Vector3D v = e.getDerivative(0);
ASSERT_NEAR(v.x, 0.0, 1e-6);
ASSERT_NEAR(v.y, 4.0, 1e-6);
ASSERT_NEAR(v.z, 0.0, 1e-6);
}

TEST(EllipseTest, CopyConstructorTest) {
Ellipse e1(3, 4);
Ellipse e2(e1);
ASSERT_NEAR(e1.getPoint(0).x, e2.getPoint(0).x, 1e-6);
ASSERT_NEAR(e1.getPoint(0).y, e2.getPoint(0).y, 1e-6);
}

TEST(EllipseTest, MoveConstructorTest) {
Ellipse e1(3, 4);
Ellipse e2(std::move(e1));
ASSERT_NEAR(e2.getPoint(0).x, 3.0, 1e-6);
ASSERT_NEAR(e2.getPoint(0).y, 0.0, 1e-6);
}


TEST(HelixTest, Constructor) {
Helix helix(5.0, 2.0);
}

TEST(HelixTest, ConstructorInvalidRadius) {
EXPECT_THROW(Helix helix(0.0, 2.0), std::invalid_argument);
}

TEST(HelixTest, OneRotateTest) {
Helix h(1, 2);
Point3D p = h.getPoint(0);
ASSERT_NEAR(p.x, 1.0, 1e-6);
ASSERT_NEAR(p.y, 0.0, 1e-6);
ASSERT_NEAR(p.z, 0.0, 1e-6);

Point3D p2 = h.getPoint(M_PI*2);
ASSERT_NEAR(p2.x, 1.0, 1e-6);
ASSERT_NEAR(p2.y, 0.0, 1e-6);
ASSERT_NEAR(p2.z, 2.0, 1e-6);
}

TEST(HelixTest, GetDerivativeTest) {
Helix h(1, 2);
Vector3D v = h.getDerivative(0);
ASSERT_NEAR(v.x, 0.0, 1e-6);
ASSERT_NEAR(v.y, 1.0, 1e-6);
ASSERT_NEAR(v.z, 2.0 / (2 * M_PI), 1e-6);
}

TEST(HelixTest, CopyConstructorTest) {
Helix h1(5, 2);
Helix h2(h1);
ASSERT_NEAR(h1.getPoint(0).x, h2.getPoint(0).x, 1e-6);
ASSERT_NEAR(h1.getPoint(0).y, h2.getPoint(0).y, 1e-6);
ASSERT_NEAR(h1.getPoint(0).z, h2.getPoint(0).z, 1e-6);
}

TEST(HelixTest, MoveConstructorTest) {
Helix h1(5, 2);
Helix h2(std::move(h1));
ASSERT_NEAR(h2.getPoint(0).x, 5.0, 1e-6);
ASSERT_NEAR(h2.getPoint(0).y, 0.0, 1e-6);
ASSERT_NEAR(h2.getPoint(0).z, 0.0, 1e-6);
}

TEST(HelixTest, StepIsZero) {
double radius = 5.0;
Circle c(radius);
Helix h(radius, 0.0);

Point3D circlePoint = c.getPoint(0);
Point3D helixPoint = h.getPoint(0);

ASSERT_NEAR(circlePoint.x, helixPoint.x, 1e-6);
ASSERT_NEAR(circlePoint.y, helixPoint.y, 1e-6);
ASSERT_NEAR(circlePoint.z, helixPoint.z, 1e-6);

Vector3D circleDerivative = c.getDerivative(0);
Vector3D helixDerivative = h.getDerivative(0);

ASSERT_NEAR(circleDerivative.x, helixDerivative.x, 1e-6);
ASSERT_NEAR(circleDerivative.y, helixDerivative.y, 1e-6);
ASSERT_NEAR(circleDerivative.z, helixDerivative.z, 1e-6);
}

TEST(CurveUtilsTest, getRandomShape) {
auto shape = CurveUtils::getRandomShape();
EXPECT_TRUE(shape != nullptr);
bool isCircle = std::dynamic_pointer_cast<Circle>(shape) != nullptr;
bool isEllipse = std::dynamic_pointer_cast<Ellipse>(shape) != nullptr;
bool isHelix = std::dynamic_pointer_cast<Helix>(shape) != nullptr;
EXPECT_TRUE(isCircle || isEllipse || isHelix);
}


TEST(CurveUtilsTest, fillOnlyCircles) {
shape_vec src = {
    std::make_shared<Circle>(5.0),
    std::make_shared<Helix>(5.0, 2.0),
    std::make_shared<Ellipse>(3.0, 4.0),
    std::make_shared<Circle>(7.0)
};
shape_vec dest;
CurveUtils::fillOnlyCircles(src, dest);
EXPECT_EQ(dest.size(), 2);
for (auto&& shape : dest) {
  EXPECT_TRUE(std::dynamic_pointer_cast<Circle>(shape) != nullptr);
}
}

TEST(CurveUtilsTest, compareRadii) {
auto circle1 = std::make_shared<Circle>(5.0);
auto circle2 = std::make_shared<Circle>(7.0);
EXPECT_TRUE(CurveUtils::compareRadii(circle1, circle2));
EXPECT_FALSE(CurveUtils::compareRadii(circle2, circle1));
}

TEST(CurveUtilsTest, sortCircle) {
shape_vec circles = {
    std::make_shared<Circle>(7.0),
    std::make_shared<Circle>(5.0)
};
CurveUtils::sortCircle(circles);
auto circle1 = std::dynamic_pointer_cast<Circle>(circles[0]);
auto circle2 = std::dynamic_pointer_cast<Circle>(circles[1]);
EXPECT_TRUE(circle1->getRadius() < circle2->getRadius());
}

TEST(CurveUtilsTest, getSumRadii) {
shape_vec circles = {
    std::make_shared<Circle>(5.0),
    std::make_shared<Circle>(7.0)
};
double sum = CurveUtils::getSumRadii(circles);
EXPECT_NEAR(sum, 12.0, 1e-6);
}
