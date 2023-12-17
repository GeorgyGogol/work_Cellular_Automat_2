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

void AutomatCore::createField(FieldInformation& settings)
{
    automat::FieldProperties newFieldSet;
    newFieldSet.Height = settings.Height;
    newFieldSet.Width = settings.Width;
    newFieldSet.Type = automat::FieldProperties::FieldTypes(settings.Type);

    pAutomat->createField(newFieldSet);

    settings.ID = 1000;
}

FieldList AutomatCore::getFieldList()
{
    return FieldList();
}

void AutomatCore::setupFieldInScene(const FieldInformation& field)
{
    if (field.ID > 0){
        //getFieldScenePtr()->LinkWithField(pAutomat->getField(field.ID));
        getFieldScenePtr()->LinkWithField(pAutomat->getLastCreatedField());
    }
    else {
        getFieldScenePtr()->ClearLinkedField();
    }
}

