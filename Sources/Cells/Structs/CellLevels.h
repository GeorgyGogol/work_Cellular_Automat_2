#pragma once

struct CellLevels
{
    int Altitude = 0;
    int LiquidCount = 0;
    bool isLiquidUnderground = true;

};

int SurfaceLevel(const CellLevels& info);

