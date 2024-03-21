#ifndef line_h
#define line_h

#include "symbol.h"

class Line {
public:
	int frequency;
	int speed;
	int lenght;
	bool epilepsy_flag;
	int interval; //shift interval
	Symbol symbol;
	unsigned long long draw_time;

	void run(int consoleHeight);
};

#endif