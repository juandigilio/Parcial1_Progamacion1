#include "Warrior.h"
#include "GameData.h"

#include <conio.h>


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

void Warrior::RecieveDamage(float damage)
{
    string current = "Current healt: ";
    
    currentHealth -= damage;
   
    SetCursor((consoleWide / 2) - (current.length() / 2) - 1, (consoleHeight / 2) + 2);

    if (currentHealth < 0.0f)
    {
        currentHealth = 0;
    }
    cout << current << currentHealth;

    cin.get();
    cin.get();
}

float Warrior::Attack(Warrior warrior, AttacType attackType, bool isCritic)
{
    float damageLanded = 0.0f;

    damageLanded = weapon->GetDamage(attackType, warrior.armor->getCritRateReduction(), isCritic);

    system("cls");
    DrawFrame(0.0f);

    SetCursor((consoleWide / 2) - 4 - (name.length() / 2) - (warrior.GetName().length() / 2) - 3, (consoleHeight / 2) - 1);
    cout << name << " attacked " << warrior.GetName() << "...";

    string txt2 = "Attack point landed: ";

    SetCursor((consoleWide / 2) - (txt2.length() / 2) - 2, (consoleHeight / 2));
    cout << "Attack point landed: " << damageLanded;

    SetCursor((consoleWide / 2) - 9, (consoleHeight / 2) + 1);

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
