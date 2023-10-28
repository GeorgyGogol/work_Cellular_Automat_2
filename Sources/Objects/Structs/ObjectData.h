#pragma once

#include "RangedValue.h"
#include "EnergyValue.h"

struct ObjectData_s
{
    int Existance = 0;
    int Energy = 0;
    EnergyType EType = EnergyType::Base;
};

struct ObjectData
{
    RangedValue Existance = 0;
    EnergyValue Energy = EnergyValue(0, EnergyType::Base);
};


