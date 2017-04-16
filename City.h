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

	const char* getName() { return name; }
	void setName(const char* name);
	

	const int getDist() { return dist; }
	void setDist(const int n);

	void addNeighbor(City* nptr);

	City& operator=(const City& c);








};