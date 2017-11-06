#include "BinarySearchTree.h"
#include <stdexcept>


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

void BinarySearchTree::insertNode(int k){
	Binary *node = root;
	if(root == NULL){
		root = new BinaryNode(k);
	}
	else{
		insertRecursive(root, k, 1);
	}
	
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *t){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	while(t->left != NULL){
		t = t->left;
	}
	
	return t;
}

BinaryNode *BinarySearchTree::removeMin(BinaryNode *t){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	else if(t->left != NULL){
		t->left = removeMin(t->left);
	}
	else{
		BinaryNode *node = t;
		t = t->right;
		delete node;
	}
	
	return t;
}	

void insertRecursive(BinaryNode *node, int k, int comparison){
	comparisons++;
	if(k < node->getKey()){
		if(node->left == NULL){
			node->left = new BinaryNode(k, comparisons);
		}
		else{
			insertRecursive(node->left, k, comparisons);
		}
	else{
		if(node->right == NULL){
			node->right = new BinaryNode(k, comparisons);
		}
		else{
			insertRecursive(node->right, k, comparisons);
		}
	}
	
}

BinaryNode *BinarySearchTree::removeNode(int k, BinaryNode *t){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	if(k < t->key){
		t->left = removeNode(k, t->left);
	}
	else if(k > t->key){
		t->right = removeNode(k, t->right);
	}
	else if((t->left != NULL) && (r->right != NULL)){
		t->key = findMin(t->right)->key;
		t->right = removeMin(t->right);
	}
	else{
		BinaryNode *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
	}
	
	return t;
	
}