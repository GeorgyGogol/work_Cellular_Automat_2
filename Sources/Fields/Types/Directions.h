#pragma once

#include "Direction.h"

class Directions
{
public:
    Directions(int nDirs);
    //Directions(int rawDirection, int nDirs);
    //Directions(const Directions& src);

private:
    unsigned short int NDirections;

protected:

public:
    int getDirections() const;
    bool isDirectValide(int direction) const;
    void normalize(int& rawDirection) const;
    
    virtual Direction getDirection(int rawDirection) const;

};

