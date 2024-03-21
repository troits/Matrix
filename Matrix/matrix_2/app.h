#ifndef app_h
#define app_h

#include "figura.h"
#include "explosion.h"
#include "line.h"
#include <vector>

using namespace std;

class App {

	int console_width = 0;
	int console_height = 0;

public:
	
	int input_min_radius = 0;
	int input_max_radius = 0;
	int delete_number = 0;
	unsigned long time_now_sec = 0;
	unsigned long time_now_ms = 0;
	
	Line parametr_for_line;
	Line* one_line;
	Explosion* explosion;
	string text_input_max_radius;
	vector<short>free_places;
	vector<unsigned long>creation_lines;
	vector<Figura*>lines_and_explosions;

	int  getConsoleWidth();
	int  getConsoleHeight();
	void begin();
	void spawnLines();
	void createLines();
	void drawDeleteLines();
	void input();
	void input_radius();
	int  getRightNumber(string request, string type);
	bool getRightText(string request);
	bool isGoodInput(string str, string type);
	unsigned long timeNowMS();
	unsigned long timeNowSec();

};

#endif