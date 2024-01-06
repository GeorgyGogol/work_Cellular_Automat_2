#include "stdafx.h"
#include "AbstractField.h"

using namespace automat;

AbstractField::AbstractField(const FieldProperties& props, int rawDirsCount)
    : ObjectID(props.ID)
    , Height(props.Height)
    , AvalableDirections(rawDirsCount)
{
    if (!props.MapName.empty()) {
        MapName = props.MapName;
    }
    else {
        std::string unnamed = "UnnamedMap" + std::to_string(props.ID);
        MapName = unnamed;
    }
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

std::string automat::AbstractField::getMapName() const
{
    return MapName;
}

bool AbstractField::isCoordValide(int x, int y) const
{
    bool res = true;

    if (y < 0 || y >= Height) res = false;
    if (x < 0 || x >= getWidth(y)) res = false;

    return res;
}

