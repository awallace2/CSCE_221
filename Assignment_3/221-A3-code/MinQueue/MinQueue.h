#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.h"

class MinQueue{
	
private:
	
	
public:
	DoublyLinkedList dll;
	MinQueue() : dll() {}
	~MinQueue() { dll.removeAll(); }
	int size() { return DoublyLinkedListLength(dll); }
	int min();
	bool isEmpty() const { return dll.isEmpty(); }
	void enqueue(int newObj) { dll.insertLast(newObj); }
	int dequeue() { return dll.removeFirst(); }
	
	
	
};

ostream& operator<<(ostream& out, MinQueue queue);



#endif
