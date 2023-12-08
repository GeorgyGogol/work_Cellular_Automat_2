#pragma once

#include <QObject>

class StartMenu;
class MapEditor;

class AppCore  : public QObject
{
    Q_OBJECT

public:
    explicit AppCore(QObject *parent = nullptr);
    ~AppCore();

    void Run();

private:
    StartMenu* StartMenuPtr;
    MapEditor* MapEditorPtr;

public slots:
    void StartMenuResult(int result);

};
