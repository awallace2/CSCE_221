#include "BinaryNode.h"


class BinarySearchTree {
private:
	BinaryNode *root;
	void deleteTree(BinaryNode *root);
	
public:
	BinarySearchTree() { root = NULL; } // default constructor
	BinarySearchTree(int element) { root = new BinaryNode(element); } // constructor
	~BinarySearchTree() { deleteTree(root); root = NULL; } // destructor
	bool isEmpty() { return root == NULL; } // check if its empty
	int size() { return (root == NULL) ? 0 : root->size(root); }
	int height() { return (root == NULL) ? 0 : root->height(root); }
	
	
};