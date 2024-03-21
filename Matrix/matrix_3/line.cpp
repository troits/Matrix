#include <iostream>
#include <Windows.h>
#include <chrono>

#include "figura.h"
#include "symbol.h"
#include "line.h"

using namespace std;

int Line::getType()
{
	return 0;
}

void Line::run(int console_height)
{

	if (symbols_in_line.size() < lenght && symbol.coord_y < lenght - 1) {

		startRun();
	}
	else if (symbol.coord_y >= console_height - 1 && !symbols_in_line.empty()) {
		endRun();
	}
	else if (!symbols_in_line.empty()) {
		middleRun();
	}
		
	for (int i = 0; i < symbols_in_line.size(); i++){
		
		symbol.gotoXY(symbols_in_line[i].coord_x, symbols_in_line[i].coord_y);
		symbol.setColor(symbols_in_line[i].color, 0);
		cout << symbols_in_line[i].sign;

	}

	time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() + interval;
}

void Line::startRun()
{
	symbol.sign = ((char)((rand() % 63) + 33));
	
	if (epilepsy_flag) 
	{
		
		symbol.color = rand() % 15;
	}	
	else 
	{

		symbol.color = 10;
	}
		
	symbol.coord_y++;
	symbols_in_line.insert(symbols_in_line.begin(), symbol);
}

void Line::endRun()
{
	symbol.gotoXY(symbol.coord_x, symbols_in_line[symbols_in_line.size() - 1].coord_y);
	cout << " ";
	symbols_in_line.pop_back();
}
void Line::middleRun()
{
	symbol.sign = ((char)((rand() % 63) + 33));
	if (epilepsy_flag) {

		symbol.color = rand() % 15;
	}
	else {

		symbol.color = 10;
	}
	symbol.gotoXY(symbol.coord_x, symbols_in_line[symbols_in_line.size() - 1].coord_y);
	cout << " ";
	symbols_in_line.pop_back();
	symbol.coord_y++;
	symbols_in_line.insert(symbols_in_line.begin(), symbol);
}
void Line::trim()
{
	if (!symbols_in_line.empty()) {
		symbol.gotoXY(symbols_in_line[0].coord_x, symbols_in_line[0].coord_y);
		cout << " ";
		lenght--;
		symbols_in_line.erase(symbols_in_line.begin());
		symbol.coord_y--;
	}
}