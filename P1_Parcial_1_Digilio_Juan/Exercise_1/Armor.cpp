#include "Armor.h"

Armor::Armor()
{

}

Armor::Armor(string name, ArmorType armorType, float defense, float weight)
{
    this->name = name;
    this->armorType = armorType;
    this->defense = defense;
    this->weight = weight;
}

Armor::~Armor()
{
}

float Armor::GetDmgReductionPerc(float damage)
{
    return 0.0f;
}

float Armor::getCritRateReduction()
{
    return 0.0f;
}
