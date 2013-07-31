#include<string.h>
#include<stdio.h>

int main() {
int i,j,a,b,c,d;
	i=printf("thisisc");

	printf("%d",i); //i=7

	j=scanf("%d%d%d%d",&a,&b,&c,&d);

	printf("%d",j); 
return 0;
}

//output: printf: 7 scanf: 4 so final output: thisisc74
