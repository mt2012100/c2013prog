//Header file for single link list.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
//Data structure.

struct singleLinkList {
	int data;
	struct singleLinkList *next;
};

typedef struct singleLinkList node;

node *head;

//Initialize the link list
void initLinkList();

//create node
node *createNode(int data);

//insert the item 
// flag 0 for begning, 1 end, -1 for after.
node* insert(node *head, int data, int flag);

//Delete the node
int Delete(node *head, int data);

//Display node data.
void displayNode(node *head);

//free the memory
void freeList(node *head);

//read data from file
int *readData(char *str);

//no of line is there in file.
int fileLength(char *str);

