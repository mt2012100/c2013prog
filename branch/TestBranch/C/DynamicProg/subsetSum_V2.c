// the given the element find the subset of that which sum is k

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int max(int x, int y){
    return (x>=y)?x:y;
}

int subsetSum(int *a, int n, int k) {
    
    int matx[k+1][n+1];
    int i=0,j=0,sum;
    int keep[k+1][n+1];
    for(i=0;i<k+1;i++){
        for(j=0;j<n+1;j++){
            keep[i][j] = 0;
        }
    }
    
    for(i=0;i<k+1;i++) {
        for(j=0;j<n+1;j++) {
            
            if(i==0 || j==0) 
                matx[i][j] = 0;
            
            else if(i == a[j-1])
                matx[i][j] = 1;

            else if(i > a[j-1] )   {
                matx[i][j] = max(matx[i-a[j-1]][j-1],matx[i][j-1]);
                //printf("%d %d %d\n", i, a[j-1],matx[i][j]);
                if(matx[i][j] == matx[i-a[j-1]][j-1])
                    keep[i][j] = 1;
                else
                    keep[i][j] = 0;
            }        
                
            else
                matx[i][j] = matx[i][j-1];
             
        }
    }
    
    for(i=0;i<k+1;i++) {
        for(j=0;j<n+1;j++) {
            printf("%d ",keep[i][j]);
        }
        printf("\n");
    }
    
    sum = k; 
    //element in that subset
    printf("Number in subset\n");
    if(matx[sum][n]) {
        for(i=n-1;i>=0;i--) {
            if(keep[sum][i+1] == 1) {
                printf("%d ",a[i]);
                sum = sum-a[i];
            }    
        }
        printf("\n");
    }
    
    return matx[k][n];
    
}

int main(int argc, char *argv[]) {
    int a[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 11;
    int val;
    val = subsetSum(a,n,k);
    printf("%d ",val);
    
    return 0;
}
