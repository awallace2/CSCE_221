#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedList; // class declaration

// list node
template <typename T>
struct DListNode {
  T obj;
  DListNode<T> *prev, *next;
  DListNode<T>(T e = T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list
template <typename T>
class DoublyLinkedList {
private:
  DListNode<T> header, trailer;
public:
  DoublyLinkedList() : header(T()), trailer(T()) // constructor
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList<T>(const DoublyLinkedList<T>& dll); // copy constructor
  ~DoublyLinkedList<T>(); // destructor
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
  void insertAfter(DListNode<T> &p, T newobj);
  void insertBefore(DListNode<T> &p, T newobj);
  T removeAfter(DListNode<T> &p);
  T removeBefore(DListNode<T> &p);
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);
// return the list length
template <typename T>
int DoublyLinkedListLength(const DoublyLinkedList<T>& dll);





// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;
  
  DListNode<T> *oldNode = dll.getFirst(); // set it equal to the first node in the list to be copied
  while(oldNode != dll.getAfterLast()){ // while its not the trailer, copy the old nodes in
	  T newObj = oldNode->obj;
	  this->insertLast(newObj);
	  oldNode = oldNode->next;
  }
  
}

// assignment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
  if(!isEmpty()){ // if it has nodes, delete them
	  DListNode<T> *current = header.next;
	  DListNode<T> *oldNode = header.next;
	  while(current != &trailer){
		  oldNode = current;
		  current = current->next;
		  delete oldNode;
	  }
	  header.next = &trailer;
	  trailer.prev = &header;
  }
  
  DListNode<T> *oldNode = dll.getFirst(); // set it equal to the first node in the list to be copied
  while(oldNode != dll.getAfterLast()){ // while its not the trailer, copy the old nodes in
	  T newObj = oldNode->obj;
	  this->insertLast(newObj);
	  oldNode = oldNode->next;
  }
  
  return *this;
}

// insert the new object as the first one
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
	DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
	DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{ 
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		DListNode<T> *node = header.next;
		node->next->prev = &header;
		header.next = node->next;
		T obj = node->obj;
		delete node;
		return obj;
	}
}

// remove the last object from the list
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		DListNode<T> *node = trailer.prev;
		node->prev->next = &trailer;
		trailer.prev = node->prev;
		T obj = node->obj;
		delete node;
		return obj;
	}
}

// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	DListNode<T> *prev_node, *node = header.next;
	while(node != &trailer){
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{ 
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List"); 
	}
	else{
		return header.next->obj;
	}
}

// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
	if(isEmpty()){
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else{
		return trailer.prev->obj;
	}
}

// insert the new object after the node p
template <typename T>
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
	DListNode<T> *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	DListNode<T> *newNode = new DListNode<T>(newobj, current, current->next);
	current->next->prev = newNode; // node after newNode points back to newNode
	current->next = newNode; // node p points to newNode
}

// insert the new object before the node p
template <typename T>
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
	DListNode<T> *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	DListNode<T> *newNode = new DListNode<T>(newobj, current->prev, current);
	current->prev->next = newNode; // node before previous points to newNode
	current->prev = newNode; // node p now points back to newNode
}

// remove the node after the node p
template <typename T>
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
	DListNode<T> *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	current = current->next; // current is now equal to the node to be removed
	current->next->prev = current->prev;
	current->prev->next = current->next;
	T obj = current->obj;
	delete current;
	return obj;
}

// remove the node before the node p
template <typename T>
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
	DListNode<T> *current = header.next;
	while(current != &p){
		current = current->next;
	}
	// current is now equal to p
	current = current->prev; // current is now equal to the node to be removed
	current->next->prev = current->prev;
	current->prev->next = current->next;
	T obj = current->obj;
	delete current;
	return obj;
	
}

// return the list length
template <typename T>
int DoublyLinkedListLength(const DoublyLinkedList<T>& dll)
{
    /* Complete this function */
	DListNode<T> *current = dll.getFirst();
	int count = 0;
	while(current != dll.getAfterLast()){
		count++;
		current = current->next;
	}
	return count;
}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
  
  /* Complete this function */
  DListNode<T> *current = dll.getFirst();
  int listLength = DoublyLinkedListLength<T>(dll);
  for(int i = 0; i < listLength; i++){
	  out << current->obj << " "; // output data of node
	  current = current->next; // go to next node
  }
  
  return out;
}
