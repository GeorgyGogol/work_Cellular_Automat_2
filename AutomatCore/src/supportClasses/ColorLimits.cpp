#include "stdafx.h"
#include "ColorLimits.h"

ColorLimits::ColorLimits(int min, int max)
    : Lower(min)
    , Higher(max)
{
    if (Higher > MaximumHigh) Higher = MaximumHigh;
}

