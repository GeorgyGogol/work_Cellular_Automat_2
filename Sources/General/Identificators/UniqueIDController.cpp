#include "stdafx.h"
#include "UniqueIDController.h"

automat::UniqueIDController::UniqueIDController(int startID)
    : StartID(startID)
    , NextID(startID)
{
}

int automat::UniqueIDController::getStartID() const
{
    return StartID;
}

int automat::UniqueIDController::getNextID()
{
    return NextID++;
}

int automat::UniqueIDController::getCurrentMaxID() const
{
    return NextID - 1;
}

void automat::UniqueIDController::refreshIDs(ObjectID **objectsArray, int nObjects)
{
    int newNextID = StartID;
    ObjectID* ptr = nullptr;
    for (int i = 0; i < nObjects; ++i, ++newNextID) {
        ptr = objectsArray[i];
        if(ptr->getID() != newNextID) {
            ptr->ID = newNextID;
        }
    }
    NextID = newNextID + 1;
}

void automat::UniqueIDController::setupNextID(ObjectID *pObject)
{
    pObject->ID = getNextID();
}

bool automat::UniqueIDController::checkIdInRange(int id) const
{
    return id > StartID - 1 && id < NextID;
}
