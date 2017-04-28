#include "Vector.h"
#include "City.h"
using namespace std;

int main()
{
	cout << "TEST int tipussal:" << endl;
	Vector<int> intVector1;
	if (intVector1.isEmpty() == true) cout << "intVector1 ures :(" << endl;
	Vector<int> intVector2(5);
	cout << "intVector2" << endl;
	for (int i = 12; i < 19; i++) intVector2.pushBack(i);
	intVector2.print();
	intVector1 = intVector2;
	cout << "intVector1=intVector2, majd masolo konstruktor utan intVector3:" << endl;
	Vector<int> intVector3(intVector1);
	intVector3.print();
	cout << "merete es elemszama: " << intVector3.getSize() << " " << intVector3.getCount() << endl;
	cout << "6. eleme: " << intVector3[6] << endl;
	cout << "benne van-e a 15? " << intVector3.isElement(15) << ", indexe: " << intVector3.position(15) << endl;
	intVector3.empty();
	if (intVector3.isEmpty() == true) cout << "intVector3 kiurittetett :(" << endl;


	cout << endl << "TEST char tipussal:" << endl;
	Vector<char> charVector1;
	if (charVector1.isEmpty() == true) cout << "charVector1 ures :(" << endl;
	Vector<char> charVector2(5);
	cout << "charVector2" << endl;
	for (int i = 112; i < 119; i++) charVector2.pushBack(i);
	charVector2.print();
	charVector1 = charVector2;
	cout << "charVector1=charVector2, majd masolo konstruktor utan charVector3:" << endl;
	Vector<char> charVector3(charVector1);
	charVector3.print();
	cout << "merete es elemszama: " << charVector3.getSize() << " " << charVector3.getCount() << endl;
	cout << "6. eleme: " << charVector3[6] << endl;
	cout << "benne van-e az 'r'? " << charVector3.isElement('r') << ", indexe: " << charVector3.position('r') << endl;
	charVector3.empty();
	if (charVector3.isEmpty() == true) cout << "charVector3 kiurittetett :(" << endl;

	cout << endl << "TEST City tipussal:" << endl;
	Vector<City> cityVector1;
	Vector<City> cityVector2(3);
	City c1("Balmazujvaros");
	c1.setDist(2);
	City c2("Ketegyhaza");
	c2.setDist(58787999);
	City c3("Tapioszecso");
	c3.setDist(9825432);
	cityVector2.pushBack(c1);
	cityVector2.pushBack(c2);
	cityVector2.pushBack(c3);
	cityVector1 = cityVector2;
	cityVector1.print();
	cout << "Tapioszecso indexe: " << cityVector1.position(c3) << endl;
	cityVector1.empty();
	if (cityVector1.isEmpty() == true) cout << "cityVector1 kiuittetett :(" << endl;
	cout << "TEST vege" << endl;

	return 0;
}