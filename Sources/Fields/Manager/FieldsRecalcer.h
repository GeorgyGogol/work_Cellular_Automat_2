#pragma once

class AbstractField;
#include "FieldsPredefines.h"

class FieldsRecalcer
{
public:
    FieldsRecalcer() = default;

private:
    void recalc(SimpleSquareTestField* pField);

public:
    void recalcField(AbstractField* pField);

};

