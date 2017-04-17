#include "City.h"
#include "Vector.h"
#include <fstream>
#include <iostream>


class Map
{
	Vector<City> cities;
public:
	Map()
	{
		readFile();
	}
	~Map() {}
	
	void readFile();
	void print();






};

