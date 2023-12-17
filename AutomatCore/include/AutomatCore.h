#pragma once

#include "automatcore_global.h"

#include "CoreProperties.h"
#include "AutomatFieldScene.h"

class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();
    ~AutomatCore();

private:
    automat::Automat* pAutomat;
    AutomatFieldScene* FieldScene = nullptr;

public:
    AutomatFieldScene* getFieldScenePtr();

    void createField(FieldInformation& settings);
    FieldList getFieldList();
    void setupFieldInScene(const FieldInformation& field);
    inline void resetCurrentScene() { setupFieldInScene(FieldInformation()); }

};

