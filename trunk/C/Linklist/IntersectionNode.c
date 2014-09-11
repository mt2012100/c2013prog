#include <stdio.h>
#include<stdlib.h>

//find intersection node of two list.
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
} node;

//create new node
node *createNode(int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

//find the merging node
node *intersectionPoint(node *list1, node *list2)
{
	if(!list1 || !list2)
		return NULL;
		
	node **stack1 = (node**)malloc(sizeof(node*)*100);
	node **stack2 = (node**)malloc(sizeof(node*)*100);
	int top1 = 0;
	int top2 = 0;
	
	while(list1 != NULL)
	{
		stack1[top1++] = list1;
		list1 = list1->next;
	}
	
	while(list2 != NULL)
	{
		stack2[top2++] = list2;
		list2= list2->next;
	}
	
	node *p=NULL,*q=NULL,*dum;
	while((p=stack1[--top1]) && (q=stack2[--top2]))
	{	
		
		if(p == q)
		{
			dum = p;
			continue;
		}
		
		return dum;
			
			
	}
	return NULL;
}

int main(void) {
	// your code goes here
	node *list1=NULL;
	node *list2=NULL;
	
	list1 = createNode(1);
	list1->next = createNode(2);
	list2 = createNode(3);
	node *temp;
	temp = createNode(4);
	list2->next = temp;
	list1->next->next = temp ;
	temp = createNode(5);
	list2->next->next = temp;
	list1->next->next->next = temp;
	
	
	node *join = intersectionPoint(list1,list2);
	printf("%d",join->data);
	return 0;
}
