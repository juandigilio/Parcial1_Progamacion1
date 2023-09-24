#pragma once

#include <iostream>
#include "Weapon.h"
#include "Armor.h"


using namespace std;


class Warrior
{
private:

	string name;
	Weapon* weapon;
	Armor* armor;
	float maxHealth;
	float currentHealth;

public: 

	Warrior();
	Warrior(string name, float maxHealth);
	~Warrior();

	void SetWeapon(Weapon* weapon);
	void SetArmor(Armor* armor);
	string GetName();
	float RecieveDamage(float damage);
	float Attack(Warrior warrior, AttacType attackType);
	float GetCurrentHealth();
	bool IsAlive();
};

