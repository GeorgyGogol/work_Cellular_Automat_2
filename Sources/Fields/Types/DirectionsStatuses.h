#pragma once

#include "Directions.h"

namespace automat {

    class DirectionsStatuses
        : public Directions
    {
    public:
        DirectionsStatuses(int nDirs);
        
        DirectionsStatuses(const DirectionsStatuses& src) noexcept;
        DirectionsStatuses(DirectionsStatuses&& from) noexcept;

        virtual ~DirectionsStatuses();

        static DirectionsStatuses CreateInvalide();

    public:
        DirectionsStatuses& operator=(const DirectionsStatuses& src) noexcept;
        DirectionsStatuses& operator=(DirectionsStatuses&& from) noexcept;
        

    private:
        bool* DirectionsStats = nullptr;

    public:
        bool getStatus(int direction) const;
        void setStatus(int direction, bool status);

        Direction getDirection(int rawDirection) const override;

        void resetStatuses(bool resetValue = true);

        bool isValide() const;

    };

}

