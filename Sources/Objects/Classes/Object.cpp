#include "stdafx.h"
#include "Object.h"

#include "Damage.h"

Object::Object(const ObjectData& op)
    : Existance(op.Existance)
{
}

Object::Object(const ObjectData_s &op)
    : Existance(op.Existance)
{
}

int Object::getExistancePointsMax() const
{
    return Existance.getMaxValue();
}

int Object::getExistancePoints() const
{
    return Existance.getValue();
}

void Object::addExistancePoints(int delta)
{
    Existance.addValue(delta);
}

bool Object::isExists() const
{
    return !Existance.isEmpty();
}

void Object::RecieveDamage(const Damage& dmg)
{
    removeExistancePoints(dmg.Points);
    //dmg.Emmiter->RecieveDamage(dmg);
}

void Object::SendDamage(IDamageIO* reciver, int damageStrengh)
{
    Damage dmg;
    dmg.Reciver = reciver;
    dmg.Emmiter = this;
    dmg.Points = damageStrengh;
    reciver->RecieveDamage(dmg);
}


