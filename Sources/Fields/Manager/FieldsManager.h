#pragma once

#include <vector>
#include "FieldProperties.h"
#include "BaseManager.h"

namespace automat {

    class FieldsRecalcer;
    class AbstractField;

    typedef std::vector<FieldProperties> FieldListContainer;
    typedef std::vector<FieldProperties>::iterator FieldListIterator;

    class FieldsManager
        : public BaseManager
    {
    public:
        FieldsManager();
        ~FieldsManager();

    private:
        std::vector<AbstractField*> Fields;
        FieldListContainer FieldsInfo;
        FieldsRecalcer* Recalcer;

        int seekField(int id, int startEl, int endEl);

    public:
        int createField(FieldProperties& properties);
        void deleteField(int fieldID);

        int getFieldsCount() const;
        FieldListContainer getFieldList() const;
        AbstractField* const getField(int fieldID) const;

        FieldListIterator begin();
        FieldListIterator end();

        void recalcFields();

    };

}

