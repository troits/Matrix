#ifndef explosion_h
#define explosion_h

#include "symbol.h"
#include "figura.h"

class Explosion : public Figura {
private:

	int radius;

public:

	int current_raduis;
	Symbol symbol;

	Explosion(int radius, Symbol symbol, unsigned long time) 
	{
		this->symbol.setCoordX(symbol.getCoordX());
		this->symbol.setCoordY(symbol.getCoordY());
		this->radius = radius;
		current_raduis = 1;
	}

	Explosion() 
	{
		current_raduis = 1;
		radius = 0;
	}

	int  getType();
	void run(int console_height);
	int getRadius();
	void setRadius(int);

};

#endif