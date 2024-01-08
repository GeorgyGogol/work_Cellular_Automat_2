#include "stdafx.h"
#include "Damage.h"
#include "IDamageIO.h"

using namespace automat;

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

