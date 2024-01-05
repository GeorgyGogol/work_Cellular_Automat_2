#include "stdafx.h"
#include "AutomatCore.h"

#include "Automat.h"
#include "FieldsManager.h"
#include "AbstractField.h"

#include <QStandardItemModel>

AutomatCore::AutomatCore()
{
    pAutomat = new automat::Automat();
}

AutomatCore::~AutomatCore()
{
    if (FieldScene) delete FieldScene;
    if (FieldListModel) delete FieldListModel;
    delete pAutomat;
}

AutomatFieldScene* AutomatCore::getFieldScenePtr()
{
    if(!FieldScene) {
        FieldScene = new AutomatFieldScene();
    }
    return FieldScene;
}

int AutomatCore::createField(const FieldInformation& settings)
{
    automat::FieldProperties newFieldSet;
    newFieldSet.Height = settings.Height;
    newFieldSet.Width = settings.Width;
    newFieldSet.Type = automat::FieldProperties::FieldTypes(settings.Type);
    if (settings.Name.length() > 0) {
        newFieldSet.MapName = settings.Name.toLocal8Bit().toStdString();
    }

    newFieldSet.ID = pAutomat->createField(newFieldSet);
    newFieldSet.MapName = pAutomat->getFields()->getField(newFieldSet.ID)->getMapName();

    QStandardItemModel* mapList = getMapListModel();
    QStandardItem* item = new QStandardItem(QString(newFieldSet.MapName.c_str()));
    item->setData(newFieldSet.ID, Qt::UserRole + 1);
    mapList->appendRow(item);

    return newFieldSet.ID;
}

FieldList AutomatCore::getFieldList()
{
    FieldList out;
    FieldInformation elementInfo;

    automat::FieldProperties elementRawInfo;
    automat::FieldListIterator it = pAutomat->getFields()->begin();
    automat::FieldListIterator end_it = pAutomat->getFields()->end();

    while (it != end_it)
    {
        elementRawInfo = *it;

        elementInfo.ID = elementRawInfo.ID;
        elementInfo.Type = int(elementRawInfo.Type);
        elementInfo.Height = elementRawInfo.Height;
        elementInfo.Width = elementRawInfo.Width;

        out.push_back(elementInfo);

        ++it;
    }
    
    return out;
}

void AutomatCore::deleteField(int fieldID)
{
    pAutomat->deleteField(fieldID);
}

/* void AutomatCore::saveField(int field, const QString& filePath)
{
}

int AutomatCore::loadField(const QString& filePath)
{
    return int();
} */

void AutomatCore::setupFieldInScene(int fieldID)
{
    if (fieldID < 0) {
        getFieldScenePtr()->ClearLinkedField();
        return;
    }

    automat::AbstractField* f = pAutomat->getFields()->getField(fieldID);
    if (f) {
        getFieldScenePtr()->LinkWithField(f);
    }
}

QStandardItemModel* AutomatCore::getMapListModel()
{
    if (!FieldListModel) {
        FieldListModel = new QStandardItemModel();
    }
    return FieldListModel;
}

