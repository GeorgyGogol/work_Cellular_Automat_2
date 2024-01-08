#include "BaseManager.h"
#include "UniqueIDController.h"

automat::BaseManager::BaseManager(int startID)
{
    IDStorage = new UniqueIDController(startID);
}

automat::BaseManager::~BaseManager()
{
    delete IDStorage;
}

