#include <iostream>
#include <vector>
#include <fstream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]){
	
	string filename = argv[1];
	
	Graph k(filename);
	
	k.print();
	
	cout << "Can this graph be drawn in one stroke?:  " << k.status() << endl;
	
	k.findPath();
	
}