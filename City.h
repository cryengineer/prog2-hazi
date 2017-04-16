#pragma once
#include "Vector.h"

class City
{
	char* name;
	int dist; //a BFS soran a gyokertol valo tavolsagot tarolja
	Vector<City*> neighbors; //a szomszedos varosokra mutato pointereket tarolja

public:
	City(const char* name);
	City(const City& c);
	~City() { delete[] name; }

	const char* getName() const { return name; }
	void setName(const char* name);
	

	const int getDist() const { return dist; }
	void setDist(const int n);

	const Vector<City*> getNeighbors() const { return neighbors; }
	void addNeighbor(City* c);

	City& operator=(const City& c);
	bool operator==(const City& c);

};