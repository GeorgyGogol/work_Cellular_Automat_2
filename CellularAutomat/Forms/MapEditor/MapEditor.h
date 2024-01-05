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

    void setStatusWithMap(bool isHaveMap);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void Closed();

public slots:
    void on_action_CreateNewMap_triggered();
    void on_action_LoadMap_triggered();
    void on_action_SaveMap_triggered();
    void on_action_CloseMap_triggered();

    void on_pb_ResetScale_clicked();
    void setMainViewScale(int value);

    void on_cb_PaintGrid_toggled(bool value);
    void on_cb_PaintInfo_toggled(bool value);
    void on_cb_Directions_toggled(bool value);

    void on_MapListView_clicked(QModelIndex index);

};

