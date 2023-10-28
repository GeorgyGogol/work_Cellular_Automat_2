#pragma once

#include "BonusInfluence.h"

class IImpactedObject
{
public:
    virtual BonusInfluence getImpact() = 0;
};

