#include "stdafx.h"
#include "Point.h"

#include <cmath>

Point::Point()
    : X(0), Y(0)
{
}

Point::Point(int x, int y)
    : X(x), Y(y)
{
}

Point::Point(const Point& src)
{
    X = src.X;
    Y = src.Y;
}

Point& Point::operator=(const Point& src)
{
    if (this != &src) {
        X = src.X;
        Y = src.Y;
    }
    return *this;
}

bool Point::operator==(const Point& val) const
{
    bool bX, bY;
    bX = X == val.X;
    bY = Y == val.Y;
    return bX && bY;
}

bool Point::operator!=(const Point& val) const
{
    return !(*this == val);
}

Point Point::operator+(const Point& val) const
{
    Point out;
    out.X = X + val.X;
    out.Y = Y + val.Y;
    return out;
}

Point Point::operator-(const Point& val) const
{
    Point out;
    out.X = X - val.X;
    out.Y = Y - val.Y;
    return out;
}

Point& Point::operator+=(const Point& src)
{
    X += src.X;
    Y += src.Y;
    return *this;
}

Point& Point::operator-=(const Point& src)
{
    X -= src.X;
    Y -= src.Y;
    return *this;
}

Point& Point::operator--()
{
    X = X - 1;
    Y = Y - 1;
    return *this;
}

Point Point::operator--(int)
{
    Point t(*this);
    X = X - 1;
    Y = Y - 1;
    return t;
}

Point& Point::operator++()
{
    X = X + 1;
    Y = Y + 1;
    return *this;
}

Point Point::operator++(int)
{
    Point t(*this);
    X = X + 1;
    Y = Y + 1;
    return t;
}


std::string Point::s_str() const
{
    std::string out = "(";
    out += std::to_string(X);
    out += ", ";
    out += std::to_string(Y);
    out += ")";

    return out;
}

//const char* Point::c_str() const
//{
//    return s_str().c_str();
//}

Point Point::GetVectorTo(const Point& aim) const
{
    return aim - *this;
}

double Point::GetRangeTo(const Point& aim) const
{
    using namespace std;
    Point vec = GetVectorTo(aim);
    return sqrt(pow(vec.X, 2) + pow(vec.Y, 2));
}

