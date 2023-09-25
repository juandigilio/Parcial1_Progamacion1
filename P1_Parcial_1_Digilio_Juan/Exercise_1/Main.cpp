#include "GameLogic.h"
#include "WarriosSpawner.h"
#include "GameData.h"

using namespace ConsoleData;

void main()
{
	Warrior* player1{};
	Weapon* weapon1{};
	Armor* armor1{};

	Warrior* player2{};
	Weapon* weapon2{};
	Armor* armor2{};

	SetConsoleFont(20, 18);
	SetConsoleSize();

	WarriosSpawner p1(player1, weapon1, armor1, 0.0f);
	WarriosSpawner p2(player2, weapon2, armor2, 0.0f);

	GameLogic game(player1, player2);

}