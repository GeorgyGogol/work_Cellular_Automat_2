#pragma once

class Direction
{
public:
    Direction() = default;
    Direction(int rawDirection, bool accessable = true);
    ~Direction() = default;

    Direction(const Direction& src);
    Direction& operator=(const Direction& src);

    bool operator==(const Direction& rightVal);
    bool operator!=(const Direction& rightVal);

    operator int();
    operator bool();

public:
    int Azimuth = 0;
    bool Access = true;

public:

    
};

