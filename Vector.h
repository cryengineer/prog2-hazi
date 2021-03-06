#pragma once
#include <iostream>

template <class itemT>
class Vector
{
	itemT* data;
	int size, count;

public:

	Vector() : size(5), count(0) //parameter nelkuli konstruktor
	{
		data = new itemT[size];
	} 
	Vector(int size) : size(size), count(0) //konstruktor: megadhato a vektor kezdomerete
	{
		data = new itemT[size];
	}
	Vector(const Vector& v); //masolo konstruktor
	~Vector() { delete[] data; } //destruktor

	const int getSize() const { return size; }
	const int getCount() const { return count; }
	bool isEmpty()
	{
		if (count == 0) return true;
		return false;
	}

	Vector& operator=(const Vector& v); //egyenlo operator
	itemT& operator[](int n) const; //indexelo operator
	void pushBack(itemT newItem); //a vektor vegen elhelyez egy elemet
	bool isElement(itemT element); //true, ha az adott elem benne van a vektorban, kulonben false
	int position(itemT element); //visszaadja az argumentumkent kapott elem indexet, -1et ad, ha nincs benne a vektorban
	void empty(); //kiuriti a vektort
	void print() const; //kiirja a vektor tartalmat



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
itemT& Vector<itemT>::operator[](int n) const
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
bool Vector<itemT>::isElement(itemT element)
{
	for (int i = 0; i < count; i++) if (data[i] == element) return true;
	return false;
}

template<class itemT>
int Vector<itemT>::position(itemT element)
{
	for (int i = 0; i < count; i++) if (data[i] == element) return i;
	return -1;
}

template<class itemT>
void Vector<itemT>::empty()
{
	delete[] data;
	data = NULL;
	count = 0;
}

template<class itemT>
void Vector<itemT>::print() const
{
	std::cout << "A vector tartalma:" << std::endl;
	for (int i = 0; i < count; i++) std::cout << data[i] << std::endl;
}