#ifndef symbol_h
#define symbol_h

#include <vector>

class Symbol {
private:
	
	int  coord_x;
	int  coord_y;
	
public:

	int  color;
	char sign;

	Symbol() 
	{
		coord_x = 0;
		coord_y = -1;
		color = 0;
		sign = '0';
	}

	void setColor(int, int);
	void gotoXY(int, int);
	void setCoordX(int);
	void setCoordY(int);
	int  getCoordX();
	int  getCoordY();

};

#endif