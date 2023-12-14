#pragma once

#include "GraphicCell.h"
#include "QObject.h"

class TestGraphicCell : public GraphicCell
{
    Q_OBJECT

public:
    TestGraphicCell(int* pCell, SceneSettings* pSceneSettings);

private:
    int* CellDataSource;

    void paintBorder(QPainter *painter) override;
    void paintCell(QPainter *painter) override;

};

