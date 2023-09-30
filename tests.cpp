#include "circle.h"
#include <gtest/gtest.h>
#include "ellipse.h"


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
ASSERT_EQ(p.x, 1.0);
ASSERT_EQ(p.y, 0.0);
ASSERT_EQ(p.z, 0.0);
}

TEST(CircleTest, GetDerivativeTest) {
Circle c(1);
Vector3D v = c.getDerivative(0);
ASSERT_EQ(v.x, 0.0);
ASSERT_EQ(v.y, 1.0);
ASSERT_EQ(v.z, 0.0);
}

TEST(CircleTest, CopyConstructorTest) {
Circle c1(5);
Circle c2(c1);
ASSERT_EQ(c1.getPoint(0).x, c2.getPoint(0).x);
ASSERT_EQ(c1.getPoint(0).y, c2.getPoint(0).y);
}

TEST(CircleTest, MoveConstructorTest) {
Circle c1(5);
Circle c2(std::move(c1));
ASSERT_EQ(c2.getPoint(0).x, 5.0);
ASSERT_EQ(c2.getPoint(0).y, 0.0);
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
ASSERT_EQ(p.x, 3.0);
ASSERT_EQ(p.y, 0.0);
ASSERT_EQ(p.z, 0.0);
}

TEST(EllipseTest, GetDerivativeTest) {
Ellipse e(3, 4);
Vector3D v = e.getDerivative(0);
ASSERT_EQ(v.x, 0.0);
ASSERT_EQ(v.y, 4.0);
ASSERT_EQ(v.z, 0.0);
}

TEST(EllipseTest, CopyConstructorTest) {
Ellipse e1(3, 4);
Ellipse e2(e1);
ASSERT_EQ(e1.getPoint(0).x, e2.getPoint(0).x);
ASSERT_EQ(e1.getPoint(0).y, e2.getPoint(0).y);
}

TEST(EllipseTest, MoveConstructorTest) {
Ellipse e1(3, 4);
Ellipse e2(std::move(e1));
ASSERT_EQ(e2.getPoint(0).x, 3.0);
ASSERT_EQ(e2.getPoint(0).y, 0.0);
}