#pragma once

#include "Directions.h"

class DirectionsStatuses
    : public Directions
{
public:
    DirectionsStatuses(int nDirs);
    
    virtual ~DirectionsStatuses();

public:
    

private:
    bool* DirectionsStats;

public:
    bool getStatus(int direction) const;
    void setStatus(int direction, bool status);

    Direction getDirection(int rawDirection) const override;

};

