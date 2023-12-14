#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MapSettingsClass; };
QT_END_NAMESPACE

class MapSettings : public QDialog
{
    Q_OBJECT

public:
    MapSettings(QWidget *parent = nullptr);
    ~MapSettings();

private:
    Ui::MapSettingsClass *ui;
    int MapTypeIndex = 0, 
        Height = 0, 
        Width = 0;
    
    void RecalcMapSize();

public:
    inline int getMapType() const {
        return MapTypeIndex;
    }
    inline int getMapHeight() const {
        return Height;
    }
    inline int getMapWidth() const { 
        return Width; 
    }

public slots:
    void MapTypeChange(int);
    void MapHeightChange(int);
    void MapWidthChange(int);


};
