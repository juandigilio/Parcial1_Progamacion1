#include "Armor.h"

Armor::Armor()
{

}

Armor::Armor(string name, ArmorType armorType, float defense, float weight, float criticalRateReduction)
{
    this->name = name;
    this->armorType = armorType;
    this->defense = defense;
    this->weight = weight;
    this->critRateReduction = criticalRateReduction;
}

Armor::~Armor()
{
}

float Armor::GetDmgReductionPerc(float damage)
{
    float damageReduction = 0.8f / (damage / defense);

    if (damageReduction > 0.8f)
    {
        damageReduction = 0.8f;
    }

    damage -= (damage * damageReduction);

    return damage;
}

float Armor::getCritRateReduction()
{
    return critRateReduction;
}
