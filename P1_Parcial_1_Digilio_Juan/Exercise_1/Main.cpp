#include "GameLogic.h"
#include "WarriosSpawner.h"
#include "GameData.h"

using namespace ConsoleData;

void main()
{
	SetConsoleFont(20, 18);
	SetConsoleSize();

	WarriosSpawner p1(8.0f);
	WarriosSpawner p2(0.0f);

	GameLogic game(p1.GetWarrior(), p2.GetWarrior());

}