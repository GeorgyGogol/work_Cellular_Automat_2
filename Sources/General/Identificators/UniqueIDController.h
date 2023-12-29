#pragma once

#include "ObjectID.h"

namespace automat {

    class UniqueIDController
    {
    public:
        UniqueIDController(int startID = 0);

    private:
        int StartID;
        int NextID;

    public:
        int getStartID() const;
        int getNextID();
        int getCurrentMaxID() const;

        void refreshIDs(ObjectID** objectsArray, int nObjects);
        void setupNextID(ObjectID* pObject);

        bool checkIdInRange(int id) const;

    };

}

