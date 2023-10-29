#include "CellLevels.h"

int SurfaceLevel(const CellLevels &info)
{
    if (info.isLiquidUnderground){
        int max = info.Altitude;

        if (max < info.LiquidCount) max = info.LiquidCount;

        return max;
    }
    else{
        return info.Altitude + info.LiquidCount;
    }
}
