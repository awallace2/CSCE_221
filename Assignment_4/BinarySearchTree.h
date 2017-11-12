#include "BinaryNode.h"
#include <iostream>
#include <math.h>


class BinarySearchTree {
private:
	int totalNode;
	BinaryNode *root;
	BinaryNode* findMin(BinaryNode *t); // find min value in tree
	BinaryNode* removeMin(BinaryNode *t); // remove min value
	BinaryNode* removeNode(int k, BinaryNode *t); // remove a designated node
	BinaryNode* insert(int k, BinaryNode *t, int& cost);
	void deleteTree(BinaryNode *root);
	void resetSearchCost(BinaryNode *t, int k); // reset after deleting a node
	void inOrderTraversal(BinaryNode *t, int& totalCost); // different ways of outputting tree
	void preOrderTraversal(BinaryNode *t, int& totalCost);
	void postOrderTraversal(BinaryNode *t, int& totalCost);
	
public:
	BinarySearchTree() { root = NULL; totalNode = 0; } // default constructor
	~BinarySearchTree() { deleteTree(root); root = NULL; totalNode = 0; } // destructor
	BinaryNode *getRoot() const { return root; }
	bool isEmpty() { return root == NULL; } // check if its empty
	int size() { return (root == NULL) ? 0 : root->size(root); } // return size of tree
	int height() { return (root == NULL) ? 0 : root->height(root); } // return height of tree
	void insertNode(int k) { int cost = 0; root = insert(k, root, cost); } // to insert nodes
	void remove(int k) { root = removeNode(k, root); } // remove by key
	int inOrderTraversal(){
		int costTotal = 0;
		inOrderTraversal(root, costTotal); // using traversal function to return size
		cout << endl;
		return costTotal;
	}
	int preOrderTraversal(){
		int costTotal = 0;
		preOrderTraversal(root, costTotal);
		cout << endl;
		return costTotal;
	}
	int postOrderTraversal(){
		int costTotal = 0;
		postOrderTraversal(root, costTotal);
		cout << endl;
		return costTotal;
	}
	void outputLevelByLevel();
	void outputData(string filename);
	
	
	
	
};