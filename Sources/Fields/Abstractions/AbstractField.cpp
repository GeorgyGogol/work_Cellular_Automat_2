#include "stdafx.h"
#include "AbstractField.h"

using namespace automat;

AbstractField::AbstractField(int height, int rawDirsCount)
    : Height(height)
    , AvalableDirections(rawDirsCount)
{
}

AbstractField::~AbstractField()
{
}

int AbstractField::getHeight() const
{
    return Height;
}

Directions AbstractField::getGeneralDirections() const
{
    return AvalableDirections;
}

bool AbstractField::isCoordValide(int x, int y) const
{
    bool res = true;

    if (y < 0 || y >= Height) res = false;
    if (x < 0 || x >= getWidth(y)) res = false;

    return res;
}

