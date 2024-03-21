#include <iostream>
#include <chrono>

#include "symbol.h"
#include "line.h"

void Line::run(int consoleHeight)
{
	if (epilepsy_flag)
		symbol.setColor(rand() % 15 + 1, 0);
	else
		symbol.setColor(10, 0);

	if (symbol.coord_y < consoleHeight - 1) {
		symbol.gotoXY(symbol.coord_x, symbol.coord_y + 1);
		std::cout << (char)((rand() % 63) + 33);
	}

	if (symbol.coord_y + 1 - lenght >= 0 and symbol.coord_y - lenght + 1 <= consoleHeight - 1)
	{
		symbol.gotoXY(symbol.coord_x, symbol.coord_y + 1 - lenght);
		std::cout << " ";
	}
	symbol.coord_y++;

	draw_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + interval; //интервал смещения
}