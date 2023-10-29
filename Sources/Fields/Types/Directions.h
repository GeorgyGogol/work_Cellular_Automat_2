#pragma once

class Directions
{
public:
    Directions(int nDirs);
    Directions(int direction, int nDirs);
    //Directions(const Directions& src);

private:
    unsigned short int NDirections;
    unsigned short int Azimuth = 0;

protected:
    void Normalize(int& direction) const;

public:
    int getDirections() const;
    int getDirection() const;

    bool isDirectValide(int direction) const;

};

