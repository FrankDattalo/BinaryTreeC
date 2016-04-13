#include <stdio.h>
#define dataType char
#include "BinaryTree.h"

int compare(char x, char y) {
	return y - x;
}

void printFunct(char x) {
	printf("%c\n", x);
}

int main() {
	binary_tree* b = newBinaryTree(5, (void*)compare, (void*)printFunct);
	char i;
	for(i = 0; i < 127; i++) {
		insert(b, i);
	}
	inOrderWalk(b);
	return 0;
}