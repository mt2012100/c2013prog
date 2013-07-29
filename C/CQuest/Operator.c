#include<stdio.h>

/*int main() {
	int i=4,x;
	x =++i + ++i + ++i;
	printf("%d ",x);
return 0;
}*/

//output: 19 //output is very un predictable.

// I think logic lies here
 /*pre increment operator evaluate from  left to right.
 so first right 6+6 =12,
 now 7+12 =19. 
 
 */
 
 
 /*
 int main()
	{
	int x,i=4;
	x= ++i + ++i + i + ++i;
	printf(" %d %d ", x,i); 
	return 0;
}
 
*/
//output 25.
//explanation: expression evaluate from left to right and ++i + ++i will evaluate first so i=6 and evaluated exp. will be 12 now 
// 12 +6=18, now 18+7=25.

/*
	int main()
	{
	int x,i=2;
	if(i==2) {
	    i=~i+2<<1;
	    printf("%d  ",i);
	    
	}

	return 0;
}
*/

//output: -2;  expln: ~2=-3 and -3+2=-1, -1<<1, -2.

/*
	int main()
	{
	int x,a=10;
	printf("%d %d %d",a,a++,++a);

	return 0;
	}
*/
//output: 12 11 12, expln: in stack , argument from right will push, so while printing ++a , or a will print updated values where as a++ will print values of a before ++ operation.
// stack:a=10: values of a =11, a=11: val of a=12, a : val =12.

/*
	#define SIZEOF(arr) (sizeof(arr)/sizeof(arr[0]))

	#define PrintInt(expr) printf("%s:%d\n",#expr,(expr))
	int main()
	{
		//The powers of 10 
	int pot[] = {
	0001,
	0010,
	0100,
	1000
	};
	int i;

	for(i=0;i<SIZEOF(pot);i++)
	    PrintInt(pot[i]);
	return 0;
	}
*/
//output: 1 8 64 1000 /// strainge output.
