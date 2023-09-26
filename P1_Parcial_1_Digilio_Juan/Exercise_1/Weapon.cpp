#include "Weapon.h"



Weapon::Weapon()
{

}

Weapon::Weapon(string name, WeaponType weaponType, float attack, float critRate, float critDamage)
{
    this->name = name;
    this->waponType = weaponType;
    this->attack = attack;
    this->critRate = critRate;
    this->critDamage = critDamage;
}

Weapon::~Weapon()
{

}

float Weapon::GetDamage(AttacType attackType, float critRateReduction, bool isCritic)
{
    float actualDamage = attack;
    float actualCrit = critRate;
    float actualCritDam = critDamage;

    switch (attackType)
    {
        case AttacType::Fast:
        {
            actualDamage += 6.0f;
            actualCrit *= 0.9;
            break;
        }
        case AttacType::Normal:
        {
            actualDamage += 12.0f;
            actualCrit *= 0.8;
            actualCritDam += 6.0f;
            break;
        }
        case AttacType::Charged:
        {
            actualDamage += 15.0f;
            actualCrit *= 0.7;
            actualCritDam += 9.0f;
            break;
        }
    }

    actualCrit *= critRateReduction;

    float randCrit = (rand() % 100) + 1;

    if (actualCrit >= randCrit)
    {
        isCritic = true;
        actualDamage += actualCritDam;
    }

    return actualDamage;
}

