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

    if (LastColor /* < 1.0 * Settings->getCellsLook()->Alt()->getLength() */ > 256 / 2)
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
    
    painter->save();
    
    painter->setPen(Qt::transparent);
    painter->setBrush(QColor(val, val, val));
    painter->drawRect(boundingRect());

    painter->restore();

    LastColor = val;

    colors = nullptr;
}

void TestGraphicCell::paintInformation(QPainter* painter)
{
    painter->save();

    if (LastColor > 1.0 * Settings->getCellsLook()->Alt()->getLength() / 2)
        painter->setPen(Qt::black);
    else
        painter->setPen(Qt::white);

    int lineWidth = painter->fontInfo().pixelSize();

    QRectF infoArea = boundingRect();
    infoArea.setRect(infoArea.x() + 2, infoArea.y() + 2, infoArea.width() - 4, infoArea.height() - 4);
    QPoint TextPoint = QPoint(int(infoArea.x()), int(infoArea.y()) + lineWidth);

    QString alt = "Value: " + QString::number(*CellDataSource);
    QString maxLengthText = "TestTe:";
    maxLengthText += QString::number(maxLengthText.length());

    painter->drawText(TextPoint, alt);
    TextPoint.setY(TextPoint.y() + lineWidth + 2);

    painter->drawText(TextPoint, maxLengthText);

    painter->restore();
}

