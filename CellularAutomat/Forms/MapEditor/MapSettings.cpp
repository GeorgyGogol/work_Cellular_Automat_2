#include "stdafx.h"
#include "MapSettings.h"
#include "ui_MapSettings.h"

#include "ResCore.h"

MapSettings::MapSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MapSettingsClass())
    , Resources(new ResCore("MapEditor"))
{
    ui->setupUi(this);

    connect(ui->MapType, qOverload<int>(&QComboBox::currentIndexChanged), this, &MapSettings::MapTypeChange);
    connect(ui->MapHeight, qOverload<int>(&QSpinBox::valueChanged), this, &MapSettings::MapHeightChange);
    connect(ui->MapWidth, qOverload<int>(&QSpinBox::valueChanged), this, &MapSettings::MapWidthChange);

    ui->gvFieldImg->setScene(new QGraphicsScene(ui->gvFieldImg));

    MapTypeChange(0);
}

MapSettings::~MapSettings()
{
    delete ui;
    delete Resources;
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

    QString descr;
    QPixmap img;
    switch (type)
    {
    case 0:
        descr = Resources->loadString("TestFieldDesc");
        img = Resources->loadImage("TestFieldImg");
        break;

    case 1:
        descr = Resources->loadString("SquareFieldDesc");
        img = Resources->loadImage("SquareFieldImg");
        break;

    default:
        break;
    }

    ui->FieldDesc->setText(descr);

    QGraphicsScene* scene = ui->gvFieldImg->scene();
    scene->clear();
    scene->addPixmap(img);
}

QString MapSettings::getMapName() const
{
    return ui->eFieldName->text();
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

