#include "WarriosSpawner.h"

#include <conio.h>

#include "GameData.h"

using namespace ConsoleData;

WarriosSpawner::WarriosSpawner(float delay)
{
	float maxHealth = 100.0f;

    string nameTXT = "Enter warrior name:";
    string weaponTXT = "Enter weapon class...";
    string spear = "1-Spear";
    string sword = "2-Sword";
    string doubleHanded = "3-Double Handed";
    int y = (consoleHeight / 2) - 1;

	string nameInput;
	char input;

    DrawFrame(delay);
    
    SetCursor((consoleWide / 2) - (nameTXT.length() / 2), y);
	cout << nameTXT;

    SetCursor((consoleWide / 2 - 4), y + 1);
	cin >> nameInput;

	warrior = new Warrior(nameInput, maxHealth);

    system("cls");

    DrawFrame(0);
    
    SetCursor((consoleWide / 2) - (weaponTXT.length() / 2), y);
    cout << weaponTXT;

    SetCursor((consoleWide / 2) - (spear.length() / 2), y + 1);
    cout << spear;

    SetCursor((consoleWide / 2) - (sword.length() / 2), y + 2);
    cout << sword;

    SetCursor((consoleWide / 2) - (doubleHanded.length() / 2), y + 3);
    cout << doubleHanded;

	do 
	{
        SetCursor((consoleWide / 2), y + 4);
        input = _getch();

	} while (input != '1' && input != '2' && input != '3');


    switch (input)
    {
        case '1':
        {
            weapon = new Weapon("Spear", WeaponType::Spear, 15.0f, 100.0f, 20.0f);
            warrior->SetWeapon(weapon);

            break;
        }
        case '2':
        {
            weapon = new Weapon("Sword", WeaponType::Spear, 25.0f, 80.0f, 25.0f);
            warrior->SetWeapon(weapon);

            break;
        }
        case '3':
        {
            weapon = new Weapon("Heavy axe", WeaponType::Spear, 32.0f, 60.0f, 58.0f);
            warrior->SetWeapon(weapon);
      
            break;
        }
    }


    string armorTXT = "Enter armor class...";
    string light = "1-light";
    string medium = "2-Medium";
    string heavy = "3-Heavy";


    system("cls");
    DrawFrame(0);

    SetCursor((consoleWide / 2) - (armorTXT.length() / 2), y);
    cout << armorTXT;

    SetCursor((consoleWide / 2) - (light.length() / 2), y + 1);
    cout << light;

    SetCursor((consoleWide / 2) - (medium.length() / 2), y + 2);
    cout << medium;

    SetCursor((consoleWide / 2) - (heavy.length() / 2), y + 3);
    cout << heavy;


    do
    {
        SetCursor(consoleWide / 2, y + 4);
        input = _getch();

    } while (input != '1' && input != '2' && input != '3');


    switch (input)
    {
        case '1':
        {
            armor = new Armor("Light", ArmorType::Light, 15.0f, 10.0f, 0.4f);
            warrior->SetArmor(armor);

            break;
        }
        case '2':
        {
            armor = new Armor("Medium", ArmorType::Medium, 25.0f, 20.0f, 0.6f);
            warrior->SetArmor(armor);

            break;
        }
        case '3':
        {
            armor = new Armor("Heavy", ArmorType::Heavy, 35.0f, 30.0f, 0.8f);
            warrior->SetArmor(armor);

            break;
        }
    }

    system("cls");
    DrawFrame(0);

    /*this->warrior = warrior;
    this->weapon = weapon;
    this->armor = armor;*/
}

WarriosSpawner::~WarriosSpawner()
{
    cout << "deleeeeeeteeeeeee";
    delete warrior;
    delete weapon;
    delete armor;
}

Warrior WarriosSpawner::GetWarrior()
{
    return *warrior;
}