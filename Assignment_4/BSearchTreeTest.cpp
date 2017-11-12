// main function
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	
	try{
		cout << "Enter the name of the file you would like to open: ";
		string input;
		cin >> input;
		cout << endl;
		
		ifstream file; // ifstream to read the data from the file
		file.open(input); // open the file
		int data; // int to store values
		int totalNodes = 0; // keep track of total nodes
		vector<int> inputData;
		
		if(file.is_open()){ // while file is open
			cout << "Outputting Data:" << endl;
			while(file >> data){ // while values are still being read in
				totalNodes++; // increment total nodes
				inputData.push_back(data); // push values into vector
				cout << data << endl;
			}
			file.close();
		}
		else{
			throw runtime_error("ERROR: Could not open designated file"); // throw error if file not found
		}
		
		cout << endl;
		
		cout << "Creating Binary Search Tree:" << endl;
		
		BinarySearchTree tree; // create tree
		
		for(int i = 0; i < inputData.size(); i++){
			tree.insertNode(inputData[i]); // insert data into tree
		}
		
		cout << "Number of nodes: " << totalNodes << endl;
		cout << endl;
		
		cout << "Printing using In-Order Traversal: "; // output using different traversal types
		int totalCost = tree.inOrderTraversal();
		
		cout << endl;
		
		cout << "Printing using Pre-Order Traversal: ";
		tree.preOrderTraversal();
		
		cout << endl;
		
		cout << "Printing using Post-Order Traversal: ";
		tree.postOrderTraversal();
		
		cout << endl;
		
		double averageCost = (double)totalCost / (double)totalNodes; // compute average cost
		cout << "Average search cost: " << averageCost << endl;
		
		cout << endl;
		
		string pre = "Output_";
		string extension = ".txt";
		
		string total = pre + input;
		total = total + extension;
		
		if(totalNodes <= 16){
			tree.outputData(total); // output data to file called "Output_filename.txt"
		}
		cout << endl;
		int removal;
		
		cout << "Enter a key to remove from the tree: ";
		cin >> removal;
		
		tree.remove(removal);
		
		int newTotalCost = tree.inOrderTraversal();
		totalNodes--;
		double newAverageCost = (double)newTotalCost / (double)totalNodes;
		cout << "New total number of nodes: " << totalNodes << endl;
		cout << "New average search cost: " << newAverageCost << endl;
		cout << endl;
	}
	catch(runtime_error& e){
		cout << e.what();
	}
	
}