#ifndef explosion_h
#define explosion_h

#include "symbol.h"
#include "figura.h"

class Explosion : public Figura {
public:

	int radius = 0;
	int current_raduis = 1;
	Symbol symbol;

	int  getType();
	void run(int console_with);

};

#endif