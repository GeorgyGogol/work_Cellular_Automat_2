#pragma once

namespace automat {

    class UniqueIDController;

    class ObjectID
    {
        friend class UniqueIDController;
        
    public:
        ObjectID(int id);
        ObjectID();
        virtual ~ObjectID() = default;

    private:
        int ID;

    public:
        int getID() const { return ID; }

    };

}

