#pragma once

#include "Direction.h"

class Directions
{
public:
    Directions(int nDirs);
    Directions(Direction maxDirection);

    virtual ~Directions() = default;

    operator int();

private:
    unsigned short int NDirections;

protected:

public:
    int getRawDirections() const;
    bool isDirectValide(int direction) const;
    void normalize(int& rawDirection) const;
    
    virtual Direction getDirection(int rawDirection) const;

};

