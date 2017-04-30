#include "Map.h"

using namespace std;

int main()
{
	try
	{
		Map map("Hungary.txt");
		map.printMap();
		cout << endl << "Kerlek add meg annak a varosnak az indexet, ahonnan utazni szeretnel." << endl;
		int rootIndex = -1;
		cin >> rootIndex;
		while (rootIndex<1 || rootIndex > map.getSize())
		{
			cout << "Nincs ilyen indexu varos, a fenti indexek kozul valassz." << endl;
			cin >> rootIndex;
		}
		rootIndex--;
		cout << endl;

		map.BFS(rootIndex);
		map.printTransfers(rootIndex);
	}
	catch (const char* exc)
	{
		cout << "HIBA: " << exc << endl << "A program leall." << endl;
	}
	catch (const int)
	{
		cout << "HIBA: a megadott terkep ures." << endl << "A program leall." << endl;
	}

	return 0;
}