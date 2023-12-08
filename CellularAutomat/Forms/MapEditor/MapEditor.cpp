#include "stdafx.h"
#include "MapEditor.h"
#include "ui_MapEditor.h"

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
