//Driver program.
#include "graph.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int countLine(char *str) {
	char buff[100],count=0;
	FILE *fptrs;
	if(!(fptrs = fopen(str,"r"))) {
		printf("Error in file operation\n");
		return 0;
	}
	
	while(fgets(buff,sizeof(buff), fptrs) != NULL)
		count++;
	
	fclose(fptrs);	
	return count;		
}

int main(int argc, char *argv[]) {
	FILE *fptr;	
	int V=0,E=0,lineNumber=0,i=0,v1=0,v2=0,c;
	if(argc<2) {
		printf("Please provide the input file as command line argument\n");
		return 0;	
	}	
	lineNumber = countLine(argv[1]);
	
	if(!(fptr = fopen(argv[1],"r")))  {
		printf("Error in file operation\n");
		return 0;
	}
	
	
	printf("Line Number %d\n",lineNumber);
	
	fscanf(fptr, "%d",&V);
	fscanf(fptr, "%d",&E);
	printf("No of Vertex %d NO of Edge %d\n",V,E);
	
	for(;i<lineNumber-2;i++) {
		fscanf(fptr, "%d",&v1);
		c = fgetc(fptr);
		c = fgetc(fptr);
		c = fgetc(fptr);
		c = fgetc(fptr);
		fscanf(fptr, "%d",&v2);
		printf("Edge: %d %d\n",v1,v2);
		
	}
	
	
	
return 0;
}

