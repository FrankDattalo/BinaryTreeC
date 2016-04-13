#ifndef BI_TREE
#define BI_TREE

#ifndef dataType
#define dataType int
#endif

typedef void (*print_fuction)(dataType a);

typedef int (*compare_function)(dataType a, dataType b);

typedef struct _binary_tree
{
	dataType data;
	compare_function* compare;
	print_fuction* printer;
	struct _binary_tree* parent;
	struct _binary_tree* left;
	struct _binary_tree* right;	
} binary_tree;

/*
	Creates a new binary tree with root of data, and ordering property comparison.
*/
void* newBinaryTree(dataType data, compare_function* comparison, print_fuction* printer);

/*
	Inserts data into this.
*/
void insert(binary_tree* this, dataType data);

/*
	Reports if this contains data.
*/
int contains(binary_tree* this, dataType data);

/*
	Removes data from this if this contains data.
*/
void removeNode(binary_tree* this, dataType data);

/*
	Returns the node data or null if this does not contain data.
*/
binary_tree* find(binary_tree* this, dataType data);

/*
	Returns the left most child of this or this if there is no left child.
*/
binary_tree* getLeftMostChild(binary_tree* this);

/*
	Recursively frees tree.
*/
void freeTree(binary_tree* this);

/*
	Traverses nodes of this in order and prints them.
*/
void inOrderWalk(binary_tree* this);

#endif
