//Search the element given that odd element is at odd position and even element is at even place.

#include<stdio.h>
#include<string.h>
//flag 0 for even  and 1 for odd .
int searchElement(int *a, int low , int high, int data, int flag) {
	int mid;
	if(high< low) {
		printf("Data not found\n");
		return 0;
	}	
	if(low == high) {
		if(data == a[low]) {
			printf("Data found\n");
			return 1;
		}	
		else{
			printf("Data Not found\n");	
			return 0;
		}
	}
	
	mid = (low+high)/2;
	
	if(!flag) {
		if(mid%2 != 0) {
			mid = mid-1;
		}
	}
	else{
		if(mid%2 == 0) {
			mid = mid-1;
		}
	}
	
	if(a[mid] == data) {
		printf("Data found\n");
		return 1;
	}
	else if(data > a[mid]){
		searchElement(a, mid+2, high,data,flag);
	}
	else if(data < a[mid] ) {
		searchElement(a, low, mid-2,data,flag);
	}
	
}

int main() {
	int array[] ={2,5,6,7,16,15,18,19,20,677,678};
	int i;
	i = searchElement(array,0,10,677,1);

return 0;
}
