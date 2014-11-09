//Join the two linklist alternate node
#include<stdio.h>
#include<stdlib.h>

typedef struct linkList {
	int data;
	struct linkList *next;
}node;

node *createNode(int data) {

	node *temp = (node *)malloc(sizeof(node));
	
	if(temp == NULL)
		return NULL;
	
	temp->data = data;
	temp->next = NULL;	
	
	return temp;
}

node *mergeAlternative(node *dest, node *src) {
	
	node *head=dest, *curr=NULL;
	
	node *p,*q,*pnext,*qnext;
	
	if(!dest)
		return NULL;
	p = dest;
	q = src;
	
	while((dest != NULL) && (src != NULL) ) {
	
		pnext = dest->next;
		qnext = src->next;
		
		dest->next = src;
		src->next = pnext;
		
		dest = pnext;
		src = qnext;
	}
		
	return head;	
} 

void display(node *head) {
	
	while(head) {
		printf("%d\t",head->data);
		head = head->next;
	}
	return ;
}

int main() {

	node *p,*temp, *q;
	p = createNode(1);
	p->next =  	createNode(3);
	p->next->next = createNode(5);
	
	q = createNode(2);
	q->next =  	createNode(9);
	q->next->next = createNode(6);
	
	temp = mergeAlternative(p,q);
	
	display(temp);
	
return 0;
}

