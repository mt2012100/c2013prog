//Bubble Sort in desecending order, 

#include<stdio.h>
#include<string.h>

void bubbleSort(int *a, int n) {
	int i=0,j=0;
	int temp = 0;
	int swap = 1;
	for(i=0;(i<n-1 && swap) ;i++) {
		swap = 0;
		for(j=0;j<n-1-i;j++) {
		
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swap = 1;
				//printf("Test\n");
			}
		}
	}
	
	
}

//driver program
int main() {
	int array[] = {5,2,9,10,8,90,80,12,17};
	int n = sizeof(array)/sizeof(int);
	printf("Sizeof array %d\n",n);
	int i = 0;
	printf("Values before Sort\n");
	 
	for(;i<n;i++) {
		printf("%d ",array[i]);
	} 
	printf("\nAfter Sort\n");
	
	bubbleSort(array,n);
	
	for(i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
return 0;
}
