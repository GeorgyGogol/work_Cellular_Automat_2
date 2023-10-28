#pragma once

class CharacterValue
{
public:

public:
    CharacterValue() = default;

    CharacterValue(const CharacterValue& src);
    CharacterValue& operator=(const CharacterValue& src);

    CharacterValue(int level);
    CharacterValue& operator=(int level);

    operator int();

private:
    int Level = 0;
    int CurrentUseExperience = 0;
    int NextLevelExperience = 0;

    int calcNextLevelPoints(int nextLevel) const;
    int calcAllUseExperience(int level) const;

public:
    int getLevel() const;
    void setLevel(int level);
    void increaceLevel();

    int getUseExperience() const;
    int getMaxExperience() const;

    void addUse(int value);
    void remUse(int value);

    int getTotalUseExperience() const;

};

