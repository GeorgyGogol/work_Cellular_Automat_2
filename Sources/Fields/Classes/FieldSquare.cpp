#include "FieldSquare.h"

FieldSquare::FieldSquare(int height, int width)
    : BaseField(height, 8)
    , Width(width)
{
}

FieldSquare::~FieldSquare()
{
}

void FieldSquare::CreateField()
{
    Cells = new SurfaceCell[Height * Width];
}

void FieldSquare::DeleteField()
{
    delete[] Cells;
    Cells = nullptr;
}

int FieldSquare::getWidth(int onHeight) const
{
    return Width;
}

DirectionsStatuses& FieldSquare::getDirectionsForPoint(int x, int y) const
{
    //if (!isCoordValide(x, y)) return;
    DirectionsStatuses out(0); // (AvalableDirections);
    return out;
}

SurfaceCell FieldSquare::getCellAt(int x, int y) const
{
    if (!isCoordValide(x, y)) return SurfaceCell();
    return Cells[x + y * Width];
}

void FieldSquare::setCellAt(int x, int y, const SurfaceCell &cell)
{
    if (!isCoordValide(x, y)) return;
    Cells[x + y * Width] = cell;
}

