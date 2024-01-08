#include "stdafx.h"
#include "Automat.h"

#include "FieldsManager.h"
#include "ObjectManager.h"

automat::Automat::Automat()
{
    Fields = new FieldsManager();
    Objects = new ObjectManager();
}

automat::Automat::~Automat()
{
    delete Fields;
    delete Objects;
}

automat::FieldsManager *const automat::Automat::getFields()
{
    return Fields;
}

int automat::Automat::createField(FieldProperties &properties)
{
    return Fields->createField(properties);
}

void automat::Automat::deleteField(const int fieldID)
{
    Fields->deleteField(fieldID);
}

automat::ObjectManager *const automat::Automat::getObjects()
{
    return Objects;
}

int automat::Automat::createObject(ObjectData &objectInfo)
{
    return Objects->createObject(objectInfo);
}

void automat::Automat::doStep()
{
}

