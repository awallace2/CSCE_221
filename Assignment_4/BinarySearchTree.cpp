#include "BinarySearchTree.h"
#include <stdexcept>
#include <queue>
#include <fstream>


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

BinaryNode *BinarySearchTree::insert(int k, BinaryNode *t, int& cost){
	cost++;
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
		throw runtime_error("ERROR: Node already exists");
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
	else if((t->left != NULL) && (t->right != NULL)){
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

void BinarySearchTree::resetSearchCost(BinaryNode *t, int k){
	if(t == NULL){
		return;
	}
	resetSearchCost(t->left, k + 1);
	resetSearchCost(t->right, k + 1);
	t->searchCost = k;
}

void BinarySearchTree::inOrderTraversal(BinaryNode *t, int& totalCost){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	if(t->left != NULL){
		inOrderTraversal(t->left, totalCost);
	}
	if(totalNode <= 16){
		cout << t->key << "[" << t->searchCost << "] ";
	}
	totalCost += t->searchCost;
	
	if(t->right != NULL){
		inOrderTraversal(t->right, totalCost);
	}
	
}

void BinarySearchTree::preOrderTraversal(BinaryNode *t, int& totalCost){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	if(totalNode <= 16){
		cout << t->key << "[" << t->searchCost << "] ";
	}
	totalCost += t->searchCost;
	
	if(t->left != NULL){
		preOrderTraversal(t->left, totalCost);
	}
	if(t->right != NULL){
		preOrderTraversal(t->right, totalCost);
	}

	
}

void BinarySearchTree::postOrderTraversal(BinaryNode *t, int& totalCost){
	if(t == NULL){
		throw runtime_error("ERROR: Tree is empty");
	}
	if(t->left != NULL){
		postOrderTraversal(t->left, totalCost);
	}
	if(t->right != NULL){
		postOrderTraversal(t->right, totalCost);
	}
	if(totalNode <= 16){
		cout << t->key << "[" << t->searchCost << "] ";
	}
	
	totalCost += t->searchCost;
	
	
}

void BinarySearchTree::outputLevelByLevel(){
	if(!root){
		return;
	}
	
	queue<BinaryNode*> data;
	int currentLevel = 1;
	int nextLevel = 0;
	
	data.push(root);
	
	BinaryNode* X = new BinaryNode(-1);
	bool check = true;
	vector<int> line;
	
	while(!data.empty()){
		BinaryNode *currentNode = data.front();
		data.pop();
		currentLevel--;
		if(currentNode){
			line.push_back(currentNode->key);
			if(currentNode->left == NULL){
				data.push(X);
			}
			else{
				check = false;
				data.push(currentNode->left);
			}
			if(currentNode->right == NULL){
				data.push(X);
			}
			else{
				check = false;
				data.push(currentNode->right);
			}
			nextLevel += 2;
		}
		if(currentLevel == 0){
			for(int i = 0; i < line.size(); i++){
				if(line[i] == -1){
					cout << "X ";
				}
				else{
					cout << line[i] << " ";
				}
			}
			cout << endl;
			if(check){
				return;
			}
			line.clear();
			check = true;
			currentLevel = nextLevel;
			nextLevel = 0;
		}
	}
	
	delete X;
	
}

void BinarySearchTree::outputData(string filename){
	ofstream ofs(filename);
	if(!root){
		return;
	}
	queue<BinaryNode*> data;
	int currentLevel = 1;
	int nextLevel = 0;
	
	data.push(root);
	
	BinaryNode* X = new BinaryNode(-1);
	bool check = true;
	vector<int> line;
	
	while(!data.empty()){
		BinaryNode *currentNode = data.front();
		data.pop();
		currentLevel--;
		if(currentNode){
			line.push_back(currentNode->key);
			if(currentNode->left == NULL){
				data.push(X);
			}
			else{
				check = false;
				data.push(currentNode->left);
			}
			if(currentNode->right == NULL){
				data.push(X);
			}
			else{
				check = false;
				data.push(currentNode->right);
			}
			nextLevel += 2;
		}
		if(currentLevel == 0){
			for(int i = 0; i < line.size(); i++){
				if(line[i] == -1){
					ofs << "X ";
				}
				else{
					ofs << line[i] << " ";
				}
			}
			ofs << endl;
			if(check){
				return;
			}
			line.clear();
			check = true;
			currentLevel = nextLevel;
			nextLevel = 0;
		}
	}
	
	delete X;
	
}

