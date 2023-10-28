#pragma once

class IDamageIO;

struct Damage
{
    IDamageIO* Emmiter = nullptr;
    IDamageIO* Reciver = nullptr;
    int Points = 0;

    static void send(const Damage& dmg);
    void send();
};

