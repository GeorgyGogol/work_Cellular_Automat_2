#pragma once

#include "AbstractField.h"
#include "ICellAccess.h"

namespace automat {

    class SimpleSquareTestField
        : public AbstractField
        , public ICellAccess<int>
    {
    public:
        SimpleSquareTestField(const FieldProperties& props);
        virtual ~SimpleSquareTestField();

    private:
        int Width;
        int* Cells;

        int* CellAt(int x, int y) const;

    public:
        int getFieldType() const override { return 0; }

        int getWidth(int onHeight = 0) const override;

        DirectionsStatuses getDirectionsForPoint(int x, int y) const;

        int* getCellAt(int x, int y) const override;

        void setCellAt(int x, int y, const int& cell) override;
    

        //bool isCanMove(int x, int y, Direction dir) const;
        //bool isCanMove(Point p, Direction dir) const { return isCanMove(p.X, p.Y, dir); }

        //Direction getDirectionFromVector(Point vector) const;
        //Point getVectorFromDirection(Direction direction) const;

    };
    
}


