#pragma once

namespace automat {

    class Direction
    {
    public:
        Direction() = default;
        Direction(int rawDirection, bool accessable = true);

        ~Direction() = default;

        Direction(const Direction& src);
        Direction& operator=(const Direction& src);

    public:
        operator int();
        operator bool();

    public:
        bool operator==(const Direction& rightVal) const;
        bool operator!=(const Direction& rightVal) const;

    public:
        int Azimuth = 0;
        bool Access = true;

    public:

        
    };

}

