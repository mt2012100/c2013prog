#include <stdio.h>
#include<stdlib.h>

//print all prime number between low and high , including them
void printPrime(int low, int high) {
	
	if(high == 1)
		return;
	if(low > high)
		return;
	char *arr = (char*)malloc(sizeof(char)*(high+1));
	int index=0;
	
	arr[0] = '0';
	arr[1] = '0';
	
	for(index=2;index<high+1;index++) {
		arr[index] = '1';
	}
	
	
	int i=2;
	
	for(;i<high+1;i++) {
		
		if(arr[i]-'0' == 1) {
			int count = 2;
			
			if(i >= low)
				printf("%d ",i);
				
			int j = 0;
			for( j=2*i;j<high+1;j=count*i) {
				arr[j] = '0';
				count++;
			}
		}
		
	}
	/*if(arr[1]-'0' == 1)
		printf("true");
	printf("%d ",arr[1]);
	*/
	
	
}

int main(void) {
	// your code goes here
	printPrime(999000000,1000000000);
	return 0;
}
