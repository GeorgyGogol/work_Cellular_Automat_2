#pragma once

/// @file AbstractField.h
/// @brief Файл абстракции поля
/// @details В этом файле описывается базовый класс поля

#include "Directions.h"
#include "DirectionsStatuses.h"
#include "Point.h"
#include "ObjectID.h"
#include "FieldProperties.h"
#include <string>

/**
 * @brief Абстракция поля
 * @details Этот класс является общим классом для всех полей, отвечая
 * только за базовые свойства - Название, Кол-во направлений движения.
 * УИД идет делегация классу ObjectID. Такие свойства как высота и
 * ширина оставлены на попечение дочерним классам, так как именно
 * дочерние классы определяют суть поля. Но абстракция задает интерфейс
 * для взаимодействия с дочерними сойствами, так же давая интерфейс
 * проверки валидности координаты, проверки типа поля, значения
 * минимальной и максимальной точек.
*/
namespace automat {

    class AbstractField
        : public ObjectID
    {
    public:
        AbstractField(const FieldProperties& props, int rawDirsCount);
        virtual ~AbstractField();

    private:
        /// @brief Количество направлений на карте
        Directions AvalableDirections;

        /// @brief Название карты
        std::string MapName;

    protected:
        int Height;

    public:
        int getHeight() const;
        virtual int getWidth(int onHeight = 0) const = 0;
        Directions getGeneralDirections() const;
        std::string getMapName() const;

        virtual bool isCoordValide(int x, int y) const;
        inline bool isCoordValide(Point p) const { return isCoordValide(p.X, p.Y); }

        virtual DirectionsStatuses getDirectionsForPoint(int x, int y) const = 0;

        virtual int getFieldType() const = 0;

        virtual int getMinPoint() const = 0;
        virtual int getMaxPoint() const = 0;

    };

}

