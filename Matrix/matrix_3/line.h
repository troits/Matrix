#ifndef line_h
#define line_h

#include "linkedList.h"
#include "symbol.h"
#include "figura.h"
#include <vector>

using namespace std;

class Line : public Figura {
public:
	int  frequency = 0;
	int  speed = 0;
	int  lenght = 0;
	int  interval = 0;
	int  chance = 0;
	bool epilepsy_flag = false;
	unsigned long draw_time = 0;
	Symbol symbol;
	LinkedList<Symbol>symbols_in_line;
	
	int  getType();
	void run(int console_height);
	void startRun();
	void endRun();
	void middleRun();
	void trim();

};

#endif