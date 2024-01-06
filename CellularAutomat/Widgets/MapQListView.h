#pragma once

#include <QListView>

class MapQListView  : public QListView
{
    Q_OBJECT

public:
    MapQListView(QWidget *parent);
    ~MapQListView();

public:
    int getCurrentId() const;

};
