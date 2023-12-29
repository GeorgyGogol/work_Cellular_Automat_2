#pragma once

#include "GraphicCell.h"

class TestGraphicCell : public GraphicCell
{
    Q_OBJECT

public:
    TestGraphicCell(int* pCell, SceneSettings* pSceneSettings);
    ~TestGraphicCell();

private:
    int* CellDataSource;
    int LastColor = -1;

    void paintBorder(QPainter *painter) override;
    void paintCell(QPainter *painter) override;
    void paintInformation(QPainter* painter) override;

};

