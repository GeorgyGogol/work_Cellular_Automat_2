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
    return Settings->getCellSize();
}

void GraphicCell::setSelected(bool isSelected)
{
    IsSelected = isSelected;
}

void GraphicCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    paintCell(painter);

    if (IsSelected) {
        paintBorderSelected(painter);
    }

    if (Settings->PrintBorder) {
        paintBorder(painter);
    }

    if (Settings->PrintCellInfo) {
        paintInformation(painter);
    }

    if (Settings->PrintDirections) {
        paintDirections(painter);
    }
}

