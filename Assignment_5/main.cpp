#include "BinaryHeap.h"
#include <fstream>
#include <string>



int main(){
	
	PriorityQueue<int> pq;
	int length;
	int jobID;
	int priority;
	
	string firstLine;
	string secondLine;
	string thirdLine;
	
	string filename = "DataSetSize1000000.csv";
	
	//cout << "Please enter the name of the file for reading in: ";
	//cin >> filename;
	//cout << endl;
	
	// Here we will read in the data to the PriorityQueue
	ifstream inFile(filename);
	
	// This is to get rid of the first 3 words which we don't need
	getline(inFile, firstLine);
	
		// read in all the data and add it to the priority queue
		while(getline(inFile, firstLine, ',')){
			getline(inFile, secondLine, ',');
			getline(inFile, thirdLine);
			
			jobID = stoi(firstLine);
			length = stoi(secondLine);
			priority = stoi(thirdLine);
			
			pq.insertItem(jobID, priority, length);
		}
	
	// outputs to file with similar name
	pq.runJobs(filename);
	
	return 0;
	
}