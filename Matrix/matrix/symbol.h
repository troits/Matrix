#ifndef symbol_h
#define symbol_h

class Symbol {
public:
	int color;
	char znach;
	int coord_x;
	int coord_y;
	
	void setColor(int text, int background);
	void gotoXY(int x, int y);
};

#endif