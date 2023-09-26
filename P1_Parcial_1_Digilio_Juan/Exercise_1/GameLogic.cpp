#include "GameLogic.h"
#include "GameData.h"

#include <conio.h>

using namespace ConsoleData;


GameLogic::GameLogic(Warrior player1, Warrior player2)
{
	bool isCritic{};
	rounds = 0;
	
	while (player1.IsAlive() && player2.IsAlive())
	{
		rounds++;

		GetInput(player1, player2, isCritic);

		if (player2.IsAlive())
		{
			GetInput(player2, player1, isCritic);
		}
	}

	system("cls");
	DrawFrame(0.0f);

	string out = " is the winner!";
	string total = "Rounds count: ";

	SetCursor((consoleWide / 2) - (out.length() / 2) - 4, consoleHeight / 2);

	if (player1.IsAlive())
	{
		cout << player1.GetName() << out << endl << endl;
	}
	else
	{
		cout << player2.GetName() << out << endl << endl;
	}
	
	SetCursor((consoleWide / 2) - (total.length() / 2), (consoleHeight / 2) + 1);
	cout << total << rounds;

	cin.get();
	cin.get();
}

GameLogic::~GameLogic()
{

}

void GameLogic::GetInput(Warrior& player1, Warrior& player2, bool isCritic)
{
	char key{};
	string output = "Select attack type:";
	string output2 = "1-Charged";
	string output3 = "2-Normal";
	string output4 = "3-Fast";
	
	system("cls");
	DrawFrame(0.0f);

	SetCursor((consoleWide / 2) - (output.length() / 2), consoleHeight / 2);
	cout << output;
	SetCursor((consoleWide / 2) - (output.length() / 2), (consoleHeight / 2) + 1);
	cout << output2;
	SetCursor((consoleWide / 2) - (output.length() / 2), (consoleHeight / 2) + 2);
	cout << output3;
	SetCursor((consoleWide / 2) - (output.length() / 2), (consoleHeight / 2) + 3);
	cout << output4;
	

	do
	{
		key = _getch();

	} while (key != '1' && key != '2' && key != '3');

	switch (key)
	{
		case '1':
		{
			player2.RecieveDamage(player1.Attack(player2, AttacType::Charged, isCritic));
			break;
		}
		case '2':
		{
			player2.RecieveDamage(player1.Attack(player2, AttacType::Normal, isCritic));
			break;
		}
		case '3':
		{
			player2.RecieveDamage(player1.Attack(player2, AttacType::Fast, isCritic));
			break;
		}
	}
}

