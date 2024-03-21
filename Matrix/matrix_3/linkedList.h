#ifndef linkedlist_h
#define linkedlist_h

#include "list.h"

template<typename T>
class LinkedList : public List<T>
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* pointer_next;
		T data;
		
		Node(T data = T(), Node* pointer_next = nullptr)
		{
			this->data = data;
			this->pointer_next = pointer_next;
		}
	};

	int count;
	Node<T>* head;

public:
	LinkedList();
	~LinkedList();

	void push_back(T) override;
	void insert(int, T) override;
	void erase(int) override;
	int size() override; 
	bool empty() override;
	void clear();
	void pop_back();
	int begin();
	
	T& operator[](const int index); //перегрузка скобок чтобы он возвращал элемент по индексу

};

template<typename T>
LinkedList<T>::LinkedList()
{
	count = 0;
	head = nullptr;
}


template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
void LinkedList<T>::clear()
{
	while (count)
	{
		Node<T>* temp_head = head;
		head = head->pointer_next;
		delete temp_head;
		count--;
	}
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head; //пройти по листу, и вставать элемент
		while (current->pointer_next != nullptr)
		{
			current = current->pointer_next;
		}
		current->pointer_next = new Node<T>(data);
	}
	count++;
}

template<typename T>
void LinkedList<T>::insert(int index, T data)
{
	if (index == 0)
	{
		head = new Node<T>(data, head);
		count++;
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pointer_next;
		}

		Node<T>* new_node = new Node<T>(data, previous->pointer_next);

		previous->pointer_next = new_node;

		count++;
	}
}

template<typename T>
void LinkedList<T>::erase(int index)
{
	if (index == 0)
	{
		Node<T>* node_to_erase = head;
		head = head->pointer_next;
		delete node_to_erase;
		count--;
	}

	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pointer_next;
		}

		Node<T>* node_to_erase = previous->pointer_next;
		previous->pointer_next = node_to_erase->pointer_next;
		delete node_to_erase;
		count--;
	}
}

template<typename T>
int LinkedList<T>::begin()
{
	return 0;
}

template<typename T>
int LinkedList<T>::size()
{
	return count;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	erase(size() - 1);
}

template<typename T>
bool LinkedList<T>::empty()
{
	return count == 0;
}

template<typename T>
T& LinkedList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pointer_next;
		counter++;
	}
}

#endif