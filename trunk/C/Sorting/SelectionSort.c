//InsertionSort Sort in desecending order, 

#include<stdio.h>
#include<string.h>

void SelectionSort(int *a, int n) {
	int i=0,j=0;
	int temp = 0;
	int min = 0;
	for(i=1;i<n-1 ;i++) {
		min = i;
		for(j=i+1;j<n;j++) {
			
			if(a[j] < a[i]) {
				min = j;
			}
		}
		if(min != i) {
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
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
	
	SelectionSort(array,n);
	
	for(i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
return 0;
}
