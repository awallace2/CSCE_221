#include "BinaryHeap.h"



int main(){
	
	PriorityQueue<int> pq;
	
	int jobID = 0;
	int length = 0;
	int priority = 0;
	
	jobID = 5;
	length = 2;
	priority = 2;
	
	pq.insertItem(jobID, priority);
	
	jobID = 3;
	priority = 2;
	
	pq.insertItem(jobID, priority);
	
	//jobID = 100000;
	//priority = 2;
	
	//pq.insertItem(jobID, priority);
	
	jobID = 100000;
	priority = -15;
	
	pq.insertItem(jobID, priority);
	
	cout << "First Priorty JobID: " << pq.minElement() << endl;
	
	return 0;
	
}