#include "stdafx.h"
#include "AutomatFieldScene.h"

#include "SceneSettings.h"
#include "CellsSettings.h"

#include "AbstractField.h"
#include "GraphicCell.h"
#include "SimpleSquareTestField.h"
#include "TestGraphicCell.h"

AutomatFieldScene::AutomatFieldScene(QObject* parent)
    : QGraphicsScene(parent)
{
    Settings = new SceneSettings();
    //Settings->DefaultCellSize = QRectF(0, 0, 50, 50);
}

AutomatFieldScene::~AutomatFieldScene()
{
    ClearLinkedField();
    delete Settings;
}

void AutomatFieldScene::createTestField()
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
        createTestField();
        break;
    
    case -1:
    default:
        break;
    }
}

void AutomatFieldScene::ClearLinkedField()
{
    Settings->clearLink();

    this->clearFocus();
    this->clear();
    this->update();
    this->setSceneRect(0, 0, 0, 0);
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
    //Settings->PrintDirections = isNeed;
    update();
}

