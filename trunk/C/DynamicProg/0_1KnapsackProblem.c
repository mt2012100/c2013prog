#include<stdbool.h>
int knapsack(int * weight, int * values, int w, int n);
int max(int a, int b);
int main()
{
    int weight[] = {5,2,3,6};
    int values[] = {3,4,5,6};
    int w = 5;
    int n = sizeof(weight)/sizeof(int);
    printf("\nThe total weight is %d\n", knapsack(weight, values, w, n));
}
int knapsack(int * weight, int * values, int w, int n)
{
    int i, j;
    int k[n+1][w+1];
    bool keep[n+1][w+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=w;j++)
            keep[i][j] = 0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                k[i][j] = 0;
            else if(weight[i-1]<=w)
            {
                k[i][j] = max(k[i-1][j-weight[i-1]] + values[i-1], k[i-1][j]);
                if(k[i][j] == k[i-1][j-weight[i-1]] + values[i-1])
                    keep[i][j] = 1;
            }
            else
                k[i][j] = k[i-1][j];   
        }
    }
    j = w;
    printf("The weight of the items which fills the knapsack are\n");
    for(i = n;i>=1;i--)
    {
        if(keep[i][j] == 1)
        {
            printf("%d  ",weight[i]);
            j = j - weight[i-1];
        }  
    }
    return k[n][w];
}
int max(int a, int b)
{
    return ((a>b)?a:b); 
}
