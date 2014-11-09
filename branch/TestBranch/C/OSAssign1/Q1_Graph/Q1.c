/*
Filename		:	Q1.c
description	:	create a adjecenecy list representation of a graph
Date			:	12 Dec 2012	
Author		:	Pratibind Jha
*/
#include "Q1.h"
#include<stdio.h>
#include<stdlib.h>


//initilization of a graph
int inti_graph(int v) {
	int i=0;

	G = (graph*)malloc(sizeof(graph));
	if(G == NULL) {
		//printf("Memory Error\n");
		return 0;
	} 
	G->V = v;
	
	G->Adj = malloc(G->V * sizeof(list_node));	
	if(G->Adj == NULL) {
		//printf("Memory Error\n");
		return 0;
	}
	for(i=1; i<=(G->V);i++) {
		G->Adj[i] = (list_node*)malloc(sizeof(list_node));
		if(G->Adj[i] == NULL) {
			//printf("Memory Error\n");
			return 0;
		}
		G->Adj[i]->vertex_no = i;
		G->Adj[i]->next = NULL;
	}
	return 1;
	
}//End of init function

//Create a adjecency list representation of a graph
int create_graph(int v1, int v2) {
	
	list_node *node,*temp;
	int iscyc,i;
	
	//for cycle detection.
	for(i=1;i<=G->V;i++) {
		visited[i] = 0;
	}
	//vertex no should be range in 1 to G->V
	if((1 <= v1) && (v1 <= G->V) && (1 <= v2) && (v2 <= G->V) ) {
		node = (list_node*)malloc(sizeof(list_node));
		if(node == NULL) {
			return 0;
		}
		//check for allready exist edge.
		temp = G->Adj[v1];
		while(temp->next != NULL) {
			if(temp->next->vertex_no == v2) {
				return 3;
			}
			temp = temp->next;
			
		}
		iscyc = isCycle(G,v2,v1);
		//printf("%d\n",iscyc);
		
		if(iscyc == 1) {
			return 2;
		}
		else if(iscyc == 2) {
			return 0;
		}
		node->vertex_no = v2;
		node->next = NULL;
		temp = G->Adj[v1];
		while(temp->next != NULL) {
			temp = temp->next;
			
		}
		temp->next = node;
		return 1;
		/*node = (list_node*)malloc(sizeof(list_node));
		if(node == NULL) {
			return 0;
		}
		node->vertex_no = v1;
		node->next = G->Adj[v2];
		temp = G->Adj[v2];
		while(temp->next != G->Adj[v2]) {
			temp = temp->next;
		}
		temp->next = node;*/
		
	}
	
	return 4;
}//End of create_graph function

//DFS traversal
void DFS(graph *head,int i) {
	list_node *temp;
	static k=0;
	if(head == NULL) {
		printf("\nGraph is empty\n");
	}
	visited[i] = 1;
	printf("%d",i);
	temp = head->Adj[i];
	while((temp->next != NULL)) {
		
		if(!visited[temp->next->vertex_no]) {
			printf("->");
			DFS(head,temp->next->vertex_no);
			temp = temp->next;
		}
		else 
			//cycle_flag = 1;
			//back_edge[k++]= temp->next->vertex_no;
			temp = temp->next;
			
	}
	
}//End of DFS function

//cycle detection
int isCycle(graph *head,int startVrtx,int endVrtx) {
	list_node *temp;
	
	if(head == NULL) {
		printf("\nGraph is empty\n");
		return 2;
	}
	visited[startVrtx] = 1;
	
	if(startVrtx == endVrtx) {
		return 1;
	}
	
	
	temp = head->Adj[startVrtx];
	
	while((temp->next != NULL)) {
			
		if(!visited[temp->next->vertex_no]) {
			
			if(!(isCycle(head,temp->next->vertex_no,endVrtx))) {
				temp = temp->next;
			}
			else {
				return 1;
				
			}
			
		}
		else 
			//cycle_flag = 1;
			//back_edge[k++]= temp->next->vertex_no;
			temp = temp->next;
			
	}
	return 0;
}//End of isCycle.
