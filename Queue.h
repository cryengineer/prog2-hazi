#pragma once
#include <iostream>


template <class itemT>
class Queue
{
	struct unit //listaelem + a kovetkezo elemre mutato pointer
	{
		itemT item;
		unit* next;
	};
	
	unit* data; //a lista elso elemere mutato pointer
	int size;

public:
	Queue() : data(NULL), size(0) {};
	
	~Queue()
	{
		while (isEmpty() != true) popFront();
	}

	void pushBack(itemT newItem); //betesz egy elemet a Queue vegere
	itemT popFront(); //levesz egy elemet a Queue elejerol, es vissza is adja
	void print(); //kiirja a Queue tartalmat

	bool isEmpty()
	{
		if (size == 0) return true;
		return false;
	}
	
	const int getSize() const
	{
		return size;
	}

};

template<class itemT>
void Queue<itemT>::pushBack(itemT newItem)
{
	if (size == 0)
	{
		data = new unit;
		data->item = newItem;
		data->next = NULL;
		size++;
	}
	else
	{
		unit* it;
		for (it = data; it->next != NULL; it = it->next);
		it->next = new unit;
		it->next->item = newItem;
		it->next->next = NULL;
		size++;
	}
}

template<class itemT>
itemT Queue<itemT>::popFront()
{
	itemT first = data->item;
	unit* tmp = data->next;
	delete data;
	data = tmp;
	size--;
	return first;
}

template<class itemT>
void Queue<itemT>::print()
{
	std::cout << "A queue elemei: " << std::endl;
	for (unit* it = data; it != NULL; it = it->next) std::cout << it->item << " " << std::endl;
}