#pragma once

#include "automatcore_global.h"

#include "CoreProperties.h"
#include "AutomatFieldScene.h"

QT_BEGIN_NAMESPACE
class QStandardItemModel;
QT_END_NAMESPACE

class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();
    ~AutomatCore();

private:
    automat::Automat* pAutomat;
    AutomatFieldScene* FieldScene = nullptr;
    QStandardItemModel* FieldListModel = nullptr;

public:
    AutomatFieldScene* getFieldScenePtr();

    int createField(const FieldInformation& settings);
    FieldList getFieldList();
    void deleteField(int fieldID);
/*     void saveField(int fieldID, const QString& filePath);
    int loadField(const QString& filePath); */

    void setupFieldInScene(int fieldID);
    inline void resetCurrentScene() { setupFieldInScene(-1); }

    QStandardItemModel* getMapListModel();

};

