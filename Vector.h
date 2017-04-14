#pragma once
#include <iostream>

template <class itemT>
class Vector
{
	itemT* data;
	int size, count;

public:

	Vector() : data(NULL), size(10), count(0) {}; //parameter nelkuli konstruktor
	Vector(int size) : size(size) //konstruktor: megadhato a vektor kezdomerete
	{
		count = 0;
		data = new itemT[size];
	}
	Vector(const Vector& v); //masolo konstruktor
	~Vector() { delete[] data; } //destruktor

	const int getSize() { return size; }
	const int getCount() { return count; }
	bool isEmpty()
	{
		if (count == 0) return true;
		return false;
	}

	Vector& operator=(const Vector& v); //egyenlo operator
	itemT& operator[](int n); //indexelo operator
	void pushBack(itemT newItem); //a vektor vegen elhelyez egy elemet
	void empty(); //kiuriti a vektort
	// bool insert(int n, itemT newItem); //az n. indexu elem moge szurja be a megadott elemet
	void print(); //kiirja a vektor tartalmat



};

template<class itemT>
Vector<itemT>::Vector(const Vector& v)
{
	size = v.size;
	data = new itemT[size];
	count = v.count;
	for (int i = 0; i < count; i++) data[i] = v.data[i];
}

template<class itemT>
Vector<itemT>& Vector<itemT>::operator=(const Vector& v)
{
	size = v.size;
	data = new itemT[size];
	count = v.count;
	for (int i = 0; i < count; i++) data[i] = v.data[i];
	return *this;
}

template<class itemT>
itemT& Vector<itemT>::operator[](int n)
{
	return data[n];
}

template<class itemT>
void Vector<itemT>::pushBack(itemT newItem)
{
	if (count < size)
	{
		data[count] = newItem;
		count++;
	}
	else
	{
		itemT* tmp = new itemT[2 * size];
		for (int i = 0; i < size; i++) tmp[i] = data[i];
		tmp[count] = newItem;
		count++;
		size *= 2;
		delete[] data;
		data = tmp;
	}
}

template<class itemT>
void Vector<itemT>::empty()
{
	delete[] data;
	data = NULL;
	count = 0;
}

template<class itemT>
void Vector<itemT>::print()
{
	std::cout << "A vector tartalma:" << std::endl;
	for (int i = 0; i < count; i++) std::cout << data[i] << std::endl;
}