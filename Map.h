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
	
	const int getSize() { return cities.getCount(); } //visszaadja a terkepen levo varosok szamat
	void readFile(const char* testFile); //beolvassa az inputot
	void printMap(); //kiirja a terkepen levo varosokat
	void printTransfers(const int rootIndex); //kiija a szukseges atszallasok szamat a kiindulasi varostol a BFS futasa utan
	void BFS(const int rootIndex);

};

