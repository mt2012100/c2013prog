//find the longest comman subsequence
#include<stdio.h>
#include<string.h>
//find maximum of two element
int max(int x, int y) {
    return (x>y?x:y);
}
int LCS_Sequence(char *str1, char *str2, int n, int m) {
	int lcs[n+1][m+1];
	int i=0,j=0;
	for(;i<n+1;i++) {
		for(;j<m+1;j++) {
			lcs[i][j] = 0;
		}
	}
	
	for(i=0;i<n+1;i++) {
		for(j=0;j<m+1;j++) {
		
			if(i==0 || j==0) {
				lcs[i][j] = 0;
			}
			else if(str1[i-1] == str2[j-1]) {
				lcs[i][j] = 1+lcs[i-1][j-1];
			}
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	
	return lcs[n][m];
}

/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", LCS_Sequence( X, Y, m, n ) );
  
  return 0;
}
