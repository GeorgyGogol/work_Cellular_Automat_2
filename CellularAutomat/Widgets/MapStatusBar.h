#pragma once

#include <QStatusBar>
#include "CoreProperties.h"

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MapStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    MapStatusBar(QWidget *parent);
    ~MapStatusBar();

private:
    QLabel* mapName;
    QLabel* mapType;
    QLabel* mapSize;

public:

public slots:
    void setMapName(QString name);
    void setMapType(QString type);
    void setMapSize(int width, int height);
    
    void Clear();

    void RecieveInfo(const FieldInformation& data);

};
