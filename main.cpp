#include "Map.h"

using namespace std;

int main()
{
	Map map("input2.txt");
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
	
	return 0;
}