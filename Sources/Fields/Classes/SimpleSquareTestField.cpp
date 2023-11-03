#include "SimpleSquareTestField.h"

SimpleSquareTestField::SimpleSquareTestField(int height, int width)
    : BaseField(height, 8)
{
}

SimpleSquareTestField::~SimpleSquareTestField()
{
}

void SimpleSquareTestField::CreateField()
{
    Cells = new int[Height * Width] {0} ;
}

void SimpleSquareTestField::DeleteField()
{
    delete[] Cells;
    Cells = nullptr;
}

int SimpleSquareTestField::getWidth(int onHeight) const
{
    return Width;
}

DirectionsStatuses &SimpleSquareTestField::getDirectionsForPoint(int x, int y) const
{
    //if (!isCoordValide(x, y)) return DirectionsStatuses();
    DirectionsStatuses out (4); // (getGeneralDirections());
    return out;
}

int SimpleSquareTestField::getCellAt(int x, int y) const
{
    if (!isCoordValide(x, y)) return 0;
    return Cells[x + y * Width];
}

void SimpleSquareTestField::setCellAt(int x, int y, const int &cell)
{
    if (!isCoordValide(x, y)) return;
    Cells[x + y * Width] = cell;
}

