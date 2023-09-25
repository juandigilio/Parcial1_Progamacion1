#include "GameLogic.h"
#include "GameData.h"

using namespace ConsoleData;


GameLogic::GameLogic(Warrior* player1, Warrior* player2)
{
	srand(NULL);

	GameLoop(player1, player2);
}

GameLogic::~GameLogic()
{

}

void GameLogic::GameLoop(Warrior* player1, Warrior* player2)
{
	bool isCritic{};

	while (player1->IsAlive() && player2->IsAlive())
	{
		system("cls");
		DrawFrame(8.0f);

		

		player2->RecieveDamage(player1->Attack(player2, AttacType::Charged, isCritic));

		if (player2->IsAlive())
		{
			system("cls");
			DrawFrame(0.0f);

			player1->RecieveDamage(player2->Attack(player1, AttacType::Charged, isCritic));
		}
	}
	
}