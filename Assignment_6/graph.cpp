#include "graph.h"
#include <fstream>
#include <algorithm>
#include <list>
#include <string.h>
#include <iostream>

using namespace std;

Graph::Graph(string filename){
	
	ifstream inFile(filename);
	
	int vertices = 0;
	int edges = 0;
	
	//to hold the data about the graph
	string firstNumber;
	string secondNumber;
	
	//this is to get the number of vertices and edges
	getline(inFile, firstNumber, ' ');
	getline(inFile, secondNumber);
	
	vertices = stoi(firstNumber);
	edges = stoi(secondNumber);
	
	verticeCount = vertices;
	edgeCount = edges;
	
	//create size of adjacency matrix
	for(int i = 0; i < vertices; i++){
		vector<int> column;
		for(int j = 0; j < vertices; j++){
			column.push_back(0);
		}
		adMat.push_back(column);
	}
	
	//for the start and ends of edges
	string firstNum;
	string secondNum;
	
	int start = 0;
	int end = 0;
	
	adjList = new list<int>[edgeCount];
	
	//properly add the edges to the matrix
	while(getline(inFile, firstNum, ' ')){
		getline(inFile, secondNum);
		
		start = stoi(firstNum);
		end = stoi(secondNum);
		
		add(start, end);
		//cout << start << " " << end << endl;
		addEdge(start, end);
		
		
	}
	
	path();
	
	

}

void Graph::add(int start, int end){
	
	adMat.at(start - 1).at(end - 1) = 1;
	adMat.at(end - 1).at(start - 1) = 1;
	
}

void Graph::print(){
	// print as an adjacency list
	
	for(int i = 0; i < adMat.size(); i++){
		cout << i + 1 << " ";
		for(int j = 0; j < adMat.size(); j++){
			//cout << adMat.at(i).at(j) << " ";
			if(i == j){
				continue;
			}
			else if(adMat.at(i).at(j) == 1){
				cout << "-> " << j + 1 << " ";
			}
			else{
				continue;
			}
		}
		cout << endl;
		
	}
	
}

void Graph::path(){
	
	isPath = false;
	isCircuit = false; // these are false until shown to be true
	
	int odds = 0;
	int count = 0;
	
	for(int i = 0; i < adMat.size(); i++){
		for(int j = 0; j < adMat.size(); j++){
			if(adMat.at(i).at(j) == 1){
				count++;
			}
		}
		if((count % 2) == 1){
			odds++;
		}
		count = 0;
	}
	
	if(odds == 0){
		isCircuit = true;
		return;
	}
	else if(odds == 2){
		isPath = true;
		return;
	}
	else{
		return;
	}
}

string Graph::status(){
	
	if((isCircuit == true) || (isPath == true)){
		return "Yes";
	}
	else{
		return "No";
	}
	
}

void Graph::findPath(){
	
	if((isCircuit == true) && (isPath == false)){
		printEulerPathStart(1); // can start here since we know its already valid starting place
	}
	else if((isCircuit == false) && (isPath == true)){
		printEulerPath(); // find odd vertex and then print
	}
	else{
		cout << "There is no path to draw" << endl;
		return;
	}
	
	return;
	
}

/* void Graph::findEulerCircuit(){
	
	int current = 0;
	int start = 1;
	int counter = 0; // to help populate the count vector
	vector<int> count; // holds how many connections each vertex has left
	vector <vector <int>> data; // a copy of the adjacency matrix
	vector<int> path; // this will hold the actual path we take
	
	// copy the data to the matrix and fill up the count vector
	for(int i = 0; i < adMat.size(); i++){
		vector<int> column;
		for(int j = 0; j < adMat.size(); j++){
			column.push_back(adMat.at(i).at(j));
			if(adMat.at(i).at(j) == 1){
				counter++;
			}
		}
		data.push_back(column);
		count.push_back(counter); // update that value in the vector with the number of edges it has
	}
	
	current = 1;
	
	// this will run only for the number of edges that exist
	for(int k = 0; k < edgeCount; k++){
		
	}
	
} */


void Graph::printEulerPath(){
	
	int startPoint = 0; // starting point for path
	
	for(int i = 0; i < edgeCount; i++){
		if(adjList[i].size() & 1){
			startPoint = i;
			break;
		}
	}
	
	printEulerPathStart(startPoint);
	cout << endl;
}

void Graph::printEulerPathStart(int start){
	
	list<int>::iterator i;
	
	for(i = adjList[start].begin(); i != adjList[start].end(); i++){
		int end = *i;
		
		if((end != -1) && (isNextEdgeValid(start, end)))
		{
			cout << start << "->" << end << " "; 
			removeEdge(start, end);
			printEulerPathStart(end);
		}
	}
	
}

void Graph::removeEdge(int start, int end){
	
	list<int>::iterator one = find(adjList[start].begin(), adjList[start].end(), end);
	*one = -1;
	
	list<int>::iterator two = find(adjList[end].begin(), adjList[end].end(), start);
	*two = -1;
	
}

int Graph::DFSCount(int end, bool visited[]){
	
	visited[end] = true;
	int count = 1;
	
	list<int>::iterator i;
	for(i = adjList[end].begin(); i != adjList[end].end(); i++){
		if((*i != -1) && (!visited[*i])){
			count += DFSCount(*i, visited);
		}
	}
	
	return count;
	
}

bool Graph::isNextEdgeValid(int start, int end){
	
	int count = 0;
	list<int>::iterator i;
	// for if there is only one adjacent vertex
	for(i = adjList[start].begin(); i != adjList[start].end(); i++){
		if(*i != -1){
			count++;
		}
	}
	
	if(count == 1){
		return true;
	}
	
	bool visited[edgeCount];
	memset(visited, false, edgeCount);
	int countFirst = DFSCount(start, visited);
	
	removeEdge(start, end);
	memset(visited, false, edgeCount);
	int countSecond = DFSCount(start, visited);
	
	addEdge(start, end);
	
	return (countFirst > countSecond) ? false: true;
	
	
}
