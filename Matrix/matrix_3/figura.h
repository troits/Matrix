#ifndef figura_h
#define figura_h

class Figura {
public:

	unsigned long time = 0;

	virtual int  getType() = 0;
	virtual void run(int console_height) = 0;

};

#endif