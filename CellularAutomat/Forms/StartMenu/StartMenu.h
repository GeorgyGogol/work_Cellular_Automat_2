#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StartMenuClass; };
QT_END_NAMESPACE

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private:
    Ui::StartMenuClass *ui;

public:
    enum SelectResult
    {
        None = 100,
        MapEditor,
        Exit = 0
    };

signals:
    void MenuSelect(int);

};
