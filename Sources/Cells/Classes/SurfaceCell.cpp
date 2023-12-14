#include "stdafx.h"
#include "SurfaceCell.h"

SurfaceCell::SurfaceCell()
{
    Level.Altitude = 0;
    Level.LiquidCount = 0;
    Level.isLiquidUnderground = false;
}

SurfaceCell::SurfaceCell(const CellLevels &levels)
    : Level(levels)
{
}

SurfaceCell::operator CellLevels() const
{
    return Level;
}

int SurfaceCell::getAltitude() const
{
    return Level.Altitude;
}

void SurfaceCell::changeAltitude(int delta)
{
    Level.Altitude += delta;
}

void SurfaceCell::setAltitude(int value)
{
    Level.Altitude = value;
}

int SurfaceCell::getLiquidCount() const
{
    return Level.LiquidCount;
}

void SurfaceCell::changeLiquidCount(int delta)
{
    Level.LiquidCount += delta;
}

void SurfaceCell::setLiquidCount(int value)
{
    Level.LiquidCount = value;
}

void SurfaceCell::setLiquidCount(int value, bool isUnderground)
{
    Level.LiquidCount = value;
    Level.isLiquidUnderground = isUnderground;
}
