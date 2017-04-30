#include "Map.h"
#include "City.h"
#include "Queue.h"

using namespace std;

void Map::readFile(const char* testFile)
{
	std::ifstream input(testFile);
	char* first = new char[20];
	char* second = new char[20];
	int n1, n2;
	if (!input) throw "A fajl megnyitasa sikertelen.";
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
		cities[n1].neighbors.pushBack(n2);
		cities[n2].neighbors.pushBack(n1);
	}
	input.close();
	if (cities.getCount() == 1) throw 0; //ha az input fajlban egy sor sincs, vagyis a terkep ures
}

void Map::printMap()
{
	cout << "Az alabbi varosok kozotti kozlekedest ismerem:" << endl;
	for (int i = 0; i < cities.getCount(); i++)
	{
		cout << i+1 << " " << cities[i].getName() << endl;
	}
}

void Map::printTransfers(int rootIndex)
{
	cout << cities[rootIndex].getName() << " varosbol a felsorolt varosokba utazva az atszallasok szama: " << endl;
	for (int i = 0; i < cities.getCount(); i++)
	{
		if (i != rootIndex)
		{
			cout << cities[i].getName() << ": ";
			if (cities[i].getDist() != -1)
			{
				if (cities[i].getDist() == 1) cout << "van kozvetlen jarat" << endl;
				else cout << cities[i].getDist() - 1 << endl;
			}
			else cout << "ide sajnos nem tudsz eljutni. :(" << endl;
		}
	}
}

void Map::BFS(const int rootIndex)
{
	Queue<int> q;
	cities[rootIndex].setDist(0);
	for (int i = 0; i < cities[rootIndex].neighbors.getCount();i++)
	{
		cities[cities[rootIndex].neighbors[i]].setDist(1);
		q.pushBack(cities[rootIndex].neighbors[i]);
	}
	while (q.isEmpty() != true)
	{
		int c_index = q.popFront();
		for (int j = 0; j < cities[c_index].neighbors.getCount(); j++)
		{
			if (cities[cities[c_index].neighbors[j]].getDist() == -1)
			{
				cities[cities[c_index].neighbors[j]].setDist(cities[c_index].getDist() + 1);
				q.pushBack(cities[c_index].neighbors[j]);
			}
		}
	}
}