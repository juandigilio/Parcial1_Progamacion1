#pragma once

#include <iostream>

using namespace std;

enum class WeaponType
{
	Spear,
	Sword,
	DoubleHanded
};

enum class AttacType
{
	Fast,
	Normal,
	Charged,
};

class Weapon
{
private:

	string name;
	WeaponType waponType;
	float attack;
	float critRate;
	float critDamage;


public:

	Weapon();
	Weapon(string name, WeaponType weaponType, float attack, float critRate, float critDamage);
	~Weapon();

	float GetDamage(AttacType attackType, float critRateReduction, bool isCritic);
	//float GetCriticalRate();
};

