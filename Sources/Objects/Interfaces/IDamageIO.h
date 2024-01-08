#pragma once

namespace automat {

    struct Damage;

    class IDamageIO
    {
    public:
        virtual ~IDamageIO() = default;

    public:
        virtual void RecieveDamage(const Damage& dmg) = 0;
        virtual void SendDamage(IDamageIO* reciver, int damageStrengh) = 0;
        //virtual void EmitDamage(IDamageIO* reciver, int points = 0) = 0;

    };

}

