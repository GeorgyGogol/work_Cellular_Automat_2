#include "stdafx.h"
#include "DNA.h"

using namespace automat;

DNA::DNA()
{
    //PartCharacter.Strength = 0;
    //PartCharacter.Endurance = 0;
}

double DNA::getAccidentDeathModifier() const
{
    return AccidentDeathModifier;
}

void DNA::changeAccidentDeathModifier(double value)
{
    AccidentDeathModifier += value;
}

double DNA::getMutateModifier() const
{
    return MutateModifier;
}

void DNA::changeMutateModifier(double value)
{
    MutateModifier += value;
}

/* 
LiveObjectCharacters_s DNA::getCharacters() const
{
    return PartCharacter;
}

ObjectData_s DNA::getObjectData() const
{
    ObjectData_s out;
    out.Existance = PartCharacter.Endurance * 5;
    return out;
}

RangedValue DNA::getLivePoints() const
{
    return RangedValue(PartCharacter.Endurance * 5);
} 
*/

DNA mergeDna(int nDna, DNA *pDnas)
{
    DNA out;
    return out;
}
