#include "stdafx.h"
#include "FieldsManager.h"

#include "FieldsRecalcer.h"

#include "AbstractField.h"
#include "SimpleSquareTestField.h"
#include "FieldSquare.h"

using namespace automat;

FieldsManager::FieldsManager()
{
    Recalcer = new FieldsRecalcer();
}

FieldsManager::~FieldsManager()
{
    delete Recalcer;
}

void FieldsManager::createField(const FieldProperties &properties)
{
    AbstractField* f = nullptr;
    switch (properties.Type)
    {
    case FieldProperties::FieldTypes::TestField:
        f = new SimpleSquareTestField(properties.Height, properties.Width);
        break;
    
    default:
        break;
    }

    if (f) Fields.push_back(f);
}

AbstractField* FieldsManager::getLastField() const
{
    if (Fields.size() == 0) return nullptr;
    return Fields[Fields.size() - 1];
}

void FieldsManager::recalcFields()
{
    if (Fields.size() == 0) return;
    
    for (AbstractField* each : Fields)
    {
        Recalcer->recalcField(each);
    }
}
