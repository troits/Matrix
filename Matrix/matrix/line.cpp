#include <iostream>
#include <chrono>

#include "symbol.h"
#include "line.h"

void Line::run(int consoleWidth)
{
	if (epilepsy_flag)
		symbol.setColor(rand() % 15 + 1, 0);
	else
		symbol.setColor(10, 0);

	if (symbol.coord_x < consoleWidth - 1) {
		symbol.gotoXY(symbol.coord_x + 1, symbol.coord_y);
		std::cout << (char)((rand() % 63) + 33);
	}

	if (symbol.coord_x + 1 - lenght >= 0 and symbol.coord_x + 1 - lenght  <= consoleWidth - 1)
	{
		symbol.gotoXY(symbol.coord_x + 1 - lenght, symbol.coord_y);
		std::cout << " ";
	}
	symbol.coord_x++;

	draw_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + interval;
}