#include "City.h"

using namespace std;

int main()
{
	City c1("Eger");
	cout << c1;
	City c2;
	c2.setName("Egerszalok");
	c2.setDist(3);
	City c3(c2);
	cout << c3;
	c1.addNeighbor(&c3);
	cout << "Eger szomszedja: " << c1.neighbors[0]->getName() << endl;
	if (!(c1 == c3)) cout << "Eger!=Egerszalok" << endl;
	c1 = c3;
	if (c1 == c3) cout << "Egerszalok=Egerszalok" << endl;
	cout << "TEST vege" << endl;

	return 0;
}