/******
File Name		:	Q2B.c
Description	:	probablity of retriving the item will be more whose weight is max.
Created Date	:	7 jan 2013
Author		:	Pratibind Jha 

******/
#include<stdio.h>
#include<stdlib.h>

int WeightDistb[1024];
int items[1024];
int itemWeight[1024];

int totalElement;
int items_index=0;
int weight_index=0;
int weightDist_index=0;


//draw a element from sample of data.
int probDrawElement() {
	int index,item;
	FILE *fptr;
	//printf("totalelement %d ",totalElement);
	srand((unsigned)time ( NULL ));
	index = rand()%totalElement;
	//printf("index %d ",index);
	item = WeightDistb[index];
	//printf("element %d ",item);
	if((fptr = fopen("output.txt","w")) == NULL ) {
		//printf("Error");
		return 0;
	}
	fprintf(fptr,"%d ",item);
	fclose(fptr);
	return 1;
	
}

//randomly distribute the item a/c weight.
int weightDistribution(int totalItems) {
	int index,index1,index2,totalWeight=0;
	int item,weight,count;
	int temp;
	
	srand((unsigned)time ( NULL ));
	
	for(index=0;index<totalItems;index++) {
		totalWeight = totalWeight + itemWeight[index];
	}	
	totalElement = totalWeight;
	count=0;
	//puting the item into array in uniform order redundantly to weight
	for(index=0;index<totalItems;index++) {
		weight = itemWeight[index];
		item = items[index];
		for(index1=0;index1<weight;index1++) {
			WeightDistb[count++] = item;
		}
	}

	//making the distribution random.
	for(index=0;index<(totalWeight/2);index++) {
		index1 = rand()% totalWeight ;
		index2 = rand()% totalWeight ;
		temp = WeightDistb[index1];
		WeightDistb[index1] = WeightDistb[index2];
		WeightDistb[index2]  = temp;
		
	}
	
	/*for(index=0;index<count;index++) {
		printf("%d ",WeightDistb[index]);
	}*/
	return 1;
}//End weightDistribution()

int main(int argc , char *argv[]) {
	FILE *fptr;
	int start=0;
	int data,item,weight,space,count=1;
	char line[256];
	
	if(argc < 2 ) {
		printf("Please Enter the filename using command Line argument.\n");
		return 0;
		//exit 1;
	}
	
	fptr=fopen(argv[1],"r");
	
	if(fptr == NULL) {
		printf("Error in file opening.");
		return 0;
	}
	
	if(!fscanf (fptr, "%d", &data)) {
		//printf("%d \n",data);
		printf("File is not formated \n");
		return 0;
	}
	 
	while ((fgets(line,sizeof line,fptr) != NULL) && (count <= data))
	    {  
	
		 if(fscanf (fptr, "%d", &item)) { 
			  //printf ("item %d ", item);
			  items[items_index++] = item;
			  
		  }  
		  
		 fscanf(fptr,"%d",&space);
		 start = fgetc(fptr);
		 
		 if(fscanf(fptr, "%d", &weight)) { 
			 // printf ("weight %d ", weight);
			 itemWeight[weight_index++] = weight;
		  }
		  
		  count++;
		  
		 // printf("\n");
	   
	    }
	    
	  fclose (fptr);
	  
	//  printf("%d ",data);
	/*  printf("\n"); 
	for(start=0;start<data;start++) {
		printf("%d ",items[start]);
	}
	printf("\n"); 
	for(start=0;start<data;start++) {
		printf("%d ",itemWeight[start]);
	}*/
	
	if(weightDistribution(data)) {

		if(!probDrawElement()) {
			printf("Error occurs in file opening");
			return 0;
		}
		printf("Element has drawn successfuly\n");
	}
	
	return 1;
}//End main().
