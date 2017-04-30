#pragma once
#include "Vector.h"

class City
{
	char* name;
	int dist; //a BFS soran a gyokertol valo tavolsagot tarolja
	//Vector<City*> neighbors; //a szomszedos varosokra mutato pointereket tarolja

public:
	Vector<int> neighbors; //a szomszedos varosok indexet tarolja
	City();
	City(const char* name);
	City(const City& c);
	~City() { delete[] name; }

	const char* getName() const { return name; }
	void setName(const char* name);
	

	const int getDist() const { return dist; }
	void setDist(const int n);

	void addNeighbor(int i);

	City& operator=(const City& c);
	bool operator==(const City& c);

	friend std::ostream& operator<<(std::ostream& os, const City& c);
};