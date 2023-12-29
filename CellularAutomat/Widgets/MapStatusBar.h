#pragma once

#include <QStatusBar>

class MapStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    MapStatusBar(QWidget *parent);
    ~MapStatusBar();
};
