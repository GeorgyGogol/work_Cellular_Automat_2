#include "stdafx.h"
#include "AutomatCore.h"

#include "Automat.h"
#include "FieldsManager.h"
#include "AbstractField.h"
#include "AutomatFieldScene.h"
#include "MapListModelDefs.h"

#include <MapListItemModel.h>

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

void AutomatCore::createField(FieldInformation& settings)
{
    automat::FieldProperties newFieldSet;
    newFieldSet.Height = settings.Height;
    newFieldSet.Width = settings.Width;
    newFieldSet.Type = automat::FieldProperties::FieldTypes(settings.Type);
    if (settings.Name.length() > 0) {
        newFieldSet.MapName = settings.Name.toLocal8Bit().toStdString();
    }

    settings.ID = pAutomat->createField(newFieldSet);
    settings.Name = QString(pAutomat->getFields()->getField(settings.ID)->getMapName().c_str());

    QStandardItem* item = new QStandardItem(settings.Name);
    item->setData(newFieldSet.ID, MapListModel::ID);
    getMapListModel()->appendRow(item);
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
    MapListItemModel* model = static_cast<MapListItemModel*>(getMapListModel());
    model->deleteItemById(fieldID);
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
        FieldListModel = new MapListItemModel();
    }
    return FieldListModel;
}

