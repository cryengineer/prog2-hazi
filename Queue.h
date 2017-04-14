#pragma once
#include <iostream>


template <class itemT>
class Queue
{
	struct unit
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

	void pushBack(itemT newItem)
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
			for (it = data; it->next != NULL; it=it->next);
			it->next = new unit;
			it->next->item = newItem;
			it->next->next = NULL;
			size++;
		}
	}

	itemT popFront()
	{
		itemT first = data->item;
		unit* tmp = data->next;
		delete data;
		data = tmp;
		size--;
		return first;
	}

	bool isEmpty()
	{
		if (size == 0) return true;
		return false;
	}
	
	const int getSize()
	{
		return size;
	}

	void print()
	{
		std::cout << "A queue elemei: " << std::endl;
		for (unit* it = data; it != NULL; it = it->next) std::cout << it->item << " " << std::endl;
	}
};
