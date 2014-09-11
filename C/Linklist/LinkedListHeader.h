/*
	filename: linkedlist_header.h
	Description: contain all function signature and declearation
	author	: Pratibind Jha
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct linkedlist {

	int data;
	struct linkedlist next;
}Node;

Node *head;

//create new node
Node *newNode(int data);

//insert new node @begining the linkedlist
Node *insertNode(Node *head,int data);

//delete node from rear
Node *deleteNode();

//traverse the linked list
void *traverse(Node *head);

//reverse the  linkedlist
Node *reverseList(Node *head);

//trim the List N node from beginig and end 
Node *trimList(Node *head, int n);
