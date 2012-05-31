#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

typedef struct BiTreeNode_ 
{
	int data;
struct BiTreeNode_ *left;
struct BiTreeNode_ *right;
                   
} Node;

typedef struct BiTree_ {

	int size;
	Node *root;

} BiTree;


void bitree_init(BiTree *tree);


#endif
