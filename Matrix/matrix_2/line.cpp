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

	if (symbols_in_line.size() < lenght && symbol.getCoordY() < lenght - 1) {

		startRun();
		
	}
	else if (symbol.getCoordY() >= console_height - 1 && !symbols_in_line.empty()) {
		
		endRun();
	}
	else if (!symbols_in_line.empty()) {
		
		middleRun();
		
	}
	
	for (int i = 0; i < symbols_in_line.size(); i++){
		
		symbol.gotoXY(symbols_in_line[i].getCoordX(), symbols_in_line[i].getCoordY());
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
		
		symbol.color = rand() % 15+1;
	}	
	else 
	{

		symbol.color = 10;
	}
		
	symbol.setCoordY(symbol.getCoordY()+1);
	symbols_in_line.insert(symbols_in_line.begin(), symbol);
}

void Line::endRun()
{
	symbol.gotoXY(symbol.getCoordX(), symbols_in_line[symbols_in_line.size() - 1].getCoordY());
	cout << " ";
	symbols_in_line.pop_back();
}
void Line::middleRun()
{
	symbol.sign = ((char)((rand() % 63) + 33));
	if (epilepsy_flag) {

		symbol.color = rand() % 15 + 1;
	}
	else {

		symbol.color = 10;
	}
	symbol.gotoXY(symbol.getCoordX(), symbols_in_line[symbols_in_line.size() - 1].getCoordY());
	cout << " ";
	symbols_in_line.pop_back();
	symbol.setCoordY(symbol.getCoordY() + 1);
	symbols_in_line.insert(symbols_in_line.begin(), symbol);

}
void Line::trim()
{
	if (!symbols_in_line.empty()) {
		symbol.gotoXY(symbols_in_line[0].getCoordX(), symbols_in_line[0].getCoordY());
		cout << " ";
		lenght--;
		symbols_in_line.erase(symbols_in_line.begin());
		symbol.setCoordY(symbol.getCoordY() - 1);
	}
}

void Line::setFrequency(int frequency) 
{
	this->frequency = frequency;
}

void Line::setSpeed(int speed)
{
	this->speed = speed;
}

void Line::setLenght(int lenght)
{
	this->lenght = lenght;
}

void Line::setInterval(int interval)
{
	this->interval = interval;
}

void Line::setChance(int chance)
{
	this->chance = chance;
}

void Line::setEpilepsyFlag(bool flag)
{
	this->epilepsy_flag = flag;
}

int Line::getFrequency()
{
	return frequency;
}

int Line::getSpeed()
{
	return speed;
}

int Line::getLength()
{
	return lenght;
}

int Line::getInterval()
{
	return interval;
}

int Line::getChance()
{
	return chance;
}

bool Line::getEpilepsyFlag()
{
	return epilepsy_flag;
}