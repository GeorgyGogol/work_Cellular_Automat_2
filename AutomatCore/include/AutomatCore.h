#pragma once

#include "automatcore_global.h"

struct FieldSettings
{
    int Height;
    int Width;
};

class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();

public:
    void CreateField(const FieldSettings& settings);

};
