// Main for MinQueue Class Implementation

#include "MinQueue.h"
#include <iostream>

using namespace std;

int main() {
	MinQueue one;
	
	// insert numbers 0 - 9 to queue
	for(int i = 0; i < 10; i++){
		one.enqueue(i);
	}
	
	one.enqueue(-1);
	
	int min = one.min();
	
	// print elements of queue
	cout << one << endl;
	
	cout << "Min is: " << min << endl;
	
	cout << "Size is: " << one.size() << endl;
	
	
}
