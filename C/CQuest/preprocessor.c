#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
//Including header file does not give error. if it is labrary .h file.

//Qustion 1
/*#define cube(x) (x*x*x)
int main() {
	int a,b=3;
	a=cube(b++);
	//a= b++*b++; //reason: postfix ++ will incrrease the values of b after evaluation of this statement. 
	//a =(b++)+(++b)*b--;//a=4+4*4=20 because ++a will execute first.
	printf("\n%d %d",a,b);
return 0;
}
//output: 27 6

*/

//Question 2
/*#define swap(a,b,c) (c t;t=a,a=b,b=t;)
int main() {
	int x=10,y=20;
	swap(x,y,int);
	printf("%d %d",x,y);
return 0;
}*/

//output: error expected ')' before 't'

//Question 3
#define str(x) #x
#define Xstr(x) str(x)
#define oper multiply
int main() {
	char *opername=Xstr(oper);
	printf("%s",opername);
return 0;
}
