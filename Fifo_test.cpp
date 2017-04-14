#include "Fifo.h"


int main()
{
	Queue<int> intFifo;
	for (int i=0;i<5;i++) intFifo.pushBack(2*i);
	intFifo.pushBack(15);
	intFifo.pushBack(19);
	intFifo.print();
	cout << "______" << intFifo.popFront() << endl;
	cout << "______" << intFifo.popFront() << endl;
	cout << "______" << intFifo.popFront() << endl;
	intFifo.print();







	return 0;
}