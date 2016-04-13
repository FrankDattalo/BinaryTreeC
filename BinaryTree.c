#ifndef BI_TREEC
#define BI_TREEC

#include <stdlib.h>

#include "BinaryTree.h"

void* newBinaryTree(dataType data, compare_function comparison, print_fuction printer){
	binary_tree* b = (binary_tree*) malloc(sizeof(binary_tree));
	b->data = data;
	b->left = NULL;
	b->right = NULL;
	b->parent = NULL;
	b->printer = printer;
	if(comparison != NULL) {
		b->compare = comparison;
	}
}

void insert(binary_tree* this, dataType data) {
	if(this->compare(this->data, data) < 0) {
		if(this->left != NULL) {
			insert(this->left, data);
		} else {
			this->left = (binary_tree*) newBinaryTree(data, this->compare, this->printer);
			this->left->parent = this;
		}
	} else {
		if(this->right != NULL) {
			insert(this->right, data);
		} else {
			this->right = (binary_tree*) newBinaryTree(data, this->compare, this->printer);
			this->right->parent = this;
		}
	}
}

int contains(binary_tree* this, dataType data) {
	binary_tree* rem = find(this, data);
	return rem != NULL;
}

void removeNode(binary_tree* this, dataType data) {
	binary_tree* rem = find(this, data);
	if(rem != NULL) {
		binary_tree* left;
		if(rem->right != NULL) {
			left = getLeftMostChild(this->right);
		} else if(rem->left != NULL) {
			left = rem->left;
		} else {
			left = rem;
		}
		if(left != rem) {
			left->left = rem->left;
			left->right = rem->right;
			if(left->parent->left == left) {
				left->parent->left = NULL;
			} else {
				left->parent->right = NULL;
			}
			left->parent = rem->parent;
			free(rem);
		} else {
			free(left);
		}
	}
}

binary_tree* find(binary_tree* this, dataType data) {
	if(this != NULL) {
		int c = this->compare(this->data, data);
		if(c < 0) {
			find(this->right, data);
		} else if(!c){
			return this;
		} else {
			find(this->left, data);
		}
	} else {
		return NULL;
	}
}

binary_tree* getLeftMostChild(binary_tree* this) {
	if(this->left == NULL) {
		return this;
	} else {
		return getLeftMostChild(this->left);
	}
}

void freeTree(binary_tree* this) {
	if(this->left != NULL) {
		freeTree(this->left);
	}
	if(this->right != NULL) {
		freeTree(this->right);
	}
	free(this);
}

void inOrderWalk(binary_tree* this) {
	if(this->left != NULL) {
		inOrderWalk(this->left);
	}
	this->printer(this->data);
	if(this->right != NULL) {
		inOrderWalk(this->right);
	}
}

#endif
