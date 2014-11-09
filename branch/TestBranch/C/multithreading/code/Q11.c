/*
Filename 		: 	Q11.c
Description	: 	Bankers Algorithm, resource allocation using pthread .
Author		: 	Pratibind jha
*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
void *resourceRequest(void *i);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int **alloc,**need,**maxClaim;
int *maxRes,*resVector,*complete;
int *executionOrder;
int order=0; //to track the order of execution of process;
int nr,np;
char space;
int count=0;
int main(int argc , char *argv[]) {
	int rc[100];
	int i,j,sum,k=0,turn=0;
	FILE *fptr;
	char msg[150];
	pthread_t *thread;
	
	if(argc < 2 ) {
		printf("Please Enter the filename using command Line argument.");
		return 0;
		//exit 1;
	}
	if((fptr=fopen(argv[1],"r"))== NULL) {
		printf("Error occur in file opening\n");
		return 0;
	}
	if(!fscanf(fptr,"%d",&nr)){
		printf("File is not formated \n");
		return 0;
	}
	printf("Number of resource %d\n",nr);
	
	complete = (int *)malloc(sizeof(int)*np);
	
	//initialize complete vector.
	for(i=0;i<np;i++) {
		complete[i] = 0;
	}
	executionOrder = (int *)malloc(sizeof(int)*np);
	
	//initialize complete vector.
	for(i=1;i<=np;i++) {
		executionOrder[i] = 0;
	}
	
	//Maximum availabe resource.
	printf("max resource\n");
	//while(fgets(line,sizeof line, fptr) != NULL) {
		maxRes =(int *) malloc(sizeof(int)*nr);
		if(maxRes == NULL) {
			printf("Memory in not sufficient\n");
			return 0;
		}
		for(i=0;i<nr;i++) {
			fscanf(fptr,"%d",&maxRes[i]);
			fscanf(fptr,"%c",&space);
			printf("%d\t",maxRes[i]);
		}
	//}
	
	//Resource vector.
	resVector =(int *) malloc(sizeof(int)*nr);
	if(resVector == NULL) {
		printf("Memory in not sufficient\n");
		return 0;
	}
	printf("\nAvailable Resource\n");
	for(i=0;i<nr;i++) {
		fscanf(fptr,"%d",&resVector[i]);
		fscanf(fptr,"%c",&space);
		printf("%d\t",resVector[i]);
	}
	printf("\n");
	
	if(!fscanf(fptr,"%d",&np)){
		printf("File is not formated \n");
		return 0;
	}
	printf("Number of process %d\n",np);
	
	//Resource allocation matrix.
	alloc = (int **)malloc(sizeof(int)*nr*np);
	if(alloc == NULL) {
		printf("Mermory is not sufficient\n");
	}
	
	printf("Allocation matrix\n");
	for(i=0;i<np;i++) {
		alloc[i] = (int *)malloc(sizeof(int)*nr);
		for(j=0;j<nr;j++) {
			fscanf(fptr,"%d",&alloc[i][j]);
			printf("%d\t",alloc[i][j]);
		}	
		printf("\n");
	}
	
	//Maximum resource required or claim.
	//Resource allocation matrix.
	maxClaim = (int **)malloc(sizeof(int)*nr*np);
	if(maxClaim == NULL) {
		printf("Mermory is not sufficient\n");
	}
	
	printf("Maximum resource claim matrix\n");
	for(i=0;i<np;i++) {
		maxClaim[i] = (int *)malloc(sizeof(int)*nr);
		for(j=0;j<nr;j++) {
			fscanf(fptr,"%d",&maxClaim[i][j]);
			printf("%d\t",maxClaim[i][j]);
		}	
		printf("\n");
	}
	fclose(fptr);
	// calculate need matrix.
	need = (int **)malloc(sizeof(int)*nr*np);
	if(need == NULL) {
		printf("Mermory is not sufficient\n");
	}
	
	printf(" resource need matrix\n");
	for(i=0;i<np;i++) {
		sum = 0;
		need[i] = (int *)malloc(sizeof(int)*nr);
		
		for(j=0;j<nr;j++) {
			need[i][j] = maxClaim[i][j]-alloc[i][j];
			printf("%d\t",need[i][j]);
		}	
		printf("\n");
	}
	
	thread = (pthread_t *)malloc(sizeof(pthread_t)*np);
	if(thread == NULL) {
		printf("Memory is insufficient\n");
		return 0;
	}
	
	next:
	for(i=0;i<np;i++) {
		if(complete[i] == 0) {
			if(rc[i]=pthread_create( &thread[i], NULL, resourceRequest,(void *) &i))  {
		     	printf("Thread creation failed: %d\n", rc[i]);
	   		}
   		}
	}
	
	//join the thread.
	
	for(i=0;i<np;i++) {
		pthread_join(thread[i],NULL);
		turn++;
	}
	
	
	k=0;
	for(i=0;i<np;i++) {
		if(complete[i] == 1) {
			k++;
		}
		else if(complete[i]==0 && (turn==(np*np))) {
			printf("The process is not in safe state\n");
			strcpy(msg,"The process is not in safe state");
			printf("Complete vector\n");
			for(i=0;i<np;i++) {
				printf("%d\t",complete[i]);
			}
			//write output to output.txt file.
			fptr= fopen("output.txt","w");
			if(fptr==NULL) {
				printf("Error in file opening in output.txt\n");
			}
			fprintf(fptr,"%d\n",nr);
			fprintf(fptr,"%d\n",np);
			fprintf(fptr,"%s\n",msg);
			for(i=0;i<np;i++) {
				if(executionOrder[i] == 0) {
					fprintf(fptr,"P%s\t","x");
				}
				else {
					fprintf(fptr,"P%d\t",executionOrder[i]);
				}
			} 
			printf("\n");
			printf("Output is written in output.txt successfuly\n");
			fclose(fptr);
			return 0;
		}
		else {
			goto next;
		}
	}
	if(k==np) {
		printf("The process is in safe state\n");
		strcpy(msg,"The process is in safe state");
	}
	printf("Order of execution\n");
	for(i=0;i<np;i++) {
		printf("P%d\t",executionOrder[i]);
	}
	printf("\n");
	fptr= fopen("output.txt","w");
	if(fptr==NULL) {
		printf("Error in file opening in output.txt\n");
	}
	fprintf(fptr,"%d\n",nr);
	fprintf(fptr,"%d\n",np);
	fprintf(fptr,"%s\n",msg);
	for(i=0;i<np;i++) {
		fprintf(fptr,"P%d\t",executionOrder[i]);
	} 
	printf("Complete vector\n");
	for(i=0;i<np;i++) {
		printf("%d\t",complete[i]);
	}
	printf("\n");
	printf("Output is written in output.txt successfuly\n");
	//fprintf(fptr,"%s","mine");
	fclose(fptr);
	free(alloc);
	free(need);
	free(maxClaim);
	free(maxRes);
	free(resVector);
	free(complete);
	//free(msg);
	free(executionOrder);
return 0;
}

void *resourceRequest(void *li) {
	int l,m,counter;
	int pi;
	pi = *(int *)li;
	//printf("pi %d\n ",pi);
	pthread_mutex_lock( &mutex1 );
	counter=0;
	if(complete[pi] == 1) {
		goto Relese;
	}
	for(l=0;l<nr;l++) {
		if(need[pi][l]>resVector[l]) {
			count++;
			complete[pi] = 0;
			break;
		}
		else if(need[pi][l] <= resVector[l]){
			counter++;
		}
	}
	
	if(counter == nr) {
		complete[pi] = 1;
		executionOrder[order++] = pi+1;
		for(l=0;l<nr;l++) {
			resVector[l] = resVector[l] + alloc[pi][l];
		}
	}
	
	Relese: ;
	pthread_mutex_unlock( &mutex1 );	
	pthread_exit((void *)"threadexit");	
}
