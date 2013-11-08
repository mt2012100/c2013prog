
//For given number n , to find the %8 we can use the rxpression: n & 0x7, similarly to find %32, use the expression n & 0x1F.

#include <stdio.h>

int main(void) {
	// your code goes here for 32 modulo.
	int n=34; 
	int t = n & 0x1f;
	printf("%d\t",t);
	return 0;
}
