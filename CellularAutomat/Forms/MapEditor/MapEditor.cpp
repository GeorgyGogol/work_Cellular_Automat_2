#include "stdafx.h"
#include "MapEditor.h"
#include "ui_MapEditor.h"

#include <memory>
#include "MapSettings.h"

#include "AutomatCore.h"

MapEditor::MapEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapEditorClass())
{
    ui->setupUi(this);
    pDll = new AutomatCore();
}

MapEditor::~MapEditor()
{
    delete ui;
    delete pDll;
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

    FieldProperties newFieldSettings;
    newFieldSettings.Height = dialog->getMapHeight();
    newFieldSettings.Width = dialog->getMapWidth();
    newFieldSettings.Type = FieldProperties::FieldTypes(dialog->getMapType());

    ui->mainView->setScene(pDll->createField(newFieldSettings));
}

