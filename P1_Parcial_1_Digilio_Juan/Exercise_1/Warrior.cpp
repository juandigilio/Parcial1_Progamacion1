#include "Warrior.h"

Warrior::Warrior()
{
    cout << "ggggggg";
}

Warrior::Warrior(string name, float maxHealth)
{
    this->name = name;
}

Warrior::~Warrior()
{

}

void Warrior::SetWeapon(Weapon* weapon)
{
    this->weapon = weapon;
}

void Warrior::SetArmor(Armor* armor)
{
    this->armor = armor;
}

string Warrior::GetName()
{
    return name;
}

float Warrior::RecieveDamage(float damage)
{
    return currentHealth;
}

float Warrior::Attack(Warrior warrior, AttacType attackType)
{
    float damage = weapon->GetDamage(); 


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

float Warrior::GetCurrentHealth()
{
    return currentHealth;
}

bool Warrior::IsAlive()
{
    if (currentHealth > 0.0f)
    {
        return true;
    }
    else
    {
        return false;
    }
}
