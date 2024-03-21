#include <iostream>
#include <Windows.h>

#include "symbol.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3,
	Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10,
	LightCyan = 11, LightRed = 12, LightMagenta = 13,
	Yellow = 14, White = 15
};

void Symbol::setColor(int text, int background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Symbol::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdOut, coord);
}

