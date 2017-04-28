#pragma once
#include "City.h"
#include "Vector.h"
#include <fstream>
#include <iostream>

class Map
{
	Vector<City> cities;
public:
	Map(const char* testFile)
	{
		readFile(testFile);
	}
	~Map() {}
	
	const int getSize() { return cities.getSize(); }
	void readFile(const char* testFile);
	void printMap();
	void printTransfers(const int rootIndex);
	void BFS(const int rootIndex);

};

