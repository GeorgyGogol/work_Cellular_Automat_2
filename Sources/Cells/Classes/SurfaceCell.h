#pragma once

#include "CellLevels.h"

namespace automat {

    class SurfaceCell
    {
    public:
        SurfaceCell();
        SurfaceCell(const CellLevels& levels);
        
        ~SurfaceCell() = default;

        //SurfaceCell(const SurfaceCell& src);
        //void operator=(const SurfaceCell& src);

        operator CellLevels() const;

    private:
        CellLevels Level;

    public:
        int getAltitude() const;
        void changeAltitude(int delta);
        void setAltitude(int value);

        int getLiquidCount() const;
        void changeLiquidCount(int delta);
        void setLiquidCount(int value);
        void setLiquidCount(int value, bool isUnderground);

        //int getSurfaceLevel() const;

    };

}

