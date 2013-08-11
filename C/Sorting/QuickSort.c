//QuickSort //

#include<stdio.h>
#include<string.h>

int partition(int *a, int start, int end) {
	int pivot=0;
	int temp;
	int left,right;
	left = start;
	right = end;
	pivot  = a[start];
	
	while(right > left) {
		
		while((a[left] <= pivot) && (left < end))
			left++;
			
		while((a[right] > pivot) && (right > start))
			right--;	
			
		
		if(left < right) {
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}	
			
	}
	
	a[start] = a[right];
	a[right] = pivot;
	return right;

}

void QuickSort(int *a, int low, int high) {

	int patitions = 0;
	
	if( high> low) {
		patitions = partition(a,low, high );
		QuickSort(a,low, patitions-1);
		QuickSort(a,patitions+1, high);
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
	
	QuickSort(array,0,n-1);
	
	for(i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
return 0;
}
