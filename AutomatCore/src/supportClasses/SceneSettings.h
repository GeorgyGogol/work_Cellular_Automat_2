#pragma once

#include "CoreProperties.h"
#include <QRectF>
#include "CellsSettings.h"

class SceneSettings
{
public:
    SceneSettings();
    ~SceneSettings();

private:
    QRectF DefaultCellSize = QRectF(0, 0, 50, 50);
    automat::AbstractField* pActiveField = nullptr;
    CellsSettings* CellsLook = nullptr;

public:
    bool PrintBorder = false;
    bool PrintCellInfo = false;
    bool PrintDirections = false;

    QRectF getCellSize() const;
    inline int getCellPosX(int x) const { return x * DefaultCellSize.width(); }
    inline int getCellPosY(int y) const { return y * DefaultCellSize.height(); }

    void setupLink(automat::AbstractField* field);
    inline void clearLink() { setupLink(nullptr); }

    automat::AbstractField* getFieldPtr() const;
    QRectF getSceneRect() const;
    
    int getFieldType() const;

    int getMinPoint() const;
    int getMaxPoint() const;
    inline int getPointLength() const {return getMaxPoint() - getMinPoint() + 1; }

    CellsSettings* getCellsLook();
    void setCellsLook(CellsSettings* pLookSettings);
    
};

