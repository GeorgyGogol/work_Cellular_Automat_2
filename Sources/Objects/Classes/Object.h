#pragma once

#include "ObjectData.h"
#include "IExistancePoints.h"
#include "IDamageIO.h"

class Object
    : public IExistancePoints
    , public IDamageIO
{
public:
    Object(const ObjectData& op);
    Object(const ObjectData_s& op);

private:

protected:
    RangedValue Existance;
    // temperature

public:
    int getExistancePointsMax() const override;
    int getExistancePoints() const override;
    void addExistancePoints(int delta) override;
    bool isExists() const override;

    void RecieveDamage(const Damage& dmg) override;
    void SendDamage(IDamageIO* reciver, int damageStrengh) override;

};

