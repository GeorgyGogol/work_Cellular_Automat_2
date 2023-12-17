#include "stdafx.h"
#include "SceneSettings.h"

#include "AbstractField.h"

SceneSettings::SceneSettings()
{
}

SceneSettings::~SceneSettings()
{
    clearLink();
}

QRectF SceneSettings::getCellSize() const
{
    return DefaultCellSize;
}

void SceneSettings::setupLink(automat::AbstractField *field)
{
    pActiveField = field;
    if (pActiveField) return;

    if (CellsLook) {
        delete CellsLook;
        CellsLook = nullptr;
    }
}

automat::AbstractField* SceneSettings::getFieldPtr() const
{
    return pActiveField;
}

QRectF SceneSettings::getSceneRect() const
{
    if (!pActiveField) return QRectF();
    return QRectF(
        0,
        0,
        DefaultCellSize.width() * pActiveField->getWidth(),
        DefaultCellSize.height() * pActiveField->getHeight()
    );
}

int SceneSettings::getFieldType() const
{
    return pActiveField->getFieldType();
}

int SceneSettings::getMinPoint() const
{
    return -2;
}

int SceneSettings::getMaxPoint() const
{
    return 1;
}

CellsSettings *SceneSettings::getCellsLook()
{
    return CellsLook;
}

void SceneSettings::setCellsLook(CellsSettings *pLookSettings)
{
    if(CellsLook) delete CellsLook;
    CellsLook = pLookSettings;
}

