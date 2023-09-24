#pragma once

#include <Windows.h>


COORD cursorPosition;
HANDLE hwnd;
CONSOLE_FONT_INFOEX fontInfo;
SMALL_RECT rect;
COORD coord;
CONSOLE_CURSOR_INFO cci;

int consoleWide;
int consoleHeight;
int color;

void SetCursor(int X, int Y)
{
    cursorPosition.X = X;
    cursorPosition.Y = Y;
    SetConsoleCursorPosition(hwnd, cursorPosition);
}