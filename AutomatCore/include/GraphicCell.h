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
    bool IsSelected = false;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    virtual void paintBorder(QPainter *painter) = 0;
    virtual void paintBorderSelected(QPainter* painter) = 0;
    virtual void paintCell(QPainter *painter) = 0;
    virtual void paintInformation(QPainter* painter) = 0;
    virtual void paintDirections(QPainter* painter) = 0;

protected:
    QRectF boundingRect() const override;

protected:
    SceneSettings* Settings;

public:
    void setSelected(bool isSelected);
    virtual void setValue(void* valType, int value, int multi) = 0;

public slots:

};

