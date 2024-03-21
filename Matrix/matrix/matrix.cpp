#include <iostream>
#include <chrono>
#include "app.h"

int main()
{	
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	App app;
	app.input();
	app.begin();

	return 0;
}