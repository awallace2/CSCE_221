// MinQueue.cpp
#include "MinQueue.h"


int MinQueue::dequeue(){
	if(dll.isEmpty()){
		throw runtime_error("This queue is empty");
	}
	else {
		return dll.removeFirst();
	}
}

int MinQueue::min(){
	if(dll.isEmpty()){
		throw runtime_error("This queue is empty");
	}
	else{
		int min = 0;
		int check = 0;
		MinQueue copy(*this);
		min = copy.dequeue();
		for(int i = 0; i < copy.size(); i++){
			check = copy.dequeue();
			if(check > min){
				min = check;
			}
		}
	}
	return min;
}

MinQueue& MinQueue::operator=(const MinQueue& queue){
	MinQueue copy(queue);
	MinQueue data;
	for(int i = 0; i < queue.size(); i++){
		data.enqueue(copy.dequeue());
	}
	for(j = 0; j < data.size(): j++){
		enqueue(data.deque());
	}
	return *this;
}

ostream operator<<(ostream& out, const MinQueue& queue){
	if(queue.isEmpty()){
		return out << "Queue is empty";
	}
	else {
		MinQueue copy(queue);
		for(int i = 0; i < queue.size(); i++){
			out << q.dequeue() << " ";
		}
	}
	return out;
}