#pragma once

#include <list>
//#include "IContainerManager.h"
//#include "Object.h"
#include "ObjectData.h"
#include "BaseManager.h"

namespace automat {

    class Object;
    class UniqueIDController;

    class ObjectManager 
        : public BaseManager
        //: public IManager<Object>
    {
    public:
        ObjectManager();
        ~ObjectManager();

    private:
        std::list<Object*> ObjectsList;
        //std::list<Object*>::iterator it;

    public:
        int createObject(ObjectData& objectInfo);


        void AddObject(Object* object);

        void RefreshObjects();

        /* 
        Object* Begin();
        Object* End();
        Object* Next();

        Object* First() const;
        Object* Last() const;
        Object* Current() const; 
        */

        int Count() const;

    };

}

