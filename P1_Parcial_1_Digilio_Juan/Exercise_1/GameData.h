#pragma once

#include <Windows.h>


namespace ConsoleData
{
	extern COORD cursorPosition;
	extern HANDLE hwnd;
	extern CONSOLE_FONT_INFOEX fontInfo;
	extern SMALL_RECT rect;
	extern COORD coord;
	extern CONSOLE_CURSOR_INFO cci;
	 
	extern int consoleWide;
	extern int consoleHeight;
	extern int color;

	void SetCursor(int X, int Y);
	void DrawFrame(float delay);
	void SetConsoleSize();
	void SetConsoleFont(int wide, int height);
}

