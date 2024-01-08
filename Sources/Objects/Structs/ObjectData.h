#pragma once

#include "RangedValue.h"
#include "EnergyValue.h"

namespace automat {

    class ObjectData
    {
    public:
        int Existance = 1;

        //int Energy = 0;
        //EnergyType EType = EnergyType::Base;

        int ID = -1;
    };

/*     struct ObjectData
    {
        RangedValue Existance = 0;
        EnergyValue Energy = EnergyValue(0, EnergyType::Base);
    }; */

}

