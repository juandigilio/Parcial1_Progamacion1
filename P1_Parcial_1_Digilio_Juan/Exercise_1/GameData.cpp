#include "GameData.h"

#include <iostream>

using namespace std;


namespace ConsoleData
{
	extern COORD cursorPosition{};
	extern HANDLE hwnd{};
	extern CONSOLE_FONT_INFOEX fontInfo{};
	extern SMALL_RECT rect{};
	extern COORD coord{};
	extern CONSOLE_CURSOR_INFO cci{};
	 
	extern int consoleWide = 50;
	extern int consoleHeight = 35;
	extern int color = 112;


	void SetCursor(int X, int Y)
	{
		cursorPosition.X = X;
		cursorPosition.Y = Y;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	void DrawFrame(float delay)
	{
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		
		cout << (char)201;

		for (int i = 0; i < (consoleWide - 2); i++)
		{
			cout << (char)205;

			Sleep(delay);
		}

		cout << (char)187;

		cursorPosition.X = consoleWide - 1;
		cursorPosition.Y = 1;

		for (int i = 0; i < (consoleHeight - 2); i++)
		{
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << (char)186;
			cursorPosition.Y++;

			if (delay > 0)
			{
				Sleep(delay + 20);
			}
		}

		SetConsoleCursorPosition(hwnd, cursorPosition);

		cout << (char)188;

		cursorPosition.X--;
		SetConsoleCursorPosition(hwnd, cursorPosition);

		for (int i = 0; i < (consoleWide - 2); i++)
		{
			cout << (char)205;
			cursorPosition.X--;
			SetConsoleCursorPosition(hwnd, cursorPosition);
			Sleep(delay);
		}

		SetConsoleCursorPosition(hwnd, cursorPosition);

		cout << (char)200;

		cursorPosition.Y--;
		SetConsoleCursorPosition(hwnd, cursorPosition);

		for (int i = 0; i < (consoleHeight - 2); i++)
		{
			cout << (char)186 << endl;
			cursorPosition.Y--;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			if (delay > 0)
			{
				Sleep(delay + 20);
			}
		}

		string digitalHappiness = "DigitalHappiness";

		cursorPosition.X = (consoleWide / 2) - (digitalHappiness.length() / 2);
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(hwnd, cursorPosition);

		for (int i = 0; i < digitalHappiness.length(); i++)
		{
			cout << digitalHappiness[i];
			if (delay > 0)
			{
				Sleep(100);
			}
		}

		cout << (char)169;
	}

	void SetConsoleSize()
	{
		coord.X = consoleWide;
		coord.Y = consoleHeight;

		rect.Top = 0;
		rect.Left = 0;
		rect.Bottom = coord.Y - 1;
		rect.Right = coord.X - 1;

		hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferSize(hwnd, coord);
		SetConsoleWindowInfo(hwnd, TRUE, &rect);


		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		cci.bVisible = 0;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	}

	void SetConsoleFont(int wide, int height)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;

		cfi.dwFontSize.X = 18;
		cfi.dwFontSize.Y = 20;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;

		wcscpy_s(cfi.FaceName, L"Lucida Console");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}
}


