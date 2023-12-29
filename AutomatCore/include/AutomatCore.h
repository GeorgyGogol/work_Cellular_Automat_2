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

    FieldID createField(const FieldInformation& settings);
    FieldList getFieldList();
    void deleteField(FieldID field);
    void saveField(FieldID field, const QString& filePath);
    FieldID loadField(const QString& filePath);

    void setupFieldInScene(FieldID field);
    inline void resetCurrentScene() { setupFieldInScene(-1); }

};

