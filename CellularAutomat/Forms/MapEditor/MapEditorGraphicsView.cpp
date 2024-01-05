#include "stdafx.h"
#include "MapEditorGraphicsView.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "GraphicCell.h"
#include <QPainter>

MapEditorGraphicsView::MapEditorGraphicsView(QWidget* parent)
    : QGraphicsView(parent)
{
    MapBrush.Strength = 1;
    MapBrush.IsInrease = true;
}

MapEditorGraphicsView::~MapEditorGraphicsView()
{}

void MapEditorGraphicsView::setBrushStrenght(int val)
{
    MapBrush.Strength = val;
}

void MapEditorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QGraphicsScene* pScene = scene();
    if (!pScene) return;

    QList<QGraphicsItem*> rawSceneItems = pScene->items(mapToScene(event->pos()));
    QList<GraphicCell*> SceneItems;
    for (QGraphicsItem* item : rawSceneItems) {
        if (GraphicCell* cell = dynamic_cast<GraphicCell*>(item)) {
            SceneItems.push_back(cell);
        }
    }

    for (GraphicCell* eachCell : SlectedCells) {
        eachCell->setSelected(false);
    }
    SlectedCells.clear();

    for (GraphicCell* eachCell : SceneItems) {
        eachCell->setSelected(true);
        eachCell->setValue(0, MapBrush.Strength, MapBrush.getIncraseMulti());
        SlectedCells.push_back(eachCell);
    }

    /*
    bool isSame = SceneItems.count() == SlectedCells.count();
    for (int i = 0; isSame && i < SceneItems.count(); ++i) {
        isSame = SceneItems[i] == SlectedCells[i];
    }

    if (isSame) {
        for (GraphicCell* eachCell : SlectedCells) {
            eachCell->setValue(0, MapBrush.Strength, MapBrush.getIncraseMulti());
        }
    }
    else {
        for (GraphicCell* eachCell : SlectedCells) {
            eachCell->setSelected(false);
        }
        SlectedCells.clear();

        for (GraphicCell* eachCell : SceneItems) {
            eachCell->setSelected(true);
            SlectedCells.push_back(eachCell);
        }

    }
    */

    pScene->update();
}

void MapEditorGraphicsView::setBrushIsIncreace(bool isInrease)
{
    MapBrush.IsInrease = isInrease;
}

