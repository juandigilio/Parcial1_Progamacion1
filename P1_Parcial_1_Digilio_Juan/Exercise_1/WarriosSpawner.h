#pragma once

#include "Warrior.h"
#include "Weapon.h"
#include "Armor.h"


class WarriosSpawner
{
private:

	Warrior* warrior;
	Weapon* weapon;
	Armor* armor;

public:

	WarriosSpawner(Warrior* warrior, Weapon* weapon, Armor* armor, float delay);
	~WarriosSpawner();
};

