#pragma once

struct MapBrushSettings
{
    int Strength;
    bool IsInrease;

    inline int getIncraseMulti() const { return IsInrease ? 1 : -1; }
};

