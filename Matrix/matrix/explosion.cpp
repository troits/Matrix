#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>

#include "symbol.h"
#include "figura.h"
#include "explosion.h"

int Explosion :: getType()
{
	return 1;
}
void Explosion :: run() override
{
	for (int i = 0, j = change - 1; i <= change - 1; i++, j--)
	{
		GotoXY(symbol.coordX + j, symbol.coordY + i);
		SetColor(0, 0);
		cout << " ";

		GotoXY(symbol.coordX - j, symbol.coordY + i);
		SetColor(0, 0);
		cout << " ";
	}

	for (int i = 1, j = change - 2; i <= change; i++, j--)
	{
		GotoXY(symbol.coordX + j, symbol.coordY - i);
		SetColor(0, 0);
		cout << " ";

		GotoXY(symbol.coordX - j, symbol.coordY - i);
		SetColor(0, 0);
		cout << " ";
	}

	if (change <= radius) {
		for (int i = 0, j = change; i <= change; i++, j--)
		{

			GotoXY(symbol.coordX + j, symbol.coordY + i);
			SetColor(rand() % 15, 0);
			cout << (char)((rand() % 63) + 33);

			GotoXY(symbol.coordX - j, symbol.coordY + i);
			SetColor(rand() % 15, 0);
			cout << (char)((rand() % 63) + 33);
		}

		for (int i = 1, j = change - 1; i <= change; i++, j--)
		{
			if (symbol.coordY - i >= 0) {
				GotoXY(symbol.coordX + j, symbol.coordY - i);
				SetColor(rand() % 15, 0);
				cout << (char)((rand() % 63) + 33);

				GotoXY(symbol.coordX - j, symbol.coordY - i);
				SetColor(rand() % 15, 0);
				cout << (char)((rand() % 63) + 33);
			}
		}

	}
	change++;
	time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + 500;
}

};
