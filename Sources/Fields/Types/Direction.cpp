#include "Direction.h"

Direction::Direction(int rawDirection, bool accessable)
    : Azimuth(rawDirection)
    , Access(accessable)
{
}

Direction::Direction(const Direction &src)
    : Azimuth(src.Azimuth)
    , Access(src.Access)
{
}

Direction &Direction::operator=(const Direction &src)
{
    if (this != &src)
    {
        Azimuth = src.Azimuth;
        Access = src.Access;
    }
    return *this;
}

Direction::operator int()
{
    return Azimuth;
}

Direction::operator bool()
{
    return Access;
}

bool Direction::operator==(const Direction &rightVal)
{
    return Azimuth == rightVal.Azimuth;
}

bool Direction::operator!=(const Direction &rightVal)
{
    return !(*this == rightVal);
}

