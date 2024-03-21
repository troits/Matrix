#ifndef figura_h
#define figura_h

class Figura
{
public:

	unsigned long long time;
	
	virtual int getType() = 0;
	virtual void run() = 0;
};

#endif