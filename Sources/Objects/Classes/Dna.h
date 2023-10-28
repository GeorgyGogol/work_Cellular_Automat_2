#pragma once

//#include "DnaPart.h"
#include "ObjectData.h"
#include "LiveObjectCharacters.h"
#include <vector>

class DNA
{
public:
    DNA();

private:
    float AccidentDeathModifier = 1;
    LiveObjectCharacters_s PartCharacter;
    //std::vector<BonusInfluence> InternalOrgans;

public:
    double getAccidentDeathModifier() const;
    void changeAccidentDeathModifier(double value);

    LiveObjectCharacters_s getCharacters() const;
    ObjectData_s getObjectData() const;
    
    RangedValue getLivePoints() const;

/*     int getInternalOrgansCount() const
    { return InternalOrgans.size(); }
    BonusInfluence* getInternalOrgan(int number);
    void addInternalOrgans(const BonusInfluence& organ);
    void removeInternalOrgan(int number); */


    /* DNA_Part* getPart(int nPart) const
    {
        return &Parts[nPart];
    } */

    //ObjectData_s getObjectDataForPart(int nPart);
    //LiveObjectCharacters getCharacters(int);


};

DNA mergeDna(int nDna, DNA* pDnas);

