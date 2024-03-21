#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <string>

#include "app.h"

using namespace std;

CONSOLE_SCREEN_BUFFER_INFO csbi;

void App::input() {

	parametr_for_line.frequency = getRightNumber("Введите частоту (1-30): ", "line");
	parametr_for_line.speed = getRightNumber("Введите скорость (1-30): ", "line");
	parametr_for_line.lenght = getRightNumber("Введите длину (1-30): ", "line");
	parametr_for_line.epilepsy_flag = getRightText("Эпилепсия (yes/no): ");

	system("cls");

	input_chance = getRightNumber("Введите шанс взрыва (1-1000): ", "chance");
	input_radius();

	system("cls");

	parametr_for_line.interval = 1000 / parametr_for_line.speed;
	console_height = getConsoleHeight();
	console_width = getConsoleWidth();

}

void App::input_radius() {

	input_min_radius = getRightNumber("Введите минимальный радиус взрыва (1-10): ", "radius");

	text_input_max_radius = "Введите максимальный радиус взрыва (";
	text_input_max_radius += to_string(input_min_radius);
	text_input_max_radius += "-10): ";

	while (true) {
		
		input_max_radius = getRightNumber(text_input_max_radius, "radius");

		if (input_min_radius > input_max_radius) {
			
			cout << "!!! Минимальный радиус должен быть меньше максимального, повторите ввод \n\n";
			continue;
		}
		break;
	}

}

void App::begin() {

	for (int i = 0; i < console_width; i++) {
		
		free_places.push_back(i);
	}

	time_now_sec = timeNowSec();

	while (1)
	{
		spawnLines();
		createLines();
		drawDeleteLines();
	}
}

void App::spawnLines() {

	if (timeNowSec() > time_now_sec){

		time_now_sec = timeNowSec();
		time_now_ms = timeNowMS();
		for (int i = 0; i < parametr_for_line.frequency; i++) {
			
			creation_lines.push_back(time_now_ms + rand() % 1000);
		}
	}
}

void App::createLines() {

	for (int j = 0; j < creation_lines.size(); j++) {

		if (timeNowMS() >= creation_lines[j] && free_places.size() != 0){

			one_line = new Line();
			delete_number = rand() % free_places.size();
			one_line->symbol.coord_x = free_places[delete_number];
			free_places.erase(free_places.begin() + delete_number);
			one_line->symbol.coord_y = -1;
			one_line->interval = parametr_for_line.interval;
			one_line->draw_time = timeNowMS() + one_line->interval; 
			one_line->lenght = parametr_for_line.lenght;
			one_line->epilepsy_flag = parametr_for_line.epilepsy_flag;
			one_line->chance = input_chance;
			lines_and_explosions.push_back(one_line);
			creation_lines.erase(j);
		}
	}
}

void App::drawDeleteLines() {

	for (int k = 0; k < lines_and_explosions.size(); k++)
	{
		if (timeNowMS() >= lines_and_explosions[k]->time)
		{

			lines_and_explosions[k]->run(console_height);

			if (!lines_and_explosions[k]->getType())
			{
				if (rand() % 1000 <= ((Line*)lines_and_explosions[k])->chance && !((Line*)lines_and_explosions[k])->symbols_in_line.empty())
				{
					explosion = new Explosion();
					explosion->radius = input_min_radius + rand() % (input_max_radius - input_min_radius + 1);
					explosion->symbol.coord_x = ((Line*)lines_and_explosions[k])->symbol.coord_x;
					explosion->symbol.coord_y = ((Line*)lines_and_explosions[k])->symbol.coord_y;
					explosion->time = timeNowMS() + 500;
					lines_and_explosions.push_back(explosion);
					((Line*)lines_and_explosions[k])->trim();
				}
				if (((Line*)lines_and_explosions[k])->symbol.coord_y == ((Line*)lines_and_explosions[k])->lenght)
					free_places.push_back(((Line*)lines_and_explosions[k])->symbol.coord_x);

				if (((Line*)lines_and_explosions[k])->symbol.coord_y - ((Line*)lines_and_explosions[k])->lenght >= console_height - 1)
					lines_and_explosions.erase(lines_and_explosions.begin() + k);
			}
			else
			{
				if ((((Explosion*)lines_and_explosions[k])->current_raduis) > ((Explosion*)lines_and_explosions[k])->radius + 1)
					lines_and_explosions.erase(lines_and_explosions.begin() + k);
			}
		}
	}
}

int App::getConsoleWidth() {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int App::getConsoleHeight() {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

bool App::isGoodInput(string str, string type) {
	for (int i = 0; i < str.length(); i++){

		if (!isdigit(str[i])) return false;
	}

	int t = stoi(str);
	if (type == "line") {
		if (t < 1 || t > 30) return false;
	}

	if (type == "radius") {
		if (t < 1 || t > 10) return false;
	}

	if (type == "chance") {
		if (t < 1 || t > 1000) return false;
	}

	return true;
}

int App::getRightNumber(string request, string type) {
	string str;
	int number;
	while (true) {
		cout << request;
		cin >> str;
		cout << '\n';
		if (!isGoodInput(str, type)) {
			std::cout << "!!! Неверное значение, повторите ввод \n" << endl;
			continue;
			}
		number = stoi(str.c_str());
		break;
	}
	return number;
}

bool App::getRightText(string request) {
	string str;
	while (true) {
		cout << request;
		cin >> str;
		cout << '\n';
		if (str == "yes") return true;
		else if (str == "no") return false;
		else {
			cout << "!!! Неверное значение, повторите ввод \n" << endl;
			continue;
		}
		break;
	}
}

unsigned long App::timeNowSec() {
	return chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
}

unsigned long App::timeNowMS() {
	return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}