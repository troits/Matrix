#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>
#include <string>

#include "symbol.h"
#include "line.h"
#include "app.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;

void App::input() {

	one_line.frequency = getRightNumber("Enter frequency (1-30): ");
	one_line.speed = getRightNumber("Enter Line Speed (1-30): ");
	one_line.lenght = getRightNumber("Enter Line Length (1-30): ");
	one_line.epilepsy_flag = getRightText("Epilepsy (yes/no): ");

	system("cls");

	one_line.interval = 1000 / one_line.speed;
	console_height = getConsoleHeight();
	console_width = getConsoleWidth();
}

void App::begin() {

	for (int i = 0; i < console_height; i++) {
		free_places.push_back(i);
	}

	time_now_sec = getTimeSec();

	while (1)
	{
		spawnLines();
		createLines();
		drawDeleteLines();
	}
}

void App::spawnLines() {

	if (getTimeSec() > time_now_sec)
	{
		existing_lines = 0;
		time_now_sec = getTimeSec();
		time_now_ms = getTimeMS();
		for (int i = 0; i < one_line.frequency; i++)
			creation_lines.push_back(time_now_ms + rand() % 1000);
	}
}

void App::createLines() {

	for (int i = creation_lines.size() - 1; i >= 0; i--) {
		if (getTimeMS() >= creation_lines[i] && existing_lines < one_line.frequency && free_places.size() != 0)
		{
			delete_number = rand() % free_places.size();
			one_line.symbol.coord_y = free_places[delete_number];
			free_places.erase(free_places.begin() + delete_number);
			one_line.symbol.coord_x = -1;
			one_line.draw_time = getTimeMS() + one_line.interval;
			lines.push_back(one_line);
			existing_lines++;
			creation_lines.erase(creation_lines.begin() + i);
		}
	}
}

void App::drawDeleteLines() {

	for (int j = 0; j < lines.size(); j++)
	{
		if (getTimeMS() >= lines[j].draw_time) {
			lines[j].run(console_width);

			if (lines[j].symbol.coord_x == lines[j].lenght)
				free_places.push_back(lines[j].symbol.coord_y);

			if (lines[j].symbol.coord_x - lines[j].lenght >= console_width)
			{
				lines.erase(lines.begin());
			}
			else break;
		}
	}
}

bool App::isGoodInput(std::string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) return false;
	}

	int t = std::stoi(str);
	if (t < 1 || t > 30) return false;
	return true;
}

int App::getRightNumber(std::string request) {
	std::string str;
	int number;
	while (true) {
		std::cout << request;
		std::cin >> str;
		if (!isGoodInput(str)) {
			std::cout << "Invalid value. Please reenter" << std::endl;
			continue;
		}
		number = std::stoi(str.c_str());
		break;
	}
	return number;
}

bool App::getRightText(std::string request) {
	std::string str;
	while (true) {
		std::cout << request;
		std::cin >> str;
		if (str == "yes") return true;
		else if (str == "no") return false;
		else {
			std::cout << "Invalid value. Please reenter" << std::endl;
			continue;
		}
		break;
	}
}

int App::getConsoleWidth() {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int App::getConsoleHeight() {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Bottom - csbi.srWindow.Top;
}

unsigned long long App::getTimeSec() {

	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

unsigned long long App::getTimeMS() {

	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}