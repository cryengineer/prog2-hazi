#include "Map.h"
#include "City.h"
#include "Queue.h"

using namespace std;

void Map::readFile()
{
	std::ifstream input("input.txt");
	char* first = new char[20];
	char* second = new char[20];
	int n1, n2;
	if (!input) std::cout << "Hiba a fajl megnyitasakor :(" << std::endl;
	else
	{
		while (input.eof() == 0)
		{
			input >> first;
			input >> second;
			City c1(first);
			City c2(second);
			if (cities.isElement(c1) == false)
			{
				cities.pushBack(c1);
				n1 = cities.getCount() - 1;
			}
			else n1 = cities.position(c1);
			if (cities.isElement(c2) == false)
			{
				cities.pushBack(c2);
				n2 = cities.getCount() - 1;
			}
			else n2 = cities.position(c2);
			cities[n1].neighbors.pushBack(&(cities[n2]));
			cities[n2].neighbors.pushBack(&(cities[n1]));
		}
		input.close();
	}
}

void Map::print()
{
	for (int i = 0; i < cities.getCount(); i++)
	{
		cout << i << " " << cities[i].getName() << ", tavolsag:" << cities[i].getDist() << endl;
		for (int j = 0; j < cities[i].neighbors.getCount(); j++)
		{
			cout << cities[i].neighbors[j]->getName() << endl;
		}
	}
}

void Map::BFS(const char* root)
{
	Queue<City*> q;
	City c(root);
	int rootIndex=cities.position(c);
	cities[rootIndex].setDist(0);
	for (int i = 0; i < cities[rootIndex].neighbors.getCount();i++)
	{
		cities[rootIndex].neighbors[i]->setDist(1);
		q.pushBack(cities[rootIndex].neighbors[i]);
	}
	while (q.isEmpty() != true)
	{
		City* cptr = q.popFront();
		for (int j = 0; j < cptr->neighbors.getCount(); j++)
		{
			if (cptr->neighbors[j]->getDist() == -1)
			{
				cptr->neighbors[j]->setDist(cptr->getDist() + 1);
				q.pushBack(cptr->neighbors[j]);
			}
		}
	}

}