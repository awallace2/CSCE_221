#include "BinaryNode.h"


int BinaryNode::size(BinaryNode *t) {
	
	if(t == NULL) {
		return 0;
	}
	else{
		return 1+size(t->left)+size(t->right);
	}
	
}

int BinaryNode::height(BinaryNode *t) {
	
	if(t == NULL){
		return -1;
	}
	else{
		int hlf = height(t->left);
		int hrt = height(t->right);
		return (hlf > hrt) ? 1+hlf : 1+hrt;
	}
}