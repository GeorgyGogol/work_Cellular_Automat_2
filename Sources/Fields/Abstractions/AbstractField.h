#pragma once

#include "Directions.h"
#include "DirectionsStatuses.h"
#include "Point.h"

class BaseField
{
public:
    BaseField(int height, int rawDirsCount);
    virtual ~BaseField();

    BaseField(const BaseField& src);
    BaseField(BaseField&& from) noexcept;

private:
    Directions AvalableDirections;

    virtual void CreateField() = 0;
    virtual void DeleteField() = 0;
    virtual void CopyField(const BaseField& src) = 0;
    virtual void MoveField(BaseField&& src) noexcept = 0;

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

