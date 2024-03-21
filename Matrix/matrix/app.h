#ifndef app_h
#define app_h

#include "symbol.h"
#include "line.h"
#include <vector>

class App {
public:
	int console_height;
	int console_width;
	std::vector<short>free_places;
	std::vector<unsigned long long>creation_lines; 
	std::vector<Line>lines;
	Line one_line;
	int delete_number;
	unsigned long long time_now_sec;
	int existing_lines = 0;
	unsigned long long time_now_ms;

	void begin();
	void spawnLines();
	void createLines();
	void drawDeleteLines();
	void input();
	int  getRightNumber(std::string request);
	bool getRightText(std::string request);
	bool isGoodInput(std::string str);
	int  getConsoleWidth();
	int  getConsoleHeight();
	unsigned long long getTimeSec();
	unsigned long long getTimeMS();

};

#endif