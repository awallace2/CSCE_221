#include "BinarySearchTree.h"
#include <stdexcept>
#include <queue>


void BinarySearchTree::deleteTree(BinaryNode *root){
	
	if(root == NULL) return;
	if(root->left != NULL){
		deleteTree(root->left);
	}
	if(root->right != NULL){
		deleteTree(root->right);
	}
	delete root;
	totalNode = 0;
	
}

void BinarySearchTree::insert(int k, BinaryNode *t, int& cost){
	cost++
	if(t == NULL){
		t = new BinaryNode(k);
		t->searchCost = cost;
		totalNode++;
		cout << "Key = " << k << "  Search Cost = " << cost << endl;
	}
	else if(k < t->key){
		t->left = insert(k, t->left, cost);
	}
	else if(k > t->key){
		t->right = insert(k, t->right, cost);
	}
	else{
		throw runtime_error("ERROR: Node already exists")
	}
	
	return t;
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
		totalNode--;
		resetSearchCost(root, 1);
	}
	else{
		totalNode--;
		BinaryNode *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
		resetSearchCost(root, 1);
	}
	
	return t;
	
}

void BinarySearchTree::resetSearchCost(BinaryNode *t, int& i){
	if(t == NULL){
		return;
	}
	resetSearchCost(t->left, i + 1);
	resetSearchCost(t->right, i + 1);
	t->searchCost = i;
}