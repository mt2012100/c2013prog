#include <stdio.h>
#include<stdlib.h>
#include<math.h>

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
	
	for(;i<sqrt(high+1);i++) {
		
		if(arr[i]-'0' == 1) {
			int count = 0;
			
		//	if(i >= low)
				//printf("%d ",i);
			int tmp = i*i;	
			int j = 0;
			for( j=tmp;j<high+1;j=tmp+count*i) {
				arr[j] = '0';
				count++;
			}
		}
		
	}
	
	for(index=2;index<high+1;index++) {
		if(arr[index]-'0' == 1) {
			printf("%d ",index);
		}
	}
	/*if(arr[1]-'0' == 1)
		printf("true");
	printf("%d ",arr[1]);
	*/
	
	
}

int main(void) {
	// your code goes here
	printPrime(9,100);
	return 0;
}
