#include <iostream>
#include <Windows.h>

#include "symbol.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void Symbol::setCoordX(int x) 
{
	coord_x = x;
}

void Symbol::setCoordY(int y)
{
	coord_y = y;
}

int Symbol::getCoordX()
{
	return coord_x;
}

int Symbol::getCoordY()
{
	return coord_y;
}

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