//Driver program
#include "SLinklist.h"

int main(int argc, char *argv[]) {

	int *data, len=0,i=0,status=0;
	node *hrf;
	if(argc <= 1) {
		printf("Please Enter file name from commandline argument");
		exit(0);
	}
	
	len = fileLength(argv[1]);
	//printf("length %d \n",len);
	if(!len) {
			printf("There is memory error in  file opeartion\n");
			exit(0);
		}	
		
	data = readData(argv[1]);	
	
	if(!data) {
			printf("There is memory erro in reading\n");
			exit(0);
	}	
		
	initLinkList();
	
	//printf("Data\n");
	//insert the data at begning.

	for(;i<len;i++) {
		head = insert(head,data[i],0);
		
		//printf("%d ",data[i]);
		
		
		if(!head) {
			printf("There is error in memory creation\n");
			exit(0);
		}	
	}
	
	printf("\n");
	
	printf("Node before Deletion\n");
	displayNode(head);
	printf("\n");
	
	printf("Node after Deletion\n");
	Delete(head,19);
	displayNode(head);
	printf("\n");
	
	printf("Node again insert\n");
	head = insert(head,99,0);
	displayNode(head);
	printf("\n");
	return 0;
} 
