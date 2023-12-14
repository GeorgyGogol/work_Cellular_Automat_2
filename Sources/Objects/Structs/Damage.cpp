#include "stdafx.h"
#include "Damage.h"
#include "IDamageIO.h"

void Damage::send(const Damage &dmg)
{
    if (!dmg.Reciver) return;
    dmg.Reciver->RecieveDamage(dmg);
}

void Damage::send()
{
    if (!Reciver) return;
    Reciver->RecieveDamage(*this);
}

