#ifndef line_h
#define line_h

#include "symbol.h"
#include "figura.h"
#include <vector>

using namespace std;

class Line : public Figura {
private:
	
	int  frequency;
	int  speed;
	int  lenght;
	int  interval;
	int  chance;
	bool epilepsy_flag;

public:
	
	unsigned long draw_time;
	Symbol symbol;
	vector<Symbol>symbols_in_line;
	
	Line() 
	{
		lenght = 0;
		interval = 0;
		chance = 0;
		epilepsy_flag = 0;
		draw_time = 0;
		frequency = 0;
		speed = 0;
	};

	Line(Line parametr_for_line, int delete_number, unsigned long time) 
	{
		symbol.setCoordX(delete_number);
		lenght = parametr_for_line.lenght;
		interval = parametr_for_line.interval;
		chance = parametr_for_line.chance;
		epilepsy_flag = parametr_for_line.epilepsy_flag;
		draw_time = time;
		frequency = 0;
		speed = 0;
	}

	int  getType();
	void run(int console_height);
	void startRun();
	void endRun();
	void middleRun();
	void trim();

	int  getFrequency();
	int  getSpeed();
	int  getLength();
	int  getInterval();
	int  getChance();
	bool getEpilepsyFlag();
	void setFrequency(int);
	void setSpeed(int);
	void setLenght(int);
	void setInterval(int);
	void setChance(int);
	void setEpilepsyFlag(bool);

};

#endif