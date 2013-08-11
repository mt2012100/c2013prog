//InsertionSort Sort in desecending order, 

#include<stdio.h>
#include<string.h>

void InsertionSort(int *a, int n) {
	int i=0,j=0;
	int temp = 0;
	
	for(i=1;i<n ;i++) {
		j = i-1;
		temp = a[i];
		while((a[j]>temp) && j>=0) {
			a[j+1] = a[j];
			j--;
		}
		a[++j] = temp;
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
	
	InsertionSort(array,n);
	
	for(i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
return 0;
}
