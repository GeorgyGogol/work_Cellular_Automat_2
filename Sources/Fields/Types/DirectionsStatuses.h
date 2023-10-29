#pragma once

#include "Directions.h"

class DirectionsStatuses
    : public Directions
{
public:
    DirectionsStatuses(int nDirs);
    ~DirectionsStatuses();

private:
    bool* DirectionsStats;

public:
    bool getStatus(int direction) const;
    void setStatus(int direction, bool status);

};

