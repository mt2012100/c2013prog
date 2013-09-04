#include<stdio.h>
#include<stdbool.h>
int main() {
    unsigned int v=15;       // word value to compute the parity of
	bool parity = false;  // parity will be the parity of v

	while (v)
	{
	  parity = !parity;
	  v = v & (v - 1);
	}
	printf("Parity %d\n",parity);
return 0;
}
