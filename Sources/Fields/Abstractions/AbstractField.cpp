#include "stdafx.h"
#include "AbstractField.h"
#include <string>

using namespace automat;

AbstractField::AbstractField(const FieldProperties& props, int rawDirsCount)
    : ObjectID(props.ID)
    , Height(props.Height)
    , AvalableDirections(rawDirsCount)
{
    if (props.MapName) {
        MapName = new char[std::strlen(props.MapName)];
        std::strncpy(MapName, props.MapName, std::strlen(props.MapName));
    }
    else {
        std::string unnamed = "UnnamedMap" + std::to_string(props.ID);
        MapName = new char[unnamed.size()];
        std::strncpy(MapName, unnamed.c_str(), unnamed.size());
    }
}

AbstractField::~AbstractField()
{
    delete[] MapName;
}

int AbstractField::getHeight() const
{
    return Height;
}

Directions AbstractField::getGeneralDirections() const
{
    return AvalableDirections;
}

char* automat::AbstractField::getMapName() const
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

