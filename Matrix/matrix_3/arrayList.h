#ifndef arraylist_h
#define arraylist_h

#include "list.h"

template<typename T>
class ArrayList :List<T>
{
private:
	int count;
	int length;
	T* array;
public:
	ArrayList();
	ArrayList(int);
	ArrayList(const ArrayList<T>&);
	~ArrayList();
	
	void push_back(T) override;
	void insert(int, T) override;
	void erase(int) override;
	int size() override;
	bool empty() override;
	
	T& operator[](int);
	ArrayList& operator=(const ArrayList& arrayList);
};


template<typename T>
ArrayList<T>::ArrayList()
{
	count = 0;
	length = 2;
	array = new T[length];
}

template<typename T>
ArrayList<T>::ArrayList(int length)
{
	count = 0;
	this->length = length;
	array = new T[length];
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& array_list)
{
	length = array_list.length;
	count = array_list.count;
	array = new T[length];
	for (int i = 0; i < count; i++)
	{
		array[i] = array_list.array[i];
	}
}

template<typename T>
ArrayList<T>::~ArrayList()
{
	delete[] array;
}

template<typename T>
void ArrayList<T>::push_back(T data)
{
	if (count == length)
	{
		length *= 1.5;
		T* temp_array = new T[length];
		for (int i = 0; i < count; i++)
		{
			temp_array[i] = array[i];
		}
		delete[] array;
		array = temp_array;
	}

	array[count] = data;
	count++;
}

template<typename T>
void ArrayList<T>::insert(int index, T data)
{
	T* temp_array;
	if (count == length)
	{
		length *= 1.5;
		temp_array = new T[length];
	}
	else
	{
		temp_array = new T[length];
	}
		
	for (int i = 0; i < index; i++)
	{
		temp_array[i] = array[i];
	}

	temp_array[index] = data;

	for (int i = index + 1; i < count + 1; i++)
	{
		temp_array[i] = array[i - 1];
	}

	delete[] array;
	array = temp_array;
	count++;
}

template<typename T>
void ArrayList<T>::erase(int index)
{
	
	for (int i = index; i < count - 1; i++)
	{
		array[i] = array[i + 1];
	}

	count--;

	T* temp_array = new T[length];

	for (int i = 0; i < count; i++)
	{
		temp_array[i] = array[i];
	}

	delete[] array;
	array = temp_array;
}

template<typename T>
int ArrayList<T>::size()
{
	return count;
}

template<typename T>
bool ArrayList<T>::empty()
{
	return count == 0;
}

template<typename T>
T& ArrayList<T>::operator[](int index)
{
	return array[index];
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& arrayList) 
{
	if (this != &arrayList)
	{
		delete[] array;
		count = arrayList.count;
		length = arrayList.length;
		array = new T[length];
		for (int i = 0; i < length; i++)
		{
			array[i] = arrayList.array[i];
		}
	}
	return *this;
}

#endif