#include "Warrior.h"
#include "GameData.h"


using namespace ConsoleData;

Warrior::Warrior()
{
    
}

Warrior::Warrior(string name, float maxHealth)
{
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
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
    currentHealth -= damage;
    return currentHealth;
}

float Warrior::Attack(Warrior warrior, AttacType attackType, bool isCritic)
{
    float damageLanded{};

    damageLanded = weapon->GetDamage(attackType, warrior.armor->getCritRateReduction(), isCritic);

    system("cls");
    DrawFrame(0.0f);

    SetCursor((consoleWide / 2) - 4 - (name.length() / 2) - (warrior.GetName().length() / 2) - 3, consoleHeight / 4);
    cout << name << " attacked " << warrior.GetName() << "...";

    string txt2 = "Attack point landed: ";

    SetCursor((consoleWide / 2) - (txt2.length() / 2) - 2, (consoleHeight / 4) + 1);
    cout << "Attack point landed: " << damageLanded;

    SetCursor((consoleWide / 2) - 9, (consoleHeight / 4) + 2);

    if (isCritic)
    {
        cout << "Attack was critic!";
    }
    else
    {
        cout << "Attack wasn't critic!";
    }

    return damageLanded;
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
