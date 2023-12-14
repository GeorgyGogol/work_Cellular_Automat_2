#include "stdafx.h"
#include "SimpleSquareTestField.h"

SimpleSquareTestField::SimpleSquareTestField(int height, int width)
    : AbstractField(height, 8)
    , Width(width)
{
    Cells = new int[Height * Width] {0} ;
}

SimpleSquareTestField::~SimpleSquareTestField()
{
    delete[] Cells;
}

int* SimpleSquareTestField::CellAt(int x, int y) const
{
    return &Cells[x + y * Width];
}

int SimpleSquareTestField::getWidth(int onHeight) const
{
    return Width;
}

DirectionsStatuses SimpleSquareTestField::getDirectionsForPoint(int x, int y) const
{
    if (!isCoordValide(x, y)) return DirectionsStatuses::CreateInvalide();
    DirectionsStatuses out(getGeneralDirections());

    Point pos = Point(x - 1, y - 1);
    int minAlt = *CellAt(x, y) - 1;
    int maxAlt = *CellAt(x, y) + 1;
    int cell;

    cell = *CellAt(pos.X, pos.Y);
    out.setStatus(7, cell >= minAlt && cell <= maxAlt);

    pos.X++;
    for (int i = 0; i < 7; ++i) {
        cell = *CellAt(pos.X, pos.Y);
        out.setStatus(i, cell >= minAlt && cell <= maxAlt);

        pos.X++;
        if (pos.X == x && pos.Y == y) {
            pos.X++;
        }

        if (pos.X == x + 2) {
            pos.Y++;
            pos.X = x - 1;
        }
    }


    return out;
}

int* SimpleSquareTestField::getCellAt(int x, int y) const
{
    if (!isCoordValide(x, y)) return nullptr;
    return CellAt(x, y);
}

void SimpleSquareTestField::setCellAt(int x, int y, const int &cell)
{
    if (!isCoordValide(x, y)) return;
    Cells[x + y * Width] = cell;
}

