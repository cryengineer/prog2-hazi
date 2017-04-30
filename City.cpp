#include "City.h"
using namespace std;
City::City()
{
	name = new char[1];
	dist = -1;
}

City::City(const char* name)
{
	this->name = new char[1];
	setName(name);
	dist = -1;
}

City::City(const City& c)
{
	name = new char[1];
	(*this) = c;
}

void City::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void City::setDist(const int n)
{
	if (n >= 0) dist = n;
}

void City::addNeighbor(int i)
{
	neighbors.pushBack(i);
}

City& City::operator=(const City& c)
{
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


ostream& operator<<(ostream& os, const City& c)
{
	cout << c.getName() << ", dist: " << c.getDist();
	return os;
}