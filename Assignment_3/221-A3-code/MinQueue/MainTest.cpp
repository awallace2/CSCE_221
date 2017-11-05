// Main for MinQueue Class Implementation

#include "MinQueue.h"
#include <iostream>

using namespace std;

int main() {
	MinQueue one;
	
	cout << "Adding values from 0 - 9 into Queue one" << endl;
	
	cout << endl;
	
	// insert numbers 0 - 9 to queue
	for(int i = 0; i < 10; i++){
		one.enqueue(i);
	}
	
	cout << "Enqueueing the value '-1'" << endl;
	
	cout << endl;
	
	// insert -1
	one.enqueue(-1);
	
	int min = one.min();
	
	// print elements of queue
	cout << "Elements of Queue one: " << one << endl;
	
	cout << endl;
	
	// print the minimum
	cout << "Min is: " << min << endl;
	
	cout << endl;
	
	//printing the size
	cout << "Size is: " << one.size() << endl;
	
	cout << endl;
	
	// dequeue first element and then output it
	
	cout << "Dequeueing the first element and returning" << endl;
	
	cout << endl;
	
	int first = one.dequeue();
	cout << "First element is: " << first << endl;
	
	cout << endl;
	
	// print the queue to ensure first thing was removed
	cout << "Elements of Queue one: " << one << endl;
	
	bool check = one.isEmpty();
	
	cout << endl;
	
	// see if the queue is empty
	cout << "Is the queue empty: " << check << endl;
	
	
}
