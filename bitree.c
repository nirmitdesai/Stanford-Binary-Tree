#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "bitree.h"


void bitree_init(BiTree *tree) 
{
	tree->size = 0;
	tree->root = NULL;
	return;

}

void insert(Node **node, int data) 
{
	Node *newNode;
	
	if (*node == NULL) 
	{
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = data;
		printf("INSERTED DATA %d\n",data);
		newNode->left = newNode->right = NULL;
		*node = newNode;
		
	}
	else 
	{
	
		if (data < (*node)->data) 
			insert(&(*node)->left, data);
		else 
			 insert(&(*node)->right, data);

	}
}

void preorder(Node *node)
{
	if(node==NULL)
		return;
	
	printf("%d\n",node->data);
	preorder(node->left);
	preorder(node->right);
	
}
void postorder(Node *node)
{
	if(node==NULL)
		return;
	
	
	postorder(node->left);
	postrder(node->right);
	printf("%d\n",node->data);
	
}
void inorder(Node *node)
{
	if(node==NULL)
		return;
	
	inorder(node->left);
	printf("%d\n",node->data);
	inorder(node->right);
	
}

void destroy_tree(Node *node)
{

	if(node==NULL)
		return;
	Node *tempL = node->left;
	Node *tempR = node->right;
	free(node);
	destroy_tree(tempL);
	destroy_tree(tempR);
}

int lookup(Node *node , int target)
{

	if(node == NULL)
		return 1;

	if(node->data == target)
		return 0;

	if (target < node->data) 
		return(lookup(node->left, target));
	else 
		return(lookup(node->right, target));
}

int maxDepth(Node *node)
{
	//if(node!=NULL)
		//printf("value encounbtered = %d\n",node->data);
	
	if(node == NULL)
		return 0;
	
	int lDepth = maxDepth(node->left);
	int rDepth = maxDepth(node->right);

	//printf(" leftdepth = %d\n",lDepth);
	//printf(" rdepth = %d\n",rDepth);
	if (lDepth > rDepth) 
		return(lDepth+1);
	else 
		return(rDepth+1);
}

int minValue(Node *node)
{
	while(node->left !=NULL)
		node = node->left;

	return node->data;
}



















