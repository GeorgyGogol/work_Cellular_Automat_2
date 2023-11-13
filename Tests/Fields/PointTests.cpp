#include "pch.h"
#include "Point.h"

TEST(PointTests, Base)
{
    Point a (5, 5);

    ASSERT_EQ(a.X, 5);
    ASSERT_EQ(a.Y, 5);

    Point b;
    ASSERT_EQ(b.X, 0);
    ASSERT_EQ(b.Y, 0);

    a = b;
    ASSERT_EQ(a.X, 0);
    ASSERT_EQ(a.Y, 0);

    ASSERT_EQ(a == b, true) << "Operator equal is not worked";
    ASSERT_NE(a, Point(2, 2)) << "Operator not equal is not worked";
}

TEST(PointTests, Simple_Operators)
{
    Point a(0, 0);
    Point b(5, 5);
    Point c;

    c = a + b;
    EXPECT_EQ(c.X, 5);
    EXPECT_EQ(c.Y, 5);
    ASSERT_EQ(c, Point(5, 5));

    c = a - Point(4, 4);
    EXPECT_EQ(c.X, -4);
    EXPECT_EQ(c.Y, -4);
    ASSERT_EQ(c, Point(-4, -4));

}

TEST(PointTests, Operations)
{
    Point a(0, 0);
    Point b(5, 5);

    ASSERT_TRUE(b - a == Point(5, 5));
}

TEST(PointTests, Simple_Operators_2)
{
    Point a(0, 0);
    Point b(5, 5);

    a += b;
    EXPECT_EQ(a.X, 5);
    EXPECT_EQ(a.Y, 5);
    ASSERT_EQ(a, Point(5, 5));

    b -= Point(5, 5);
    EXPECT_EQ(b.X, 0);
    EXPECT_EQ(b.Y, 0);
    ASSERT_EQ(b, Point(0, 0));
}

TEST(PointTests, IncrementOperators)
{
    Point a(0, 0);
    Point b;

    b = a++;
    ASSERT_NE(a, b);
    EXPECT_EQ(a.X, 1);
    EXPECT_EQ(a.Y, 1);
    EXPECT_EQ(b.X, 0);
    EXPECT_EQ(b.Y, 0);
    ASSERT_EQ(a, Point(1, 1));
    
    b = ++a;
    ASSERT_EQ(a, b);
    EXPECT_EQ(a.X, 2);
    EXPECT_EQ(a.Y, 2);
    EXPECT_EQ(b.X, 2);
    EXPECT_EQ(b.Y, 2);
    ASSERT_EQ(a, Point(2, 2));

    a = Point(-3, -3);

    b = a--;
    ASSERT_NE(a, b);
    EXPECT_EQ(a.X, -4);
    EXPECT_EQ(a.Y, -4);
    EXPECT_EQ(b.X, -3);
    EXPECT_EQ(b.Y, -3);
    ASSERT_EQ(a, Point(-4, -4));

    b = --a;
    ASSERT_EQ(a, b);
    EXPECT_EQ(a.X, -5);
    EXPECT_EQ(a.Y, -5);
    EXPECT_EQ(b.X, -5);
    EXPECT_EQ(b.Y, -5);
    ASSERT_EQ(a, Point(-5, -5));

}

TEST(PointTests, s_str)
{
    Point p = Point(3, 3);
    ASSERT_STREQ(p.s_str().c_str(), "(3, 3)");
}

TEST(PointTests, Vector)
{
    Point A(10, 10);
    Point B(20, 20);
    Point vector = A.GetVectorTo(B);

    ASSERT_EQ(vector.X, 10);
    ASSERT_EQ(vector.Y, 10);
    ASSERT_EQ(vector, Point(10, 10));
    //ASSERT_EQ(vector, B - A);
}

TEST(PointTests, Range)
{
    Point A(0, 0);
    Point B(10, 0);
    double range = A.GetRangeTo(B);

    ASSERT_DOUBLE_EQ(range, 10);
}

