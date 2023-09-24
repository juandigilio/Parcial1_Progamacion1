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
    switch (attackType)
    {
        case AttacType::Fast:
        {
            attack += 10.0f;
            critRate *= 0.9;
            break;
        }
        case AttacType::Normal:
        {
            attack += 16.0f;
            critRate *= 0.8;
            critDamage += 8.0f;
            break;
        }
        case AttacType::Charged:
        {
            attack += 22.0f;
            critRate *= 0.7;
            critDamage += 16.0f;
            break;
        }
    }

    critRate *= critRateReduction * 10.0f;

    float randCrit = (rand() % 10) + 1;

    if (critRate >= randCrit)
    {
        isCritic = true;
        attack += critDamage;
    }

    return attack;
}

