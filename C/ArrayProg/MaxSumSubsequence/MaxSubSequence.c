/*
 * MaxSubSequence.c
 *
 *  Created on: 06-Nov-2013
 *      Author: pratibind_jha
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

int maxSubArraySequence(int arr[], int n) {

	int i=0,j=0;
	int curSum=0, maxSum=0;

	int var=0;
	for (var = 0; var < n; ++var) {
		curSum += arr[var];
		if(curSum > maxSum) {
			maxSum = curSum;
		}
		if(curSum < 0 ) {
			curSum = 0;
		}
	}

	return maxSum;
}

int main() {
	
	int arrS[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int nS = sizeof(arrS)/sizeof(arrS[0]);
	int maxArraySum = maxSubArraySequence(arrS,nS);

	printf("maximum subarray sum:\t%d\n",maxArraySum);


	return 0;
}
