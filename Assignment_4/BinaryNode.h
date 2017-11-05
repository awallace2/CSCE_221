#include <iostream>

using namespace std;

class BinaryNode {
private:
	friend class BinaryTree;
	int key;
	int searchCost;
	BinaryNode *left, *right;
	
public:
	BinaryNode(int newKey = 0, int newSearchCost = 0, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
	: key(newKey), left(lt), right(rt) {} // constructor
	BinaryNode *getLeft() { return left; } // return left pointer
	BinaryNode *getRight() { return right; } // return right pointer
	int getKey() { return key; } // return key value
	int getSearchCost() { return searchCost }
	//int size(BinaryNode *t); // <------- Don't forget to finish these
	//int height(BinaryNode *t);
	
};



