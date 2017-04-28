#include "Queue.h"
using namespace std;

int main()
{
	cout << "TEST: int tipussal" << endl;
	Queue<int> intQueue;
	intQueue.pushBack(25);
	intQueue.pushBack(63);
	intQueue.pushBack(100);
	intQueue.print();
	cout << "Az intQueue tarolo merete: " << intQueue.getSize() << endl;
	cout << "Lassuk a kovetkezo ket elemet:" << endl;
	cout << intQueue.popFront() << endl;
	cout << intQueue.popFront() << endl;
	intQueue.print();
	cout << "Es a harmadik:" << endl;
	cout << intQueue.popFront() << endl;
	if (intQueue.isEmpty() == true) cout << "Az intQueue tarolo ures." << endl;


	cout << endl << "TEST: double tipussal" << endl;
	Queue<double> doubleQueue;
	for (double i = 13; i < 64; i+=10) doubleQueue.pushBack(i / 7);
	doubleQueue.print();
	cout << "A doubleQueue tarolo merete: " << doubleQueue.getSize() << endl;
	cout << "Lassuk a kovetkezo ket elemet:" << endl;
	cout << doubleQueue.popFront() << endl;
	cout << doubleQueue.popFront() << endl;
	doubleQueue.print();
	cout << "Es most a maradek elemeket is kivesszuk:" << endl;
	while (doubleQueue.isEmpty() == false) cout << doubleQueue.popFront() << endl;


	cout << endl << "TEST: char tipussal" << endl;
	Queue<char> charQueue;
	charQueue.pushBack('h');
	charQueue.pushBack('e');
	charQueue.pushBack('l');
	charQueue.pushBack('l');
	charQueue.pushBack('o');
	charQueue.print();
	cout << "Vegyuk ki oket szepen, sorban, fifo modban: " << endl;
	while (charQueue.isEmpty() == false) cout << charQueue.popFront();
	cout << endl << "TEST vege";


	return 0;
}