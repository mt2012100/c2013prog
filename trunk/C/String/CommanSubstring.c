/* Dynamic Programming solution to find length of the longest common substring */

/*
LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]
                        0  Otherwise (if X[m-1] != Y[n-1])

*/

//for longest comman polindrom 1st input will be same as LCsubStr and second input would be 
// reverse of 1st input.
#include<stdio.h>
#include<string.h>

 
// A utility function to find maximum of two integers
int max(int a, int b)
{   return (a > b)? a : b; }
 
/* Returns length of longest common substring of X[0..m-1] and Y[0..n-1] */
int LCSubStr(char *X, char *Y, int m, int n)
{
    // Create a table to store lengths of longest common suffixes of
    // substrings.   Notethat LCSuff[i][j] contains length of longest
    // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
    // first column entries have no logical meaning, they are used only
    // for simplicity of program
    int LCSuff[m+1][n+1],i,j;
    int result = 0;  // To store length of the longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
    for ( i=0; i<=m; i++)
    {
        for ( j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}
 
/* Driver program to test above function */
int main()
{
    //char X[] = "OldSite:GeeksforGeeks.org";
    //char Y[] = "NewSite:GeeksQuiz.com";
    
    char X[] = "abbcacb";
    char Y[] = "bcacbba";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    printf( "Length of Longest Common Substring is  %d\n", LCSubStr(X, Y, m, n));
    return 0;
}
