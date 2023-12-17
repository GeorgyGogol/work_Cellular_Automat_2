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

void Automat::createField(const FieldProperties &properties)
{
    Fields->createField(properties);
}

AbstractField *Automat::getLastCreatedField() const
{
    return Fields->getLastField();
}

void Automat::doStep()
{
}

