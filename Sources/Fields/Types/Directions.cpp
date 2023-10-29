#include "Directions.h"

Directions::Directions(int nDirs)
    : NDirections(nDirs)
{
}

Directions::Directions(int direction, int nDirs)
    : NDirections(nDirs)
    , Azimuth(direction)
{
}

void Directions::Normalize(int &direction) const
{
    if (isDirectValide(direction)) return;

    int fullRound = int(NDirections);
    if (direction < 0) {
        while (direction < 0)
        {
            direction += fullRound;
        }
    }
    else {
        while (direction >= fullRound)
        {
            direction -= fullRound;
        }
    }
}

int Directions::getDirections() const
{
    return int(NDirections);
}

int Directions::getDirection() const
{
    return int(Azimuth);
}

bool Directions::isDirectValide(int direction) const
{
    return direction >= 0 && direction < int(NDirections);
}

