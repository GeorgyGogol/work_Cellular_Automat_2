#include "stdafx.h"
#include "MapEditor.h"
#include "ui_MapEditor.h"

#include <memory>
#include "MapSettings.h"

#include "AutomatCore.h"

#include <QSpinBox>

MapEditor::MapEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapEditorClass())
{
    ui->setupUi(this);
    pDll = new AutomatCore();

    connect(ui->spinBox_Scale, qOverload<int>(&QSpinBox::valueChanged), this, &MapEditor::setMainViewScale);

    connect(ui->spinBox_BrushStrength, qOverload<int>(&QSpinBox::valueChanged), ui->mainView, &MapEditorGraphicsView::setBrushStrenght);
    connect(
        ui->rb_MouseBrashInc, 
        &QRadioButton::toggled,
        this, 
        [=](bool checked) { ui->mainView->setBrushIsIncreace(checked); }
    );

    ui->MapListView->setModel(pDll->getMapListModel());
}

MapEditor::~MapEditor()
{
    delete ui;
    delete pDll;
}

void MapEditor::setStatusWithMap(bool isHaveMap)
{
    isHaveMap = pDll->getFieldList().size() > 0;
    //ui->action_CreateNewMap->setDisabled(isHaveMap);
    ui->action_LoadMap->setDisabled(isHaveMap);
    ui->action_SaveMap->setEnabled(isHaveMap);
    ui->action_CloseMap->setEnabled(isHaveMap);
}

void MapEditor::closeEvent(QCloseEvent* event)
{
    emit Closed();
    event->accept();
}

void MapEditor::on_action_CreateNewMap_triggered()
{
    std::unique_ptr<MapSettings> dialog (new MapSettings(this));
    if (dialog->exec() == QDialog::Rejected) return;

    FieldInformation newFieldSettings;
    newFieldSettings.Height = dialog->getMapHeight();
    newFieldSettings.Width = dialog->getMapWidth();
    newFieldSettings.Type = dialog->getMapType();
    newFieldSettings.Name = dialog->getMapName();

    int mapID = pDll->createField(newFieldSettings);
    if (mapID > -1) {
        ui->mainView->setScene(pDll->getFieldScenePtr());
        pDll->setupFieldInScene(mapID);

        setStatusWithMap(true);
        ui->statusBar->setMapSize(newFieldSettings.Height, newFieldSettings.Width);
        ui->statusBar->setMapName(newFieldSettings.Name);
        ui->statusBar->setMapType("Test map");
        //ui->MapListView->setS
    }
}

void MapEditor::on_action_LoadMap_triggered()
{
    setStatusWithMap(true);
}

void MapEditor::on_action_SaveMap_triggered()
{
}

void MapEditor::on_action_CloseMap_triggered()
{
    if (
        QMessageBox::warning(
            this,
            "Внимание!",
            "Вы уверены, что хотите закрыть и удалить карту?",
            QMessageBox::Ok | QMessageBox::Cancel,
            QMessageBox::Ok
        ) == QMessageBox::Cancel
        )
    {
        return;
    }

    pDll->resetCurrentScene();
    //pDll->deleteField();


    setStatusWithMap(false);
}

void MapEditor::on_pb_ResetScale_clicked()
{
    ui->spinBox_Scale->setValue(4);
    ui->mainView->resetMatrix();
}

void MapEditor::setMainViewScale(int value)
{
    qreal sx = 1.0 * value / 4;
    qreal sy = 1.0 * value / 4;

    ui->mainView->resetMatrix();
    ui->mainView->scale(sx, sy);
}

void MapEditor::on_cb_PaintGrid_toggled(bool value)
{
    AutomatFieldScene* pScene = pDll->getFieldScenePtr();
    if (!pScene) return;
    pScene->setNeedPaintGrid(value);
}

void MapEditor::on_cb_PaintInfo_toggled(bool value)
{
    AutomatFieldScene* pScene = pDll->getFieldScenePtr();
    if (!pScene) return;
    pScene->setNeedPaintCellInfo(value);
}

void MapEditor::on_cb_Directions_toggled(bool value)
{
    AutomatFieldScene* pScene = pDll->getFieldScenePtr();
    if (!pScene) return;
    pScene->setNeedPaintDirections(value);
}

void MapEditor::on_MapListView_clicked(QModelIndex index)
{
    int id = index.data(Qt::UserRole + 1).toInt();
    pDll->setupFieldInScene(id);
}

