#include "stdafx.h"
#include "MapQListView.h"

#include "CoreProperties.h"

MapQListView::MapQListView(QWidget *parent)
    : QListView(parent)
{}

MapQListView::~MapQListView()
{}

int MapQListView::getCurrentId() const
{
    return currentIndex().data(Qt::UserRole + 1).toInt();
}
