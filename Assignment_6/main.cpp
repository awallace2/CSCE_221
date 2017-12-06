#include <iostream>
#include <vector>
#include <fstream>
#include "graph.h"

using namespace std;

int main(){
	
	string filename = "graph3.data";
	
	Graph k(filename);
	
	k.print();
	
	cout << "Can this graph be drawn in one stroke?:  " << k.status() << endl;
	
	k.findPath();
	
}