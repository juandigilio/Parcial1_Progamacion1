#pragma once

#include "Warrior.h"



class GameLogic
{private:

	int rounds;



public:

	GameLogic(Warrior* player1, Warrior* player2);
	~GameLogic();

	void GameLoop(Warrior* player1, Warrior* player2);

};

