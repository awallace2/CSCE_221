#include "BinaryNode.h"


class BinarySearchTree {
private:
	BinaryNode *root;
	void deleteTree(BinaryNode *root);
	
public:
	BinarySearchTree() { root = NULL; } // default constructor
	BinarySearchTree(int element) { root = new BinaryNode(element); } // constructor
	~BinarySearchTree() { deleteTree(root); root = NULL; } // destructor
	BinaryNode *getRoot() const { return root; }
	bool isEmpty() { return root == NULL; } // check if its empty
	int size() { return (root == NULL) ? 0 : root->size(root); } // return size of tree
	int height() { return (root == NULL) ? 0 : root->height(root); } // return height of tree
	void insertNode(int k); // to insert nodes
	BinaryNode* findMin(BinaryNode *t); // find min value in tree
	BinaryNode* removeMin(BinaryNode *t); // remove min value
	BinaryNode* removeNode(int k, BinaryNode *t); // remove a designated node
	
	
};