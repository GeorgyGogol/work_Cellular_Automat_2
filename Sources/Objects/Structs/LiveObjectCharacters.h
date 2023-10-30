#pragma once

#include "CharacterValue.h"

struct LiveObjectCharacters_s
{
    int Strength;
    int Endurance;
};

struct LiveObjectCharacters
{
    LiveObjectCharacters() {
        Strength = 0;
        Endurance = 0;
    }

    LiveObjectCharacters(const LiveObjectCharacters_s& src)
    {
        Strength = src.Strength;
        Endurance = src.Endurance;
    }
    
    CharacterValue Strength;
    CharacterValue Endurance;
};



