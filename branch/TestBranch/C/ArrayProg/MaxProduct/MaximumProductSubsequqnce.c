/*
 * MaximumProductSubsequqnce.c
 *
 *  Created on: 06-Nov-2013
 *      Author: pratibind_jha
 *  Given an array that contains both positive and negative integers,
 *  find the product of the maximum product subarray.
 *  Expected Time complexity is O(n) and only O(1) extra space can be used.
 */


/*
 * Algorithm:
 * 1. Find the index of zero,
 * if index is >=0
 * than find max among 0,index-1  and index+1, high
 * else
 * 1. Count the number of -ve no.
 * 2.  if count%2 == 0
 * 			multiply all element.
 * 		else
 * 			multiply all element till last -ve from begning.
 * 			multiply all element till last -ve from last.
 * 			now find maximum among them.
 */


#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int max(int x,int y) {
	return (x>y)?x:y;
}

int zeroIndex(int array[], int low, int high) {
	int index=-1;
	int var=0;
	for (var = low; var <= high; ++var) {
		if(array[var] == 0) {
			return var;
		}
	}
	return index;
}

int MaximumProductSubsequqnce(int arry[],int low, int high) {


	int zero_index = zeroIndex(arry, low, high);
	int leftMax=0,rightMax=0;

	if(zero_index != -1) {

		if(zero_index-1 >= low)
			leftMax = MaximumProductSubsequqnce(arry,low, zero_index-1);
			//printf("maxLeft %d\n",leftMax);

		if(zero_index+1 <= high)
			rightMax = MaximumProductSubsequqnce(arry, zero_index+1,high);

		return max(leftMax, rightMax);
	}

//	count the no of -ve
	int negCount=0;

	int var=0;

	for (var = low; var <= high; ++var) {
		if(arry[var] < 0)
			negCount++;
	}

	int maxMul=1;
	int count=0;
	if(negCount%2 == 0)  { // Multiply all number
		for (var = low; var <= high; ++var) {
			maxMul *= arry[var];
		}
		return maxMul;
	}

	else {
		int leftMul=1, rightMul=1;
		for (var = low; var <= high; ++var) {
			if(arry[var] < 0)
				count++;

			if(count == negCount)
					break;

			leftMul *= arry[var];

		}
		count = 0;
		for (var = high; var >= low; --var) {

			if(arry[var] < 0)
				count++;

			if(count == negCount)
					break;

			rightMul *= arry[var];

		}

		return max(leftMul,rightMul);

	}

}

int main() {

	//int arr[] = {2 ,5, -6 ,7 ,-7 ,23, -9, 0 ,12, -8 };
	int arr[] = {0,2 ,5,-2, 7, -8, 9,-2,12,0,60,0,0};

	int high = sizeof(arr)/sizeof(arr[0]);
	int maxArryProd = MaximumProductSubsequqnce(arr,0,high-1);

	printf("Maximum subarray product is\t %d\n",maxArryProd);

	return 0;
}


