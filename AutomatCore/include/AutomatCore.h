#pragma once

#include "automatcore_global.h"
#include "CoreProperties.h"

QT_BEGIN_NAMESPACE
class QStandardItemModel;
QT_END_NAMESPACE

namespace automat {
    class Automat;
}

class AutomatFieldScene;

/**
 * @brief Управляющий автоматом и отображением класс
 * @details Это класс для управления автоматом и созданием GUI в среде Qt
*/
class AUTOMATCORE_EXPORT AutomatCore
{
public:
    AutomatCore();
    ~AutomatCore();

private:
    /// @brief Указатель на экземпляр автомата
    automat::Automat* pAutomat;

    /// @brief Указатель на сцену с картой
    AutomatFieldScene* FieldScene = nullptr;

    /// @brief Указатель на модель списка карт
    QStandardItemModel* FieldListModel = nullptr;

public:
    /// @brief Получение указателя сцены карты
    /// @return Указатель на сцену с картой
    AutomatFieldScene* getFieldScenePtr();

    /// @brief Метод создания поля
    /// @param settings Настройки поля
    /// @return ID созданного поля
    void createField(FieldInformation& settings);

    /// @brief Метод получения списка полей (с подробной информацией)
    /// @return Список полей
    FieldList getFieldList();

    /// @brief Метод удаления поля
    /// @param fieldID ID поля
    void deleteField(int fieldID);

/*     void saveField(int fieldID, const QString& filePath);
    int loadField(const QString& filePath); */

    /// @brief Метод установки поля в сцену
    /// @param fieldID ID поля
    void setupFieldInScene(int fieldID);

    /// @brief Метод очистки поля
    inline void resetCurrentScene() { setupFieldInScene(-1); }

    /// @brief Метод получения модели списка полей (для отображения)
    /// @return Указатель на модель со списком
    QStandardItemModel* getMapListModel();

};

