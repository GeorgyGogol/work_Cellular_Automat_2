#pragma once

#include "automatcore_global.h"

#include "FieldProperties.h"

class Automat;

class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();
    ~AutomatCore();

private:
    Automat* pAutomat;

public:
    void CreateField(const FieldProperties& settings);

};

