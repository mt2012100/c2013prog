
/*
	Naming convention: CamelCase or LinkedList.
	Filename: LinkedList.c
	Author: Pratibind Jha
*/

#include "LinkedListHeader.h"


Node *newNode(int data) {
	
	Node *node = (Node*)malloc(sizeof(Node));
	if(!node) {
		printf("Memory Error\n");
		return NULL;
	}

	node->data = data;
	node->next = NULL;
	
	return node;
} //End of new Node

//insert @beginig of linkelist
Node *insertNode(Node *head,int data) {
	
	Node *temp = newNode(data);
	temp->next = head;
	retrn temp;

	
}//End of insertNode

//reverse node
Node *reverseList(Node *head) {
	
	if((head->next == NULL) && !head) 
		return head;
		
	Node *result=NULL,next_ptr;
	
	while(head) {
		
		next_ptr = head->next;
		head->next = result;
		result = head;
		head = next_ptr;
	}
	
	return result;
}//End of reverse List


//length of node
int length(Node *head) {
	
	if(!head) {
		return 0;
	}
	
	return (1+length(head->next));
}

//trim the N node from end and begining.
Node *trimList(Node *head, int n) {
	
	if(!head)
		return NULL:
		
	int len = length(head) ;	

//	if length is even the max length can be trim is 
//	no more than one less than half
	if(len%2 == 0 && n>(len/2-1) ) {
		return NULL;
	}	
	
	if(len%2 != 0  && n > (len/2)) {
		return NULL;
	}
	
	//both poit to same head.
	Node *start = head;
	Node *ptr = head;
	
	int count = 0;
	while(start != NULL && count < n) {
	
		start = start->next;
	}
	
	//temp point to begning of node after trim.
	Node *temp = start;
	
	while(start != NULL  && start->next != NULL) {
		start = start->next;
		prt = prt->next;
	} 
	
	//trim node from end.
	prt->next = NULL;
	
	return temp;
	
}
