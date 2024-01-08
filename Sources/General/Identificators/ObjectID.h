#pragma once

/// @file ObjectID.h
/// @brief Файл УИД объекта

/**
 * @details Пространство имен автомата
*/
namespace automat {

    class UniqueIDController;

    /**
     * @brief Класс УИД объекта
     * @details Хранит и предоставляет доступ к ID объекта. УИД
     * задается единожды, при создании, однако право на изменение ID
     * есть у UniqueIDController.
    */
    class ObjectID
    {
        friend class UniqueIDController;
        
    public:
        ObjectID(int id);
        ObjectID();
        virtual ~ObjectID() = default;

    private:
        int ID;

    public:
        int getID() const { return ID; }

    };

}

