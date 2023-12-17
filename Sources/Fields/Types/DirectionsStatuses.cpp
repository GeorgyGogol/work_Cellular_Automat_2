#include "stdafx.h"
#include "DirectionsStatuses.h"

using namespace automat;

DirectionsStatuses::DirectionsStatuses(int nDirs)
    : Directions(nDirs)
{
    if (nDirs > 0) {
        DirectionsStats = new bool[nDirs];
        resetStatuses(true);
    }
}

DirectionsStatuses::DirectionsStatuses(const DirectionsStatuses& src) noexcept
    : Directions(src.getRawDirections())
{
    int nDirs = src.getRawDirections();
    if (src.isValide()) {
        DirectionsStats = new bool[nDirs];
        for (int i = 0; i < nDirs; ++i) {
            DirectionsStats[i] = src.DirectionsStats[i];
        }
    }
}

DirectionsStatuses::DirectionsStatuses(DirectionsStatuses&& from) noexcept
    : Directions(from.getRawDirections())
{
    DirectionsStats = from.DirectionsStats;
    from.DirectionsStats = nullptr;
}

DirectionsStatuses::~DirectionsStatuses()
{
    if (DirectionsStats) {
        delete[] DirectionsStats;
        //delete DirectionsStats;
        DirectionsStats = nullptr;
    }
}

DirectionsStatuses DirectionsStatuses::CreateInvalide()
{
    return DirectionsStatuses(0);
}

DirectionsStatuses& DirectionsStatuses::operator=(const DirectionsStatuses& src) noexcept
{
    if (this != &src) {
        if (DirectionsStats) {
            delete[] DirectionsStats;
            DirectionsStats = nullptr;
        }

        if (src.isValide()) {
            int nDirs = src.getRawDirections();
            DirectionsStats = new bool[nDirs];
            for (int i = 0; i < nDirs; ++i) {
                DirectionsStats[i] = src.DirectionsStats[i];
            }
        }
    }
    return *this;
}

DirectionsStatuses& DirectionsStatuses::operator=(DirectionsStatuses&& from) noexcept
{
    if (this != &from) {
        if (DirectionsStats) {
            delete[] DirectionsStats;
            DirectionsStats = nullptr;
        }

        DirectionsStats = from.DirectionsStats;
        from.DirectionsStats = nullptr;
    }
    return *this;
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

void DirectionsStatuses::resetStatuses(bool resetValue)
{
    for (int i = 0; i < getRawDirections(); ++i) {
        DirectionsStats[i] = resetValue;
    }
}

bool DirectionsStatuses::isValide() const
{
    return getRawDirections() > 0;
}

