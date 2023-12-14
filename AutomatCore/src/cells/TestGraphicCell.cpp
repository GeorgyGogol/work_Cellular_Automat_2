#include "stdafx.h"
#include "TestGraphicCell.h"

#include <QPainter>

TestGraphicCell::TestGraphicCell(int* pCell, SceneSettings *pSceneSettings)
    : GraphicCell(pSceneSettings)
    , CellDataSource(pCell)
{
}

void TestGraphicCell::paintBorder(QPainter *painter)
{
    painter->save();

    painter->setPen(Qt::black);
    painter->drawRect(boundingRect());

    painter->restore();
}

void TestGraphicCell::paintCell(QPainter *painter)
{
    painter->save();




    painter->restore();
}
