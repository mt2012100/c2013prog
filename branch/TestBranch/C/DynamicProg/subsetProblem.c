// the given the element find the subset of that which sum is k

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int max(int x, int y){
    return (x>y)?x:y;
}

int subsetSum(int *a, int n, int k) {
    
    int matx[k+1][n+1];
    int i=0,j=0;
    bool keep[k+1][n+1];
    for(i=0;i<k+1;i++) {
        for(j=0;j<n+1;j++) {
            
            if(i==0 || j==0) 
                matx[i][j] = 0;
            
            else if(i == a[j-1])
                matx[i][j] = 1;

            else if(i > a[j-1] )   {
                matx[i][j] = max(matx[i-a[j-1]][j-1],matx[i][j-1]);
                if(matx[i][j] = matx[i-a[j-1]][j-1])
                    keep[i][j] = 1;
         }        
                
            else
                matx[i][j] = matx[i][j-1];
             
        }
    }
    
   /* for(i=0;i<k+1;i++) {
        for(j=0;j<n+1;j++) {
            printf("%d ",keep[i][j]);
        }
        printf("\n");
    }*/
    
    
    //element in that subset
    printf("Number in subset\n");
    if(matx[k][n]) {
        for(i=n-1;i>=0;i--) {
            if(matx[k][i+1]) {
                printf("%d ",a[i]);
                k = k-a[i];
            }    
        }
        printf("\n");
    }
    
    return matx[k][n];
    
}

int main(int argc, char *argv[]) {
    int a[] = {1,3,5};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 9;
    int val;
    val = subsetSum(a,n,k);
    printf("%d ",val);
    
    return 0;
}
