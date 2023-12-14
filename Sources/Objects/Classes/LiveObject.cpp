#include "stdafx.h"
#include "LiveObject.h"

LiveObject::LiveObject(const DNA &dna)
    : Object(dna.getObjectData())
    , Characters(dna.getCharacters())
    , Live(dna.getLivePoints())
    , StoredEnergy(0)
    , Dna(new DNA(dna))
{
}

LiveObject::LiveObject(LiveObject &&from) noexcept
    : Object(from.Dna->getObjectData())
{
    Characters = from.Characters;
    Live = from.Live;
    StoredEnergy = from.StoredEnergy;
    Dna = from.Dna;
    from.Dna = nullptr;
    Age = from.Age;
}

/* LiveObject::LiveObject(const LiveObject &from)
{
} */

LiveObject &LiveObject::operator=(LiveObject &&from) noexcept
{
    // TODO: вставьте здесь оператор return
    if (this != &from)
    {
        Existance = from.Existance;

        Characters = from.Characters;
        Live = from.Live;
        StoredEnergy = from.StoredEnergy;
        Dna = from.Dna;
        from.Dna = nullptr;
        Age = from.Age;
    }
    return *this;
}

void LiveObject::setAge(int age)
{
    Age = age;
}

ObjectData LiveObject::getObjectData() const
{
    return ObjectData{ Existance };
}

void LiveObject::RecieveDamage(const Damage &dmg)
{

}

void LiveObject::SendDamage(IDamageIO *reciver, int damageStrengh)
{
}

int LiveObject::getLivePointsMax() const
{
    int out = Live.getMaxValue();
    return out;
}

int LiveObject::getLivePoints() const
{
    int out = Live.getValue();
    return out;
}

void LiveObject::addLivePoints(int delta)
{
    Live += delta;
}

bool LiveObject::isAlive() const
{
    return getLivePoints() > 0;
}

int LiveObject::getAge() const
{
    return Age;
}

void LiveObject::increaseAge(int delta)
{
    bool isDead = rand() % 2;
    
    Age += delta;

    /*
    if (!isDead){
        for (auto each : SubObjects) {
            each.setAge(Age);
        }
    }
    else {
        Live.setEmpty();
        for (auto each : SubObjects) {
            each.setAge(Age);
            each.Live.setEmpty();
        }
    }
    */
}