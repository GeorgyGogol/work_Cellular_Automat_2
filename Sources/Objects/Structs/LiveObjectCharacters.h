#pragma once

#include "CharacterValue.h"

struct LiveObjectCharacters_s
{
    int Strength;
    int Endurance;
};

struct LiveObjectCharacters
{
    LiveObjectCharacters(const LiveObjectCharacters_s& src);
    
    CharacterValue Strength;
    CharacterValue Endurance;
};



