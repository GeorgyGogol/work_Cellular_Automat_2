#include "stdafx.h"
#include "FieldsRecalcer.h"

#include "AbstractField.h"
#include "SimpleSquareTestField.h"

void FieldsRecalcer::recalc(SimpleSquareTestField *pField)
{

}

void FieldsRecalcer::recalcField(AbstractField *pField)
{
    switch (pField->getFieldType())
    {
    case 0:
        recalc(static_cast<SimpleSquareTestField*>(pField));
        break;
    
    default:
        break;
    }
}