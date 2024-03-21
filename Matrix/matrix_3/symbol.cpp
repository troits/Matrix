#include <iostream>
#include <Windows.h>

#include "symbol.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

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