//count the no of set bit(1) .

#include<stdio.h>
int main() {
    unsigned int v=10; // count the number of bits set in v
    unsigned int c; // c accumulates the total bits set in v
    
    for (c = 0; v; c++)
    {
      v &= v - 1; // clear the least significant bit set
    }
    
    printf("%u\n",c);
    return 0;
}
