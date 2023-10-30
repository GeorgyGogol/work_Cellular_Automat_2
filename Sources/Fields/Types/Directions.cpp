#include "Directions.h"

Directions::Directions(int nDirs)
    : NDirections(nDirs)
{
}

/* Directions::Directions(int direction, int nDirs)
    : NDirections(nDirs)
    , Azimuth(direction)
{
} */

int Directions::getDirections() const
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
