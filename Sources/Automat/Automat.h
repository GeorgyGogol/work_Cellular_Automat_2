#pragma once

#include "FieldProperties.h"

class FieldsManager;

class Automat
{
public:
    Automat();
    ~Automat();

private:
    FieldsManager* Fields;

public:
    void createField(const FieldProperties& properties);

};

