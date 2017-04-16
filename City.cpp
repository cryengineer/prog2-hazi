#include "City.h"

City::City(const char* name)
{
	setName(name);
	dist = -1;
}

City::City(const City& c)
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

void City::addNeighbor(City* nptr)
{
	neighbors.pushBack(nptr);
}

City& City::operator=(const City& c)
{
	delete[] this->name;
	this->name = new char[strlen(c.name) + 1];
	strcpy(this->name, c.name);
	this->dist = c.dist;
	this->neighbors = c.neighbors;
	return *this;
}

bool City::operator==(const City& c)
{
	if (strcmp(this->name, c.name) == 0) return true;
	return false;
}


