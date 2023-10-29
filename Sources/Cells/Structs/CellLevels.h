#pragma once

struct CellLevels
{
    int Altitude;
    int LiquidCount;
    bool isLiquidUnderground;

};

int SurfaceLevel(const CellLevels& info);

