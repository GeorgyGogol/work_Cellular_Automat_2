#include "FieldsManager.h"

#include "AbstractField.h"
#include "SimpleSquareTestField.h"
#include "FieldSquare.h"

void FieldsManager::createField(const FieldProperties &properties)
{
    AbstractField* f;
    switch (properties.Type)
    {
    case FieldProperties::FieldTypes::TestField:
        f = new SimpleSquareTestField(properties.Height, properties.Width);
        break;
    
    default:
        break;
    }

    Fields.push_back(f);
}
