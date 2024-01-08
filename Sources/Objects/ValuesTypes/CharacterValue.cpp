#include "stdafx.h"
#include "CharacterValue.h"

using namespace automat;

CharacterValue::CharacterValue(const CharacterValue &src)
{
    Level = src.Level;
    CurrentUseExperience = src.CurrentUseExperience;
    NextLevelExperience = src.NextLevelExperience;
}

CharacterValue& CharacterValue::operator=(const CharacterValue &src)
{
    if (this != &src){
        Level = src.Level;
        CurrentUseExperience = src.CurrentUseExperience;
        NextLevelExperience = src.NextLevelExperience;
    }
    return *this;
}

CharacterValue::CharacterValue(int level) :
    Level(level)
{
    NextLevelExperience = calcNextLevelPoints(Level + 1);
}

CharacterValue& CharacterValue::operator=(int level)
{
    Level = level;
    NextLevelExperience = calcNextLevelPoints(Level + 1);
    return *this;
}

CharacterValue::operator int()
{
    return Level;
}

int CharacterValue::calcNextLevelPoints(int nextLevel) const
{
    return nextLevel * 2;
}

int CharacterValue::calcAllUseExperience(int level) const 
{
    int out = CurrentUseExperience;
    while (level > 0)
    {
        out += calcNextLevelPoints(level--);
    }
    return out;
}

int CharacterValue::getLevel() const 
{
    return Level; 
}

void CharacterValue::setLevel(int level)
{
    Level = level;
    NextLevelExperience = calcNextLevelPoints(Level + 1);
}

void CharacterValue::increaceLevel()
{
    NextLevelExperience = calcNextLevelPoints(++Level + 1);
}

int CharacterValue::getUseExperience() const 
{
    return CurrentUseExperience;
}

int CharacterValue::getMaxExperience() const 
{
    return NextLevelExperience; 
}

void CharacterValue::addUse(int value)
{
    CurrentUseExperience += value;
    if (CurrentUseExperience >= NextLevelExperience) {
        Level++;
        NextLevelExperience = calcNextLevelPoints(Level + 1);
    }
}

void CharacterValue::remUse(int value)
{
    if (CurrentUseExperience - value > 0) {
        CurrentUseExperience -= value;
    }
    else {
        NextLevelExperience = calcNextLevelPoints(Level--);
        CurrentUseExperience = NextLevelExperience - (value - CurrentUseExperience);
    }
}

int CharacterValue::getTotalUseExperience() const
{
    return calcAllUseExperience(Level);
}

