#ifndef symbol_h
#define symbol_h

#include <vector>

class Symbol {
public:

	int  coord_x = 0;
	int  coord_y = 0;
	int  color = 0;
	char sign;

	void setColor(int text, int background);
	void gotoXY(int x, int y);

};

#endif