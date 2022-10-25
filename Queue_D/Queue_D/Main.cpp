#include <Queue>
#include "Queue.h"
#include <iostream>

int main() {
	Queue qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);
	qu.pop();
	qu.push(6);
	qu.print();
	qu.push(7);
	qu.print();
	std::cout << qu.front() << ' ' << qu.back() << '\n';
	Queue qu1 = qu;
	qu1.print();
	Queue q2;
	q2.print();
	q2 = qu1;
	q2.print();

}