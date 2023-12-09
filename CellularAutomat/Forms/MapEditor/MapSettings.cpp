#include "stdafx.h"
#include "MapSettings.h"
#include "ui_MapSettings.h"

#include <QComboBox>

MapSettings::MapSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MapSettingsClass())
{
    ui->setupUi(this);

    connect(ui->MapType, qOverload<int>(&QComboBox::currentIndexChanged), this, &MapSettings::MapTypeChange);
    connect(ui->MapHeight, qOverload<int>(&QSpinBox::valueChanged), this, &MapSettings::MapHeightChange);
    connect(ui->MapWidth, qOverload<int>(&QSpinBox::valueChanged), this, &MapSettings::MapWidthChange);
}

MapSettings::~MapSettings()
{
    delete ui;
}

void MapSettings::RecalcMapSize()
{
    int size = 0;
    switch (MapTypeIndex)
    {
    case 0:
    case 1:
        size = Height * Width;
        break;

    default:
        break;
    }
    ui->LFieldSizeCells->setText(QString::number(size));
}

void MapSettings::MapTypeChange(int type)
{
    MapTypeIndex = type;
    RecalcMapSize();
}

void MapSettings::MapHeightChange(int h)
{
    Height = h;
    RecalcMapSize();
}

void MapSettings::MapWidthChange(int w)
{
    Width = w;
    RecalcMapSize();
}

