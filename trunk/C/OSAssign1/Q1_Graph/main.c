/*
Filename 		: 	program.c
Description	: 	call function to create a Adj list.
Author		: 	Pratibind jha
*/

#include "Q1.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[]) {
	int v,e,v1,v2,i=0,j=1,create_status;
	FILE *fptr,*fptr1;
	int maxNode,space,start=0;
	char line[1024];
	//printf("\nEnter the no of vertex and Edge:\n");
	//printf("argc is %d",argc);
	if(argc < 2 ) {
		printf("Please Enter the filename using command Line argument.");
		return 0;
		//exit 1;
	}
	
	fptr=fopen(argv[1],"r");
	fptr1=fopen("output.txt","w");
	
	if(fptr == NULL) {
		printf("Error in file opening.\n");
		return 0;
	}
	
	if(fptr1 == NULL) {
		printf("Error in file opening.\n");
		return 0;
	}
	
	if(!fscanf (fptr, "%d", &maxNode)) {
		
		printf("File is not formated \n");
		return 0;
	}
	//printf("max node %d \n",maxNode);
	
	//scanf("%d %d",&v,&e);
	
	if(!inti_graph(maxNode)){
		printf("Memory Error\n");
		return 0;
	}

	
	while ((fgets(line,sizeof line,fptr) != NULL) ) {  
	
		 if(fscanf (fptr, "%d", &v1)) { 
			 // printf ("node %d ", v1);
			  
		  }  
		  
		 fscanf(fptr,"%d",&space);
		 start = fgetc(fptr);
		 
		 if(fscanf(fptr, "%d", &v2)) { 
			 // printf ("node %d ", v2);
			 
		  }
		
		// printf("\n");
	   
	   create_status = create_graph(v1,v2);
	   
		if(create_status == 0) {
			printf("Memory Error\n");
			return 0;
		}
		else if(create_status == 2) {
			//printf("cycle has detected\nPlese Enter valid vertex.\n");
			fprintf(fptr1,"%d -> %d not added\n",v1,v2);
		}
		else if(create_status == 3) {
			//printf("Edge allready exist.\n");
		}
		else if(create_status == 4){
			printf("Please Enter valid vertex no b/w 1 to %d\n",maxNode);
		}
		else {
			fprintf(fptr1,"%d -> %d added\n",v1,v2);
		}
	   
	 }
	    
	 fclose (fptr);
	 fclose(fptr1);

return 0;
}
