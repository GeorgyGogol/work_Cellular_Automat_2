#include "stdafx.h"
#include "AutomatFieldScene.h"

#include "SceneSettings.h"
#include "CellsSettings.h"
#include "GraphicCell.h"
#include "TestGraphicCell.h"

#include "AbstractField.h"
#include "SimpleSquareTestField.h"

AutomatFieldScene::AutomatFieldScene(QObject* parent)
    : QGraphicsScene(parent)
{
    Settings = new SceneSettings;
}

AutomatFieldScene::~AutomatFieldScene()
{
    ClearLinkedField();
    delete Settings;
}

void AutomatFieldScene::setupTestField()
{
    using namespace automat;
    SimpleSquareTestField* pField = static_cast<SimpleSquareTestField*>(Settings->getFieldPtr());
    TestGraphicCell* pGraphCell;
    Settings->setCellsLook(CellsSettings::TestCellsLook());
    for (int y = 0; y < pField->getHeight(); ++y){
        for (int x = 0; x < pField->getWidth(); ++x){
            pGraphCell = new TestGraphicCell(pField->getCellAt(x, y), Settings);
            pGraphCell->setY(Settings->getCellPosY(y));
            pGraphCell->setX(Settings->getCellPosX(x));
            addItem(pGraphCell);
        }
    }
}

void AutomatFieldScene::LinkWithField(automat::AbstractField* pField)
{
    ClearLinkedField();

    Settings->setupLink(pField);

    setSceneRect(Settings->getSceneRect());
    switch (Settings->getFieldType())
    {
    case 0:
        setupTestField();
        break;
    
    case -1:
    default:
        break;
    }

    FieldInformation info;
    info.ID = pField->getID();
    info.Height = pField->getHeight();
    info.Width = pField->getWidth();
    info.Type = pField->getFieldType();
    info.Name = QString(pField->getMapName().c_str());
    emit FieldInfoChanged(info);
}

void AutomatFieldScene::ClearLinkedField()
{
    Settings->clearLink();

    this->clearFocus();
    this->clear();
    this->update();
    this->setSceneRect(0, 0, 0, 0);

    //emit FieldInfoChanged(FieldInformation());
}

void AutomatFieldScene::setNeedPaintCellInfo(bool isNeed)
{
    Settings->PrintCellInfo = isNeed;
    update();
}

void AutomatFieldScene::setNeedPaintGrid(bool isNeed)
{
    Settings->PrintBorder = isNeed;
    update();
}

void AutomatFieldScene::setNeedPaintDirections(bool isNeed)
{
    Settings->PrintDirections = isNeed;
    update();
}

