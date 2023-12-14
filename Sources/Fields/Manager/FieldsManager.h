#pragma once

#include <vector>
#include "FieldProperties.h"
#include "FieldsPredefines.h"

class FieldsRecalcer;

class FieldsManager
{
public:
    FieldsManager();
    ~FieldsManager();

private:
    std::vector<AbstractField*> Fields;
    AbstractField* CurrentField;
    FieldsRecalcer* Recalcer;

public:
    void createField(const FieldProperties& properties);

    void recalcFields();

};

