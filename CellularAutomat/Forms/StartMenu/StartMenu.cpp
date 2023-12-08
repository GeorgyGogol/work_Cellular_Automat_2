#include "stdafx.h"
#include "StartMenu.h"
#include "ui_StartMenu.h"

StartMenu::StartMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartMenuClass())
{
    ui->setupUi(this);

    connect(ui->pbMapEditor, &QPushButton::clicked, this, [=]() { emit MenuSelect(SelectResult::MapEditor); });
    connect(ui->bExit, &QPushButton::clicked, this, [=]() { emit MenuSelect(SelectResult::Exit); });
}

StartMenu::~StartMenu()
{
    delete ui;
}
