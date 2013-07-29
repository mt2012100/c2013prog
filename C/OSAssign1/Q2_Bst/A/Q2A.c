/*
	filename		:	Q2A.c
	Description	:	create a binary tree and return a node on the basis
					 of inorder traversal no.
	Athour		:	Pratibind Jha
*/

#include "Q2A.h"
#include<stdio.h>
#include<stdlib.h>
int count = 1;
//create a btree node 
NODE *createNode(NODE *node,int nodeNo, int children,int leftchild, int rightchild ) {
	if(node == NULL) {
		node = (NODE *)malloc(sizeof(NODE));
		node->nodeNo = nodeNo;
		node->children = children;
		node->left = (NODE *)malloc(sizeof(NODE));
		
		node->left = (NODE *)malloc(sizeof(NODE));
		
	}
}
