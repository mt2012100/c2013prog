//merge sort

#include<stdio.h>
#include<string.h>

void  Merge(int *a, int *temp, int start, int mid, int end) {
	int left_end = mid-1;
	int pos=start;
	int left=0, right=0;
	left = start;
	right = mid;
	while((left <= left_end) && (right <= end)) {
		if(a[left] <= a[right]) 
			temp[pos++] = a[left++];
	
		else
			temp[pos++] = a[right++];
		//printf("here\n");		
	}
	
	while(left <= left_end) 
		temp[pos++] = a[left++];

	
	while(right <= end) 
		temp[pos++] = a[right++];
	
	for(pos=start;pos<=end;pos++) {
		a[pos] = temp[pos];
	}
	
}



void MergeSort(int *a, int *temp,int start, int end) {
	int mid;
	mid = (start + end)/2;
	
	if(end > start) {
		
		MergeSort(a,temp, start,mid);
		MergeSort(a,temp,mid+1,end);
		Merge(a,temp,start,mid,end);
	}

}

//driver program
int main() {
	int array[] = {5,2,9,10,8,90,80,12,17};
	int n = sizeof(array)/sizeof(int);
	printf("Sizeof array %d\n",n);
	int i = 0;
	int temp[50];
	printf("Values before Sort\n");
	 
	for(;i<n;i++) {
		printf("%d ",array[i]);
	} 
	printf("\nAfter Sort\n");
	
	MergeSort(array,temp,0,n-1);
	
	for(i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
return 0;
}
