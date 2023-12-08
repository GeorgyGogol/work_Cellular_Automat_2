#include "stdafx.h"
#include "ObjectsEditor.h"
#include "ui_ObjectsEditor.h"

ObjectsEditor::ObjectsEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ObjectsEditorClass())
{
    ui->setupUi(this);
}

ObjectsEditor::~ObjectsEditor()
{
    delete ui;
}
