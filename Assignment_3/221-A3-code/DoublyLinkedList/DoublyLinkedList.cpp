#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;
  
  DListNode *oldNode = dll.getFirst(); // set it equal to the first node in the list to be copied
  while(oldNode != dll.getAfterLast()){ // while its not the trailer, copy the old nodes in
	  int newObj = oldNode->obj;
	  this->insertLast(newObj);
	  oldNode = oldNode->next;
  }
  
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
  if(!isEmpty()){ // if it has nodes, delete them
	  DListNode *current = header.next;
	  DListNode *oldNode = header.next;
	  while(current != &trailer){
		  oldNode = current;
		  current = current->next;
		  delete oldNode;
	  }
	  header.next = &trailer;
	  trailer.prev = &header;
  }
  
  DListNode *oldNode = dll.getFirst(); // set it equal to the first node in the list to be copied
  while(oldNode != dll.getAfterLast()){ // while its not the trailer, copy the old nodes in
	  int newObj = oldNode->obj;
	  this->insertLast(newObj);
	  oldNode = oldNode->next;
  }
  
  return *this;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
	DListNode *newNode = new DListNode(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
	DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		DListNode *node = header.next;
		node->next->prev = &header;
		header.next = node->next;
		int obj = node->obj;
		delete node;
		return obj;
	}
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		DListNode *node = trailer.prev;
		node->prev->next = &trailer;
		trailer.prev = node->prev;
		int obj = node->obj;
		delete node;
		return obj;
	}
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
	removeAll();
}

// return the first object
int DoublyLinkedList::first() const
{ 
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List"); 
	}
	else{
		return header.next->obj;
	}
}

// return the last object
int DoublyLinkedList::last() const
{
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		return trailer.prev->obj;
	}
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
	DListNode *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	DListNode *newNode = new DListNode(newobj, current, current->next);
	current->next->prev = newNode; // node after newNode points back to newNode
	current->next = newNode; // node p points to newNode
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
	DListNode *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	DListNode *newNode = new DListNode(newobj, current->prev, current);
	current->prev->next = newNode; // node before previous points to newNode
	current->prev = newNode; // node p now points back to newNode
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(DListNode &p)
{
	DListNode *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	current = current->next; // current is now equal to the node to be removed
	current->next->prev = current->prev;
	current->prev->next = current->next;
	int obj = current->obj;
	delete current;
	return obj;
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(DListNode &p)
{
	DListNode *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	current = current->prev; // current is now equal to the node to be removed
	current->next->prev = current->prev;
	current->prev->next = current->next;
	int obj = current->obj;
	delete current;
	return obj;
	
}

// return the list length
int DoublyLinkedListLength(const DoublyLinkedList& dll)
{
    /* Complete this function */
	DListNode *current = dll.getFirst();
	int count = 0;
	while(current != dll.getAfterLast()){
		count++;
		current = current->next;
	}
	return count;
}

void DoublyLinkedList::removeAll(){
	DListNode *prev_node, *node = header.next;
	while(node != &trailer){
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
  
  /* Complete this function */
  DListNode *current = dll.getFirst();
  int listLength = DoublyLinkedListLength(dll);
  for(int i = 0; i < listLength; i++){
	  out << current->obj << " "; // output data of node
	  current = current->next; // go to next node
  }
  
  return out;
}
