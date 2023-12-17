#include "stdafx.h"
#include "CellsSettings.h"

CellsSettings *CellsSettings::TestCellsLook()
{
    CellsSettings* out = new CellsSettings;
    out->AltitudeColors = ColorLimits(76, 180);
    return out;
}

