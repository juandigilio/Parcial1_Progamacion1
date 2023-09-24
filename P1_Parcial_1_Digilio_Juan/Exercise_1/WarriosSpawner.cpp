#include "WarriosSpawner.h"

WarriosSpawner::WarriosSpawner()
{
	float maxHealth = 100.0f;

	string name;
	int input;

	cout << "Enter warrior name: ";
	cin >> name;

	warrior = new Warrior(name, maxHealth);

	do 
	{
		cout << endl << "Enter weapon class..." << endl << "1-Spear" << endl << "2-Sword" << endl << "3-Double Handed";
		cin >> input;

	} while (input < 1 || input > 3);


    switch (input)
    {
        case 1:
        {
            weapon = new Weapon("Spear", WeaponType::Spear, 15.0f, 0.40f, 28.0f);
            warrior->SetWeapon(weapon);

            break;
        }
        case 2:
        {
            weapon = new Weapon("Sword", WeaponType::Spear, 25.0f, 0.30f, 40.0f);
            warrior->SetWeapon(weapon);

            break;
        }
        case 3:
        {
            weapon = new Weapon("Heavy axe", WeaponType::Spear, 32.0f, 0.15f, 50.0f);
            warrior->SetWeapon(weapon);
      
            break;
        }
    }

    do
    {
        cout << endl << "Enter armor class..." << endl << "1-light" << endl << "2-Medium" << endl << "3-Heavy";
        cin >> input;

    } while (input < 1 || input > 3);


    switch (input)
    {
        case 1:
        {
            armor = new Armor("Light", ArmorType::Light, 15.0f, 10.0f, 0.4f);
            warrior->SetArmor(armor);

            break;
        }
        case 2:
        {
            armor = new Armor("Medium", ArmorType::Medium, 25.0f, 20.0f, 0.6f);
            warrior->SetArmor(armor);

            break;
        }
        case 3:
        {
            armor = new Armor("Heavy", ArmorType::Heavy, 35.0f, 30.0f, 0.8f);
            warrior->SetArmor(armor);

            break;
        }
    }

}

WarriosSpawner::~WarriosSpawner()
{
    delete warrior;
    delete weapon;
    delete armor;
}
