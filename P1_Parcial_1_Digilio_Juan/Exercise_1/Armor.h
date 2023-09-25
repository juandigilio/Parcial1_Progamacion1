#pragma once

#include <iostream>

using namespace std;


enum class ArmorType
{
	Light,
	Medium,
	Heavy
};

class Armor
{
private:

	string name;
	ArmorType armorType;
	float defense;
	float weight;
	float critRateReduction;

public:

	Armor();
	Armor(string name, ArmorType armorType, float defense, float weight, float criticalRateReduction);
	~Armor();

	float GetDmgReductionPerc(float damage);
	float getCritRateReduction();
	string GetName();
	float GetDefense();
};

