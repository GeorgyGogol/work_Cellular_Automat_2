#pragma once

#include "Object.h"
#include "LiveObjectCharacters.h"
#include "ILivePoints.h"
//#include "IMoveAction.h"
#include "IImpactedObject.h"
#include "DNA.h"

#include <vector>


class LiveObject
    : public Object
    , public ILivePoints
    //, public IMoveAction
{
public:
    LiveObject(const DNA& dna);
    LiveObject(const LiveObject& from) = delete;
    LiveObject(LiveObject&& from) noexcept;
    ~LiveObject()
    {
        if (Dna) delete Dna;
    }

    LiveObject& operator=(LiveObject& src) = delete;
    LiveObject& operator=(LiveObject&& from) noexcept;

private:
//protected:
	RangedValue Live;
	int Age = 0;
	
    LiveObjectCharacters Characters;
    EnergyValue StoredEnergy = 0;
    DNA* Dna;

private:
    void setAge(int age);

    //std::vector<LiveObjectCharacters> SubObjects;
    //std::vector<IImpactedObject*> InternalOrgans;

    ObjectData getObjectData() const;


public:
    void RecieveDamage(const Damage& dmg) override;
    void SendDamage(IDamageIO* reciver, int damageStrengh) override;

    int getLivePointsMax() const override;
    int getLivePoints() const override;
    void addLivePoints(int delta) override;
    bool isAlive() const override;

    int getAge() const;
    void increaseAge(int delta);

};


