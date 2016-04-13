#include <stdio.h>

#define dataType int
#include "BinaryTree.h"

int compare(dataType x, dataType y) {
	return y - x;
}

void printFunct(dataType x) {
	printf("%d\n", x);
}

int main() {
	
	binary_tree* b = newBinaryTree(5, (void*)compare, (void*)printFunct);
	

	int i;
	for(i = 0; i < 1000; i++) {
		insert(b, i);
	}

	inOrderWalk(b);

	return 0;
}