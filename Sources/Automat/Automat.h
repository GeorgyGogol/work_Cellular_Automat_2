#pragma once

#include "FieldProperties.h"
#include "ObjectData.h"

namespace automat {

    class FieldsManager;
    class AbstractField;

    class ObjectManager;

    class Automat
    {
    public:
        Automat();
        ~Automat();

    private:
        FieldsManager* Fields = nullptr;
        ObjectManager* Objects = nullptr;

    public:
        FieldsManager* const getFields();
        int createField(FieldProperties& properties);
        void deleteField(const int fieldID);

        ObjectManager* const getObjects();
        int createObject(ObjectData& objectInfo);
        
        //int createObject
        //int createLiveObject();


        //void getFieldList() const;

        //AbstractField* getLastCreatedField() const;

        void doStep();
        //void saveAutomat();
        //void loadAutomat();

    };

}

