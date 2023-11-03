#pragma once

#include "Directions.h"
#include "DirectionsStatuses.h"
#include "Point.h"

class BaseField
{
public:
    BaseField(int height, int rawDirsCount);
    virtual ~BaseField();

private:
    Directions AvalableDirections;

protected:
    int Height;

public:
    int getHeight() const;
    virtual int getWidth(int onHeight = 0) const = 0;
    Directions getGeneralDirections() const;

    virtual bool isCoordValide(int x, int y) const;
    inline bool isCoordValide(Point p) const { return isCoordValide(p.X, p.Y); }

    virtual DirectionsStatuses& getDirectionsForPoint(int x, int y) const = 0;

};

