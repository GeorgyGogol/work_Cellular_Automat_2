#include "DirectionsStatuses.h"

DirectionsStatuses::DirectionsStatuses(int nDirs)
    : Directions(nDirs)
{
    DirectionsStats = new bool[nDirs] {true};
}

DirectionsStatuses::~DirectionsStatuses()
{
    delete[] DirectionsStats;
}

bool DirectionsStatuses::getStatus(int direction) const
{
    normalize(direction);
    return DirectionsStats[direction];
}

void DirectionsStatuses::setStatus(int direction, bool status)
{
    normalize(direction);
    DirectionsStats[direction] = status;
}

Direction DirectionsStatuses::getDirection(int rawDirection) const
{
    normalize(rawDirection);
    return Direction(rawDirection, DirectionsStats[rawDirection]);
}

