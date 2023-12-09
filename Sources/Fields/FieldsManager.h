#pragma once

#include <vector>
#include "FieldProperties.h"

class AbstractField;

class FieldsManager
{
public:
    FieldsManager() = default;

private:
    std::vector<AbstractField> Fields;
    AbstractField* CurrentField;

public:
    void createField(const FieldProperties& properties);

};

