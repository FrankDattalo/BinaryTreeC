#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

	srand(time(NULL));
	int i, x;
	
	for(i = 0; i < 1000; i++) {
		x = rand();
		insert(b, x);
	}

	inOrderWalk(b);
	freeTree(b);

	return 0;
}
