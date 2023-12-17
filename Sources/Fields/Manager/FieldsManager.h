#pragma once

#include <vector>
#include "FieldProperties.h"

namespace automat {

    class FieldsRecalcer;
    class AbstractField;

    class FieldsManager
    {
    public:
        FieldsManager();
        ~FieldsManager();

    private:
        std::vector<AbstractField*> Fields;
        FieldsRecalcer* Recalcer;

    public:
        void createField(const FieldProperties& properties);
        AbstractField* getLastField() const;

        void recalcFields();

    };

}

