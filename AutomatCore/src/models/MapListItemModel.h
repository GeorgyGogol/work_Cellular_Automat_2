#pragma once

#include <QStandardItemModel>

class MapListItemModel
    : public QStandardItemModel
{
    Q_OBJECT

public:
    MapListItemModel(QObject *parent = nullptr);
    ~MapListItemModel();

public:
    void deleteItemById(int id);

};

