
//find the position of set bit if number binary formate is all 0 except of one 1.

#include <stdio.h>

int pos(int n) {
	int i,j;
	int count=0;
	while(n>0) {
		
		n = n >> 1;
		count++;
	}
	return count;
}

int main(void) {
	// your code goes here
	printf("%d\t",pos(16));
	printf("%d\t",pos(8));
	return 0;
} 
