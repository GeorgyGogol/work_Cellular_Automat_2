#include "stdafx.h"
#include "FieldsManager.h"

#include "UniqueIDController.h"
#include "FieldsRecalcer.h"

#include "AbstractField.h"
#include "SimpleSquareTestField.h"
#include "FieldSquare.h"

using namespace automat;

FieldsManager::FieldsManager()
{
    FieldsID = new UniqueIDController(0);
    Recalcer = new FieldsRecalcer();
}

FieldsManager::~FieldsManager()
{
    delete FieldsID;
    delete Recalcer;
}

int automat::FieldsManager::seekField(int id, int startEl, int endEl)
{
    // TODO
    int startID = Fields[startEl]->getID();
    int endID = Fields[endEl]->getID();
    int centralID = (endID - startID) / 2;
    //int central

    //if (id > (max - min) / 2) {
    //
    //} 

/*     for (AbstractField* f : Fields) {
        if (f->getID() != id) continue;

        return f;
    }

    return nullptr; */
    return -1;
} 

int FieldsManager::createField(FieldProperties &properties)
{
    AbstractField* f = nullptr;
    properties.ID = FieldsID->getNextID();
    switch (properties.Type)
    {
    case FieldProperties::FieldTypes::TestField:
        f = new SimpleSquareTestField(properties);
        break;
    
    default:
        break;
    }

    int out = -1;
    if (f) {
        Fields.push_back(f);
        FieldsInfo.push_back(properties);
    }
    return properties.ID;
}

void automat::FieldsManager::deleteField(int fieldID)
{
    if (!FieldsID->checkIdInRange(fieldID)) return;

    std::vector<AbstractField*>::iterator it = Fields.begin();
    FieldListIterator it2 = FieldsInfo.begin();
    AbstractField* field;
    for (it, it2; it != Fields.end(); ++it, ++it2)
    {
        if ((*it)->getID() != fieldID) continue;
        field = *it;

        Fields.erase(it);
        FieldsInfo.erase(it2);
        delete field;
        break;
    }
}

int automat::FieldsManager::getFieldsCount() const
{
    return Fields.size();
}

FieldListContainer automat::FieldsManager::getFieldList() const
{
    /* FieldListContainer list;

    FieldProperties fieldInfo;
    for (int i = 0; i < Fields.size(); ++i) {
        if (Fields[i].getID() != fieldID) continue;

        delete Fields[i];
        Fields[i] = nullptr;
        Fields.erase(i);
        break;
    } */

    return FieldsInfo;
}

AbstractField* const FieldsManager::getField(int fieldID) const
{
    if (!FieldsID->checkIdInRange(fieldID)) return nullptr;

    AbstractField* out = nullptr;
    for (int i = 0; i < Fields.size(); ++i) {
        if (Fields[i]->getID() != fieldID) continue;

        out = Fields[i];
        break;
    }
    return out;
}

FieldListIterator automat::FieldsManager::begin()
{
    return FieldsInfo.begin();
}

FieldListIterator automat::FieldsManager::end()
{
    return FieldsInfo.end();
}

void FieldsManager::recalcFields()
{
    if (Fields.size() == 0) return;
    
    for (AbstractField* each : Fields)
    {
        Recalcer->recalcField(each);
    }
}
