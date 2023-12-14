#include "stdafx.h"
#include "AutomatCore.h"

#include "Automat.h"

AutomatCore::AutomatCore()
{
    pAutomat = new Automat();
}

AutomatCore::~AutomatCore()
{
    delete pAutomat;
}

void AutomatCore::CreateField(const FieldProperties& settings)
{
    pAutomat->createField(settings);
}
