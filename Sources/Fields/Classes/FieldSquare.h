#pragma once

#include "AbstractField.h"
#include "ICellAccess.h"
#include "SurfaceCell.h"

namespace automat {

    class FieldSquare
        : public AbstractField
        , public ICellAccess<SurfaceCell>
    {
    public:
        FieldSquare(const FieldProperties& props);
        virtual ~FieldSquare();

    private:
        int Width;
        SurfaceCell* Cells;

    public:
        int getFieldType() const override { return 1; }

        int getWidth(int onHeight = 0) const override;

        DirectionsStatuses getDirectionsForPoint(int x, int y) const;

        SurfaceCell* getCellAt(int x, int y) const override;

        void setCellAt(int x, int y, const SurfaceCell& cell) override;
    

        //bool isCanMove(int x, int y, Direction dir) const;
        //bool isCanMove(Point p, Direction dir) const { return isCanMove(p.X, p.Y, dir); }

        //Direction getDirectionFromVector(Point vector) const;
        //Point getVectorFromDirection(Direction direction) const;

    };
    
}

