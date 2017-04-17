#include "Vector.h"
using namespace std;

int main()
{
	Vector<int> intVector(10);
	//cout << intVector.getSize() << endl;
	for (int i = 10; i < 28; i++) intVector.pushBack(i);
	/*cout << intVector.getSize() << endl;
	intVector.print();
	for (int i = 33; i < 52; i++) intVector.pushBack(i);
	cout << intVector.getSize() << endl;
	intVector.print();*/

	Vector<int> intVector2(intVector);

	 
	cout << intVector2[0];

	intVector2.empty();
	if (intVector2.isEmpty() == true) cout << "intvector2 ures :(";
	intVector.print();
	cout << endl << intVector.isElement(9);
	cout << endl << intVector.position(0);


	return 0;
}