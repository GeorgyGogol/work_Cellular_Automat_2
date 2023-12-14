#pragma once

#include "FieldProperties.h"

class FieldsManager;
class AbstractField;

class Automat
{
public:
    Automat();
    ~Automat();

private:
    FieldsManager* Fields;

public:
    void createField(const FieldProperties& properties);
    AbstractField* getField();

    void doStep();

};

