#include "FieldSquare.h"

FieldSquare::FieldSquare(int height, int width)
    : BaseField(height, 8)
    , Width(width)
{
}

FieldSquare::~FieldSquare()
{
}

void FieldSquare::CreateField() override
{
    Cells = new SurfaceCell[Height * Width];
}

void FieldSquare::DeleteField() override
{
    delete[] Cells;
    Cells = nullptr;
}

void FieldSquare::CopyField(const BaseField& src) override
{
    FieldSquare* base = static_cast<FieldSquare*>(&src);

    if(Cells) DeleteField();

    Width = base->Width;
    Height = base->Height;

    CreateField();

    for (int i = 0; i < Width * Height; ++i)
    {
        Cells[i] = base->Cells[i];
    }
}

void FieldSquare::MoveField(BaseField&& src) noexcept override
{
    FieldSquare* base = static_cast<FieldSquare*>(&src);

    if(Cells) DeleteField();

    Width = base->Width;
    Height = base->Height;

    Cells = base->Cells;
    base->Cells = nullptr;
}

int FieldSquare::getWidth(int onHeight) const
{
    return Width;
}

DirectionsStatuses& FieldSquare::getDirectionsForPoint(int x, int y) const
{
    if (!isCoordValide(x, y)) return;
    DirectionsStatuses out(AvalableDirections);
    return out;
}

SurfaceCell FieldSquare::getCellAt(int x, int y) const
{
    if (!isCoordValide(x, y)) return;
    return Cells[x + y * Width];
}

void FieldSquare::setCellAt(int x, int y, const SurfaceCell &cell)
{
    if (!isCoordValide(x, y)) return;
    Cells[x + y * Width] = cell;
}

