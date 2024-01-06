#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MapSettingsClass; };
QT_END_NAMESPACE

class ResCore;

class MapSettings : public QDialog
{
    Q_OBJECT

public:
    MapSettings(QWidget *parent = nullptr);
    ~MapSettings();

private:
    Ui::MapSettingsClass *ui;
    int MapTypeIndex = 0;
    int Height = 4;
    int Width = 4;
    ResCore* Resources;
    
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
    
    QString getMapName() const;

public slots:
    void MapTypeChange(int);
    void MapHeightChange(int);
    void MapWidthChange(int);


};
