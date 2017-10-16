// MinQueue.cpp
#include "MinQueue.h"


int MinQueue::min(){
	int min = 0;
	if(dll.isEmpty()){
		throw runtime_error("This queue is empty");
	}
	else{
		int check = 0;
		min = dll.getFirst()->obj;
		DListNode* curr = dll.getFirst();
		while(curr != dll.getAfterLast()){
			if(min > curr->obj){
				min = curr->obj;
			}
			curr = curr->next;
		}
	
}

return min;
}

ostream& operator<<(ostream& out, MinQueue queue){
	if(queue.isEmpty()){
		return out << "Queue is empty";
	}
	else {
		DListNode* curr = queue.dll.getFirst();
		while(curr != queue.dll.getAfterLast()){
			out << curr->obj << " ";
			curr = curr->next;
		}
	}
	return out;
}


