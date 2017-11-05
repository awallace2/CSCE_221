#incldue "BinaryNode.h"

class BinarySearchTree {
private:
	BinaryNode *root;
	void deleteTree(BinaryNode *root);
	
private:
	BinaryTree() { root = NULL; } // default constructor
	BinaryTree(int element) { root = new BinaryNode(element) } // constructor
	~BinaryTree() { deleteTree(root); root = NULL; } // destructor
	bool isEmpty() { return root == NULL; } // check if its empty
	
	
	// UNFINISHED 
	// int height
	// int size
	
	
}