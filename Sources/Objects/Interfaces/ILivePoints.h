#pragma once

namespace automat {

    class ILivePoints
    {
    public:
        virtual ~ILivePoints() = default;

    public:
        virtual int getLivePointsMax() const = 0;
        virtual int getLivePoints() const = 0;
        virtual void addLivePoints(int delta) = 0;
        inline void removeLivePoints(int delta) { addLivePoints(-delta); }
        virtual bool isAlive() const = 0;

    };

}

