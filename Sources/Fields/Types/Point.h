#pragma once

#include <string>

class Point
{
public:
    Point();
    Point(int x, int y);
    Point(const Point&);
    
    ~Point() = default;

public:
    Point operator+(const Point& val) const;
    Point operator-(const Point& val) const;
    bool operator==(const Point& val) const;
    bool operator!=(const Point& val) const;
    Point operator=(const Point& src);
    Point operator+=(const Point& src);
    Point operator-=(const Point& src);
    Point operator--();
    Point operator--(int);
    Point operator++();
    Point operator++(int);

public:
    int X, Y;

    std::string s_str() const;

    Point GetVectorTo(const Point& aim) const;
    double GetRangeTo(const Point& aim) const;
    
};

