#include "stdafx.h"
#include "AutomatCore.h"

#include "Automat.h"

AutomatCore::AutomatCore()
{
    pAutomat = new automat::Automat();
}

AutomatCore::~AutomatCore()
{
    if (FieldScene) delete FieldScene;
    delete pAutomat;
}

AutomatFieldScene* AutomatCore::getFieldScenePtr()
{
    if(!FieldScene) {
        FieldScene = new AutomatFieldScene();
    }
    return FieldScene;
}

FieldID AutomatCore::createField(const FieldInformation& settings)
{
    automat::FieldProperties newFieldSet;
    newFieldSet.Height = settings.Height;
    newFieldSet.Width = settings.Width;
    newFieldSet.Type = automat::FieldProperties::FieldTypes(settings.Type);

    return pAutomat->createField(newFieldSet);
}

FieldList AutomatCore::getFieldList()
{
    
}

void AutomatCore::deleteField(FieldID field)
{
}

void AutomatCore::saveField(FieldID field, const QString& filePath)
{
}

FieldID AutomatCore::loadField(const QString& filePath)
{
    return FieldID();
}

void AutomatCore::setupFieldInScene(FieldID field)
{
    if (field > 0){
        //getFieldScenePtr()->LinkWithField(pAutomat->getField(field.ID));
        getFieldScenePtr()->LinkWithField(pAutomat->getLastCreatedField());
    }
    else {
        getFieldScenePtr()->ClearLinkedField();
    }
}

