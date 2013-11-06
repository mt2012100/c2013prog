/*
 * ProductOfArryElement.c
 *
 *  Created on: 06-Nov-2013
 *      Author: pratibind_jha
 *      Description: product of all element except a[i] of a array and store in a array.
				Runtime O(n).
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

int *elementProduct(int array[], int n) {
	int *prodArray = (int*)malloc(sizeof(int)*n);
	memset(prodArray,1,n);

	int var=0;
	int temp=1;
	for (var = 0; var < n; ++var) {
		prodArray[var] = temp;
		temp *= array[var];
	}

	var = n-1;
	temp = 1;
	for (var = n-1; var >=0 ; --var) {
		prodArray[var] *= temp;
		temp *= array[var];
	}


	return prodArray;
}

int main() {
	//int arry[] = {2,5,3,9,13,10,30,21};
	int arry[] = {2,3,4,5};
	int *maxProd;

	int n = sizeof(arry)/sizeof(arry[0]);
	//memset(maxProd,1,n);

	maxProd = elementProduct(arry,n);

	int var=0;
	printf("Product of element except a[i]\n");
	for (var = 0; var < n; ++var) {
			printf("%d\t",maxProd[var]);
	}

	return 0;
}



