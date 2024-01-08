#include "stdafx.h"
#include "Object.h"

#include "Damage.h"

automat::Object::Object(const automat::ObjectData& op)
    : ObjectID(op.ID)
    , Existance(op.Existance)
{
}

/* automat::Object::Object(const automat::ObjectData_s &op)
    : Existance(op.Existance)
{
} */

int automat::Object::getExistancePointsMax() const
{
    return Existance.getMaxValue();
}

int automat::Object::getExistancePoints() const
{
    return Existance.getValue();
}

void automat::Object::addExistancePoints(int delta)
{
    Existance.addValue(delta);
}

bool automat::Object::isExists() const
{
    return !Existance.isEmpty();
}

void automat::Object::RecieveDamage(const Damage& dmg)
{
    removeExistancePoints(dmg.Points);
    //dmg.Emmiter->RecieveDamage(dmg);
}

void automat::Object::SendDamage(IDamageIO* reciver, int damageStrengh)
{
    Damage dmg;
    dmg.Reciver = reciver;
    dmg.Emmiter = this;
    dmg.Points = damageStrengh;
    reciver->RecieveDamage(dmg);
}


