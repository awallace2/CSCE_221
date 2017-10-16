#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.h"

class MinQueue{
	
private:
	DoublyLinkedList dll;
	
public:
	MinQueue();
	~MinQueue() { dll.removeAll(); }
	MinQueue(const MinQueue& queue) : dll(queue.dll) { }
	MinQueue& operator=(const MinQueue&	queue);
	int size() { return DoublyLinkedListLength(dll); }
	int min();
	bool isEmpty() const { return dll.isEmpty(); }
	void enqueue(int newObj) { dll.insertLast(newObj); }
	int dequeue();
	
	
};

ostream& operator<<(ostream& out, const MinQueue& queue);


#endif
