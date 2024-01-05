#pragma once

#include <QGraphicsView>
#include <QList>
#include "MapBrushSettings.h"

class GraphicCell;

class MapEditorGraphicsView 
    : public QGraphicsView
{
    Q_OBJECT

public:
    MapEditorGraphicsView(QWidget* parent);
    ~MapEditorGraphicsView();

private:
    QList<GraphicCell*> SlectedCells;
    MapBrushSettings MapBrush;

protected:
    void mousePressEvent(QMouseEvent* event) override;

public slots:
    void setBrushStrenght(int val);
    void setBrushIsIncreace(bool isInrease);

};
