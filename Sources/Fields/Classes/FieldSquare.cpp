#include "stdafx.h"
#include "FieldSquare.h"

FieldSquare::FieldSquare(int height, int width)
    : AbstractField(height, 8)
    , Width(width)
{
    Cells = new SurfaceCell[Height * Width];
}

FieldSquare::~FieldSquare()
{
    delete[] Cells;
}

int FieldSquare::getWidth(int onHeight) const
{
    return Width;
}

DirectionsStatuses FieldSquare::getDirectionsForPoint(int x, int y) const
{
    //if (!isCoordValide(x, y)) return;
    DirectionsStatuses out(0); // (AvalableDirections);
    return out;
}

SurfaceCell* FieldSquare::getCellAt(int x, int y) const
{
    if (!isCoordValide(x, y)) return nullptr;
    return &Cells[x + y * Width];
}

void FieldSquare::setCellAt(int x, int y, const SurfaceCell &cell)
{
    if (!isCoordValide(x, y)) return;
    Cells[x + y * Width] = cell;
}

