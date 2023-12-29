#include "stdafx.h"
#include "Automat.h"

#include "FieldsManager.h"

using namespace automat;

Automat::Automat()
{
    Fields = new FieldsManager();
}

Automat::~Automat()
{
    delete Fields;
}

FieldsManager *const automat::Automat::getFields()
{
    return Fields;
}

int Automat::createField(FieldProperties &properties)
{
    return Fields->createField(properties);
}

void automat::Automat::deleteField(const int fieldID)
{
    Fields->deleteField(fieldID);
}

/* AbstractField *Automat::getLastCreatedField() const
{
    return Fields->getLastField();
} */

void Automat::doStep()
{
}

