#include <iostream>


using namespace std;

class BinaryNode {
private:
	friend class BinarySearchTree;
	int key;
	int searchCost;
	
	
public:
	BinaryNode *left, *right;
	BinaryNode(int k = 0, int search = 1, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
	: key(k), searchCost(search), left(lt), right(rt) {} // constructor
	BinaryNode *getLeft() { return left; } // return left pointer
	BinaryNode *getRight() { return right; } // return right pointer
	int getKey() { return key; } // return key value
	int getSearchCost() { return searchCost; }
	int size(BinaryNode *t); 
	int height(BinaryNode *t);
	
};



