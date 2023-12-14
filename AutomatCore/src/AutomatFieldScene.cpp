#include "stdafx.h"
#include "AutomatFieldScene.h"

#include "SceneSettings.h"
#include "AbstractField.h"
#include "GraphicCell.h"
#include "SimpleSquareTestField.h"
#include "TestGraphicCell.h"

AutomatFieldScene::AutomatFieldScene(QObject* parent)
    : QGraphicsScene(parent)
{
    Settings = new SceneSettings();
}

AutomatFieldScene::~AutomatFieldScene()
{
    ClearLinkedField();
    delete Settings;
}

void AutomatFieldScene::createTestField(SimpleSquareTestField* pField)
{
    int* pCell;
    GraphicCell* pGraphCell;
    for (int y = 0; y < pField->getHeight(); ++y){
        for (int x = 0; x < pField->getWidth(); ++x){
            pGraphCell = new TestGraphicCell(pField->getCellAt(x, y), Settings);
            pGraphCell->setY(y * DefaultCellSize.height());
            pGraphCell->setX(x * DefaultCellSize.width());
            addItem(pGraphCell);
        }
    }
}

void AutomatFieldScene::LinkWithField(AbstractField* pField)
{
    ClearLinkedField();

    Settings->TypeField = pField->getFieldType();

    DefaultCellSize = GraphicCell::getDefaultSize();
    setSceneRect(0, 0, DefaultCellSize.width() * pField->getWidth(), DefaultCellSize.height() * pField->getHeight());

    switch (Settings->TypeField)
    {
    case 0:
        createTestField(static_cast<SimpleSquareTestField*>(pField));
        break;
    
    case -1:
    default:
        break;
    }
}

void AutomatFieldScene::ClearLinkedField()
{
    Settings->resetTypeField();

    this->clearFocus();
    this->clear();
    this->update();
    this->setSceneRect(0, 0, 0, 0);
}

void AutomatFieldScene::setNeedPaintGrid(bool isNeed)
{
    Settings->PrintBorder = isNeed;
}

