#include "stdafx.h"
#include "GraphicCell.h"

#include "SceneSettings.h"

GraphicCell::GraphicCell(SceneSettings* pSceneSettings)
    : QGraphicsObject(nullptr)
    , Settings(pSceneSettings)
{
}

GraphicCell::~GraphicCell()
{
    Settings = nullptr;
}

QRectF GraphicCell::boundingRect() const
{
    return getDefaultSize();
}

QRectF GraphicCell::getDefaultSize()
{
    return QRectF(0, 0, 50, 50);
}

void GraphicCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (Settings->PrintBorder) {
        paintBorder(painter);
    }

    paintCell(painter);
}

/* void GraphicCell::setNeedPaintBorder(bool isNeed)
{
    PrintBorder = isNeed; 
} */

