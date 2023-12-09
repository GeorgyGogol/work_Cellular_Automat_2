#include "stdafx.h"
#include "MapEditor.h"
#include "ui_MapEditor.h"

#include <memory>
#include "MapSettings.h"

MapEditor::MapEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapEditorClass())
{
    ui->setupUi(this);
}

MapEditor::~MapEditor()
{
    delete ui;
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

}