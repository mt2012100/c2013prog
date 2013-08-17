//Link list implementation.
#include "SLinklist.h"

void initLinkList() {
	node *head = NULL;
}

//create new node.
node *createNode(int data) {
	node *tem=NULL;
	tem = (node *)malloc(sizeof(node));
	if(!tem) 
		return NULL;
	
	tem->data = data;
	tem->next = NULL;
	
	return tem;
}//end of create new node.

//insert new node ,flag 0, if begning, 1 if end, -1 if after. 
node* insert(node *head, int data, int flag) {
	
	node *temp=NULL, *newNode = NULL;
	if(!head) {
		//printf("here1\n");
		newNode = createNode(data);
		/*if(newNode)
			printf("Memory error\n");*/
		newNode->next = head;
		head = newNode;
		//printf("%d ", head->data);
		return head;
	}	 
	temp = head;
	//printf("Here\n");
	//insert at begning of node.
	if(flag == 0) {
		newNode = createNode(data);
		//printf(" %d ", data);
		if(!newNode)
			return NULL;
		//printf(" %d ", data);	
		newNode->next = head;
		head = newNode;
		return head;	
	}
	
	//insert after node
	if(flag == 1) {
		newNode = createNode(data);
		if(!newNode)
			return 0;
			
		while(temp->next) {
			temp = temp->next;
		}
		
		temp->next = newNode;
		return head;
		
	}
}//End of insert funcrion

//Delete the node
int Delete(node *head, int data) {
	int flag=0;
	if(!head)
		return 0;
	
	node *temp,*prev = NULL;
	temp = head;
	
	while(temp) {
		if(temp->data == data) {
			flag = 1;
			break;
		}
		prev = temp;	
		temp = temp->next;	
	}
	
	if(flag) {
		if(!prev) {
			prev = temp;
			temp = temp->next;
			head = temp;
			free(prev);
			return 1;
		}
		
		prev->next  = temp->next;
		free(temp);
		return 1;
		
	}	
	
	return 0;
		
}


//Display node data.
void displayNode(node *head) {
	node *temp;
	 temp = head;
	if(!head) 
		printf("node is empty\n");
	while(temp) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

//free the memory
void freeList(node *head) {
	
	node *temp;
	temp = head;
	
	while(head) {
		temp = head;
		head = head->next;
		free(temp);
	}

}

//read data from file
int *readData(char *str) {
	FILE *fptr;
	int i=0,data;
	int *array;
	int length = fileLength(str);
	
	fptr = fopen(str, "r");
	
	if(!fptr) 
		return NULL;
		
	array = (int *)malloc(sizeof(int));
	
	if(!array) 
		return NULL;
		
	while(i<length) {
		fscanf(fptr,"%d", &data);	
		array[i++] = data;
	}
	fclose(fptr);
	return array;
}

//no of line is there in file.
int fileLength(char *str) {
	FILE *fptr;
	int count=0;
	char buf[127];
	
	fptr = fopen(str, "r");
	
	if(!fptr) 
		return 0;
		
	while(fgets(buf, 127, fptr) != NULL) {
		count++;
	}
	fclose(fptr);
	return count;
}


