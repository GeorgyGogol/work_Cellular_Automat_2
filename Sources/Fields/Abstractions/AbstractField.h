#pragma once

/// @file AbstractField.h
/// @brief Файл абстракции поля
/// @details В этом файле описывается базовый класс поля

#include "Directions.h"
#include "DirectionsStatuses.h"
#include "Point.h"

/**
 * @brief Абстракция поля
 * 
 * @details
*/
namespace automat {

    class AbstractField
    {
    public:
        AbstractField(int height, int rawDirsCount);
        virtual ~AbstractField();

    private:
        Directions AvalableDirections;

    protected:
        int Height;

    public:
        int getHeight() const;
        virtual int getWidth(int onHeight = 0) const = 0;
        Directions getGeneralDirections() const;

        virtual bool isCoordValide(int x, int y) const;
        inline bool isCoordValide(Point p) const { return isCoordValide(p.X, p.Y); }

        virtual DirectionsStatuses getDirectionsForPoint(int x, int y) const = 0;

        virtual int getFieldType() const = 0;

    };

}

