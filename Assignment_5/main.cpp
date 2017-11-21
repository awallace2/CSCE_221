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
	
	string filename = "DataSetSize10.csv";
	
	//cout << "Please enter the name of the file for reading in: ";
	//cin >> filename;
	//cout << endl;
	
	// Here we will read in the data to the PriorityQueue
	ifstream inFile(filename);
	
	// This is to get rid of the first 3 words which we don't need
	inFile >> firstLine;
	inFile >> firstLine;
	inFile >> firstLine;
	
	// Read in all the data
	//if(inFile.is_open()){
		while(inFile.good()){
			getline(inFile, firstLine, ',');
			getline(inFile, secondLine, ',');
			getline(inFile, thirdLine, ',');
			
			jobID = stoi(firstLine);
			length = stoi(secondLine);
			priority = stoi(thirdLine);
			
			cout << "Job ID: " << jobID << " ";
			cout << "Job length: " << length << " ";
			cout << "Job priority: " << priority << endl;
			pq.insertItem(jobID, priority, length);
		}
	//}
	
	cout << endl;
	cout << "First Priority Job is: " << pq.minKey() << endl;
	cout << "First priority removed" << endl;
	cout << "Next priority job: " << pq.minKey() << endl;
	
	return 0;
	
}