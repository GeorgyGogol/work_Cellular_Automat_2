#pragma once

namespace automat {

    class UniqueIDController;

    class BaseManager
    {
    public:
        BaseManager(int startID = 0);
        ~BaseManager();

    protected:
        UniqueIDController* IDStorage;

    };
    

}

