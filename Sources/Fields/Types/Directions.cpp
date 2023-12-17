#include "stdafx.h"
#include "Directions.h"

using namespace automat;

Directions::Directions(int nDirs)
    : NDirections(nDirs)
{
}

Directions::Directions(Direction maxDirection)
    : NDirections(int(maxDirection))
{
}

Directions::operator int()
{
    return int(NDirections);
}

int Directions::getRawDirections() const
{
    return int(NDirections);
}

bool Directions::isDirectValide(int intDirection) const
{
    return intDirection >= 0 && intDirection < int(NDirections);
}

void Directions::normalize(int &rawDirection) const
{
    if (isDirectValide(rawDirection)) return;

    int fullRound = int(NDirections);
    if (rawDirection < 0) {
        while (rawDirection < 0)
        {
            rawDirection += fullRound;
        }
    }
    else {
        while (rawDirection >= fullRound)
        {
            rawDirection -= fullRound;
        }
    }
}

Direction Directions::getDirection(int rawDirection) const
{
    normalize(rawDirection);
    return Direction(rawDirection);
}
