#include "Map.h"

using namespace std;



int main()
{
	Map map;
	map.print();
	cout << endl << endl;
	map.BFS("Sacramento");
	cout << endl << endl;
	map.print();


	return 0;
}