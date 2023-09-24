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

float Weapon::GetDamage(AttacType attackType, float critRateReduction, bool isCrit)
{
    switch (attackType)
    {
    case AttacType::Fast:
    {


        break;
    }
    case AttacType::Normal:
    {


        break;
    }
    case AttacType::Charged:
    {


        break;
    }
    }
    return 0.0f;
}
