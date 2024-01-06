#include "stdafx.h"
#include "MapListItemModel.h"
#include "MapListModelDefs.h"

MapListItemModel::MapListItemModel(QObject *parent)
    : QStandardItemModel(parent)
{}

MapListItemModel::~MapListItemModel()
{}

void MapListItemModel::deleteItemById(int id)
{
    QStandardItem* el;
    for (int i = 0; i < this->rowCount(); ++i) {
        el = item(i, 0);
        if (el->data(MapListModel::ID).toInt() == id) {
            removeRow(i);
            break;
        }
    }
}
