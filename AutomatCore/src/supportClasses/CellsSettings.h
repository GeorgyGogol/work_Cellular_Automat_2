#pragma once

#include "ColorLimits.h"

class CellsSettings
{
public:
    CellsSettings() = default;
    ~CellsSettings() = default;

private:
    ColorLimits AltitudeColors;
    
public:
    inline ColorLimits* Alt() { return &AltitudeColors; }

    static CellsSettings* TestCellsLook();

};

