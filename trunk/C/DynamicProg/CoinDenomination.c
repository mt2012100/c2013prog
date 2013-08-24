//coin denomination or Coin exchange problem.
//exchange the money with minimum no of coin.

#include<stdio.h>

int min(int x, int y) {
	
	return (x<y)?x:y;
}
int coinDenom(int a[],int size, int m) {
	int table[m+1][size];
	int i=0,j=0;
	
	for(j=0;j<size;j++) {
		table[0][j] = 0;
	}
		
	for( i=1;i<m+1;i++) {
		for(j=0; j<size;j++) {
			
			if(j==0 && (i-a[j] >= 0)) {
				table[i][j] = 1 + table[i-a[j]][j];
			}
			else if(i-a[j] >= 0) {
				table[i][j] = min(1 + table[i-a[j]][j],table[i][j-1]);
			}
			else
				table[i][j] = table[i][j-1];
		}
	}

return table[m][size-1];
}

int main() {
	
	//here denimination value should be in assending order.
	int arr[] = {1 ,7,10};
	int countCoin;
	int size = sizeof(arr)/sizeof(int);
	int money = 56;
	countCoin = coinDenom(arr,size,money);
	printf("Coin values %d \n",countCoin);
return 0;
}
