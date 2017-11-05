#include "BinarySearchTree.h"


void BinarySearchTree::deleteTree(BinaryNode *root){
	
	if(root == NULL) return;
	if(root->left != NULL){
		deleteTree(root->left);
	}
	if(root->right != NULL){
		deleteTree(root->right);
	}
	delete root;
	
}