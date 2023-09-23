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

float Weapon::GetDamage(AttacType attackType, float critRateReduction, bool isCrit)
{
    return 0.0f;
}
