#pragma once

#include "automatcore_global.h"
#include <QGraphicsObject>

class SceneSettings;

class AUTOMATCORE_EXPORT GraphicCell
    : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit GraphicCell(SceneSettings* pSceneSettings);
    ~GraphicCell();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    virtual void paintBorder(QPainter *painter) = 0;
    virtual void paintCell(QPainter *painter) = 0;
    virtual void paintInformation(QPainter* painter) = 0;
    virtual void paintDirections(QPainter* painter) = 0;

    virtual void paintBorderSelected(QPainter* painter, bool isSelected) = 0;

protected:
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

protected:
    SceneSettings* Settings;

public:


public slots:

};

