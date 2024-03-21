#ifndef list_h
#define list_h

using namespace std;
template<typename T>
class List
{
	virtual void push_back(T data) = 0;
	virtual void insert(int index, T data) = 0;
	virtual void erase(int index) = 0;
	virtual int size() = 0;
	virtual bool empty() = 0;

};

#endif