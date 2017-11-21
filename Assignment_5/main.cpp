#include "BinaryHeap.h"
#include <



int main(){
	
	PriorityQueue<int> pq;
	
	int jobID = 5;
	int length = 0;
	int priority = 0;
	
	length = 2;
	priority = 2;
	
	pq.insertItem(jobID, priority);
	
	
	
	cout << "First priority removed" << endl;
	cout << "Next priority job: " << pq.minKey() << endl;
	
	return 0;
	
}