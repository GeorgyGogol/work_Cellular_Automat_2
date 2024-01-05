#include "stdafx.h"
#include "MapStatusBar.h"

#include <QLabel>

MapStatusBar::MapStatusBar(QWidget *parent)
    : QStatusBar(parent)
    , mapName(new QLabel(this))
    , mapType(new QLabel(this))
    , mapSize(new QLabel(this))
{
    Clear();

    mapName->setMinimumWidth(90);
    mapType->setMinimumWidth(110);
    mapSize->setMinimumWidth(120);

    addWidget(mapName);
    addWidget(mapType);
    addWidget(mapSize);
}

MapStatusBar::~MapStatusBar()
{
    delete mapName;
    delete mapType;
    delete mapSize;
}

void MapStatusBar::setMapName(QString name)
{
    mapName->setText("Карта: " + name);
}

void MapStatusBar::setMapType(QString type)
{
    mapType->setText("Тип: " + type);
}

void MapStatusBar::setMapSize(int width, int height)
{
    QString labelText = 
        "Размер: "
        + QString::number(height)
        + "x"
        + QString::number(width)
        + " ("
        + QString::number(width * height)
        + ")";
    mapSize->setText(labelText);
}

void MapStatusBar::Clear()
{
    setMapName("");
    setMapType("Не загружена");
    setMapSize(0, 0);
}

