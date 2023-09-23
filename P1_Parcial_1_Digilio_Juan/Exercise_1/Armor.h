#pragma once

#include <iostream>

using namespace std;


enum class ArmorType
{

};

class Armor
{
private:

	string name;
	ArmorType armorType;
	float defense;
	float weight;

public:

	Armor();
	Armor(string name, ArmorType armorType, float defense, float weight);
	~Armor();

	float GetDmgReductionPerc(float damage);
	float getCritRateReduction();
};

