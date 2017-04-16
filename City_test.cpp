#include <iostream>
#include "City.h"

using namespace std;


int main()
{
	City c1("Eger");
	cout << c1.getName() << endl;
	City c2("Budapest");
	cout << c2.getName() << endl;
	City c1_copy(c1);
	cout << c1_copy.getName() << endl;
	City c3("Prugy");
	cout << c3.getName() << endl;
	c3.setName("Solymar");
	cout << c3.getName() << endl;
	cout << (c1_copy == c3) << endl;
	c1_copy = c3;
	cout << (c1_copy == c3) << endl;
	c2.addNeighbor(&c1);
	c2.addNeighbor(&c3);
	cout << c2.getNeighbors()[0]->getDist() << endl;
	c2.getNeighbors()[0]->setDist(3);
	cout << c2.getNeighbors()[0]->getDist() << endl;
	cout << c2.getNeighbors().getCount() << endl;

	return 0;
}