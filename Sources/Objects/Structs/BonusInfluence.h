#pragma once

enum class ImpactType : unsigned short
{
    None = 0,
    
    Damage, 
    Move,
    Strenght,
    EnergyStorage,
    EnergyGenerate
};

struct BonusInfluence
{
    int Value = 0;
    ImpactType Type = ImpactType::None;
};

