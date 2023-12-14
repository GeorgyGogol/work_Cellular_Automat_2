#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MapEditorClass; };
QT_END_NAMESPACE

class AutomatCore;

class MapEditor : public QMainWindow
{
    Q_OBJECT

public:
    MapEditor(QWidget *parent = nullptr);
    ~MapEditor();

private:
    Ui::MapEditorClass *ui;
    AutomatCore* pDll;

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void Closed();

public slots:
    void on_action_CreateNewMap_triggered();

};

