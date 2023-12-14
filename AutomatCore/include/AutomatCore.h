#pragma once

#include "automatcore_global.h"

#include "FieldProperties.h"
#include "AutomatFieldScene.h"

class Automat;

class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();
    ~AutomatCore();

private:
    Automat* pAutomat;
    AutomatFieldScene* CurrentScene = nullptr;

public:
    AutomatFieldScene* createField(const FieldProperties& settings);
    AutomatFieldScene* getCurrentScene() const;
    void resetCurrentScene();

};

