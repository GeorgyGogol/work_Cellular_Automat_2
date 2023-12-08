#include "stdafx.h"
#include "AppCore.h"

#include "StartMenu.h"
#include "MapEditor.h"

AppCore::AppCore(QObject *parent)
    : QObject(parent)
{
    StartMenuPtr = new StartMenu();
    connect(StartMenuPtr, &StartMenu::MenuSelect, this, &AppCore::StartMenuResult);

    MapEditorPtr = new MapEditor();
    connect(MapEditorPtr, &MapEditor::Closed, StartMenuPtr, &StartMenu::show);
}

AppCore::~AppCore()
{
    delete StartMenuPtr;
    delete MapEditorPtr;
}

void AppCore::Run()
{
    StartMenuPtr->show();
}

void AppCore::StartMenuResult(int result)
{
    StartMenuPtr->hide();
    switch (result) {
    case StartMenu::SelectResult::MapEditor:
        MapEditorPtr->show();
        break;

    case StartMenu::SelectResult::Exit:
        exit(0);
        break;

    default:
        QMessageBox::information(nullptr, "StartMenuResult", "default(((");
        StartMenuPtr->show();

    }
}

