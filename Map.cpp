#include "Map.h"
#include "City.h"


void Map::readFile()
{
	std::ifstream input("input.txt");
	char* first = new char[20];
	char* second = new char[20];
	int n;
	if (!input) std::cout << "Hiba a fajl megnyitasakor :(" << std::endl;
	else
	{
		input >> first;
		input >> second;
		while (input.eof() == 0)
		{
			City c1(first);
			City c2(second);
			if (cities.isElement(c1) == false) cities.pushBack(c1);
			if (cities.isElement(c2) == false) cities.pushBack(c2);
			n = cities.position(c1);
			c2.addNeighbor(&(cities[n]));
			n = cities.position(c2);
			c1.addNeighbor(&(cities[n]));
			input >> first;
			input >> second;
		}
		input.close();
	}
}