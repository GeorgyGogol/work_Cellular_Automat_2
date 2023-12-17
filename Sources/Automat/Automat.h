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
        void createField(const FieldProperties& properties);
        AbstractField* getLastCreatedField() const;

        void doStep();

    };

}

