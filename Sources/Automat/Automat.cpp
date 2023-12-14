#include "stdafx.h"
#include "Automat.h"

#include "FieldsManager.h"

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

AbstractField *Automat::getField()
{
    return Fields->getLastField();
}

void Automat::doStep()
{
}

