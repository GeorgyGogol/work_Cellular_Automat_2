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
    int trueDirection = direction;
    Normalize(trueDirection);
    return DirectionsStats[trueDirection];
}

void DirectionsStatuses::setStatus(int direction, bool status)
{
    int trueDirection = direction;
    Normalize(trueDirection);
    DirectionsStats[trueDirection] = status;
}

