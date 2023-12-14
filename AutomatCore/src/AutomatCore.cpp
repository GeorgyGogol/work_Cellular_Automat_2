#include "stdafx.h"
#include "AutomatCore.h"

#include "Automat.h"

AutomatCore::AutomatCore()
{
    pAutomat = new Automat();
    CurrentScene = new AutomatFieldScene();
}

AutomatCore::~AutomatCore()
{
    delete CurrentScene;
    delete pAutomat;
}

AutomatFieldScene* AutomatCore::createField(const FieldProperties& settings)
{
    pAutomat->createField(settings);
    CurrentScene->LinkWithField(pAutomat->getField());
    return CurrentScene;
}

AutomatFieldScene *AutomatCore::getCurrentScene() const
{
    return CurrentScene;
}

void AutomatCore::resetCurrentScene()
{
    //CurrentScene = nullptr;
}
