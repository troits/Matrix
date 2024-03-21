#ifndef explosion_h
#define explosion_h

#include "symbol.h"
#include "figura.h"

class Explosion :public Figura
{
public:

	Symbol symbol;
	
	int radius;
	int change = 1;
	
	int getType();
	void run() override;

};

#endif