#pragma once

#include "automatcore_global.h"
#include <QGraphicsObject>

class AUTOMATCORE_EXPORT GraphicCell
    : public QGraphicsObject
{
    Q_OBJECT

public:
    GraphicCell();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:

};

