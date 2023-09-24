#pragma once

#include "WarriosSpawner.h"



class GameLogic
{private:

	int rounds;



public:

	GameLogic(WarriosSpawner* player1, WarriosSpawner* player2);
	~GameLogic();

	void SetConsoleSize();
	void SetConsoleFont(int wide, int height);
	void DrawFrame();

};

