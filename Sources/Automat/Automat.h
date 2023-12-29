#pragma once

#include "FieldProperties.h"

namespace automat {

    class FieldsManager;
    class AbstractField;

    class Automat
    {
    public:
        Automat();
        ~Automat();

    private:
        FieldsManager* Fields = nullptr;

    public:
        FieldsManager* const getFields();
        int createField(FieldProperties& properties);
        void deleteField(const int fieldID);


        //void getFieldList() const;

        //AbstractField* getLastCreatedField() const;

        void doStep();
        //void saveAutomat();
        //void loadAutomat();

    };

}

