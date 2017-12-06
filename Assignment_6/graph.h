#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring>

using namespace std;




class Graph{
private:
	vector<vector <int> > adMat; // matrix of the graph
	vector <int> points; // holds valid starting points for drawing path
	list<int> *adjList;
	bool isCircuit; // if its an euler circuit
	bool isPath; // if its an euler path
	int verticeCount;
	int edgeCount;
		

public:
	Graph(string filename);
	~Graph() { delete[] adjList; }
	void add(int start, int end); // adds vertices to matrix
	void print(); // prints graph as an adjacency list
	void path(); // sets the booleans to true if they match conditions
	void addPoints(int point) { points.push_back(point); }
	string status();
	void findPath();
	//void findEulerPath();
	//void findEulerCircuit();
	
	void addEdge(int start, int end)
	{ 
		adjList[start].push_back(end); 
		adjList[end].push_back(start);
	}
	void removeEdge(int start, int end);
	void printEulerPath();
	void printEulerPathStart(int start);
	int DFSCount(int end, bool visited[]);
	bool isNextEdgeValid(int start, int end);
	
	
};

