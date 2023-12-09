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
