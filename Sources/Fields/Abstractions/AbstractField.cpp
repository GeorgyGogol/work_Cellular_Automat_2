#include "AbstractField.h"

BaseField::BaseField(int height, int rawDirsCount)
    : Height(height)
    , AvalableDirections(rawDirsCount)
{
    CreateField();
}

BaseField::~BaseField()
{
    DeleteField();
}

BaseField::BaseField(const BaseField &src)
{
    CopyField(src);
}

BaseField::BaseField(BaseField &&from) noexcept
{
    MoveField(from);
}

int BaseField::getHeight() const
{
    return Height;
}

Directions BaseField::getGeneralDirections() const
{
    return AvalableDirections;
}

bool BaseField::isCoordValide(int x, int y) const
{
    bool res = true;

    if (y < 0 || y >= Height) res = false;
    if (x < 0 || x >= getWidth(y)) res = false;

    return res;
}

