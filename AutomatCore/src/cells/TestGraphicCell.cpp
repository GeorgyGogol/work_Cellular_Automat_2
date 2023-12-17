#include "stdafx.h"
#include "TestGraphicCell.h"

#include <QPainter>
#include <cmath>
#include "SceneSettings.h"
#include "CellsSettings.h"

TestGraphicCell::TestGraphicCell(int* pCell, SceneSettings *pSceneSettings)
    : GraphicCell(pSceneSettings)
    , CellDataSource(pCell)
{
}

TestGraphicCell::~TestGraphicCell()
{
    CellDataSource = nullptr;
}

void TestGraphicCell::paintBorder(QPainter *painter)
{
    painter->save();

    if (LastColor < 1.0 * Settings->getCellsLook()->Alt()->getLength() / 2)
        painter->setPen(Qt::black);
    else
        painter->setPen(Qt::white);
    
    painter->drawRect(boundingRect());

    painter->restore();
}

void TestGraphicCell::paintCell(QPainter *painter)
{
    CellsSettings* colors = Settings->getCellsLook();

    int deltaAlt = Settings->getPointLength();
    int deltaData = *CellDataSource - Settings->getMinPoint();
    double step1 = 1.0 + 1.0 * deltaData / deltaAlt;
    double step2 = step1 * colors->Alt()->getLength();

    int val = step2;

    //int val = round((1.0 + 1.0 * (Settings->getPointLength()) / (*CellDataSource * 1.0 - Settings->getMinPoint())) * colors->Alt()->getLength());
    
    painter->save();
    
    painter->setBrush(QColor(val, val, val));
    painter->drawRect(boundingRect());

    painter->restore();

    LastColor = val;

    colors = nullptr;
}

