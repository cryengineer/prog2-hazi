#include "City.h"

City::City(const char* name)
{
	setName(name);
	dist = -1;
}

City::City(const City& c) : name(NULL)
{
	(*this) = c;
}

void City::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void City::setDist(const int n)
{
	if (n >= 0) dist = n;
}

void City::addNeighbor(City* c)
{
	neighbors.pushBack(c);
}

City& City::operator=(const City& c)
{
	delete[] this->name;
	this->setName(c.name);
	this->dist = c.dist;
	this->neighbors = c.neighbors;
	return *this;
}

bool City::operator==(const City& c)
{
	if (strcmp(this->name, c.name) == 0) return true;
	return false;
}


