#include<stdio.h>
#include<string.h>
/*int main() {

return 0
}*/

//Question1.
/*int main() {
    int *p1,i=25;
    void *p2;
    p1=&i;
    p2=&i;
    p1=p2;
    p2=p1;
    return 0;
}*/

//Question2.
/*int main() {
	char a[]="Visual C++";
	char *b="Visual C++";
	printf("\n%d %d",sizeof(a),sizeof(b));
	printf("\n%d %d",sizeof(*a),sizeof(*b));
return 0;
} */

/* output 11 4 and 1 1*/

//Question3
/*int main() {
	int arr[] = {2,3,4,1,6};
	printf("%u %d",arr,sizeof(arr));
	return 0;
}*/

//output: warning, use %p for print pointer or address.

//question 4
/*int main() {
	int arr[] = {12,14,15,23,45};
	printf("%u %u %u",arr+1,&arr,&arr+1);
}*/

//output warning &arr+1 == addr(arr)+1*sizeof(arr);

//Question5
/*int main() {
	char a[]="sunshine";
	char *p="crackdown";
	a="crackdown";
	p="sunshine";
	printf("\n%s %s",a,p);
return 0;	
}*/

//output: error because of incompatible assignment to a in line 46.


//Question 6
/*int main() {
	float a[]={12.4,2.3,4.5,6.7};
	printf("\n %d",sizeof(a)/sizeof(a[2]));
return 0;
}*/

//output: 4 because 16/4.

//Question 7
/*int main() {
	int a[3][4] = {
			1,2,3,4,
			4,3,2,1,
			7,8,9,0
		};
	printf("\n %u %u %u %u",a,a+1,&a,&a+1);	
return 0;
}*/

//Question 8
/*int main() {
    int *p1,i=25;
    void *p2;
    p1=&i;
    p2=&i;
    p1=p2;
    p2=p1;
    p2++;
    printf("\n%p",p2);
    return 0;
}*/

//output : OK

//Question 9: find the missing number from sequence of n number.
/*int main()
{
    int n,tot=0 , mis=0 , sum=0 , i=0,dup=0 , xo=0,xot=1,out=0;
    int *ar;
    printf("enter the number of nos");
    scanf("%d",&n);
    ar=(int*)malloc(sizeof(int)*(n-1));
    
    printf("\n enter the no %d",n);
    dup=0;
    i=0;
    while(dup<n-1)
    {
    scanf("%d",&ar[i]);
    i++;
    dup++;
    }
    printf("\nafter first while i--> %d",i);
    
    i=0;
    while(i<(n-1))
    {
    xo=xo ^ar[i];
    i++;
    }
    printf("\nafter first while xo--> %d",xo);
    i=2;
    while(i <= n)
    {
    xot=xot ^ i;
    i++;
   
    }
    printf("\nafter first while xot--> %d",xot);
    out=xo ^ xot;
    printf("\n\n the missing no is");
    printf("\n %d",out);
    return 0;
}*/

/*input 4
        1 2 4*/
// output 3

//Question 10
/*int main() {
	printf(5 + "fascimile");
return 0;
} */       

//output: mile        

//Question 11:
/*int main() {
	char str1[]="Hello";
	char str2[]="Hello";
	if(str1==str2)
		printf("\nEqual");
	else
		printf("\nNot Equal");	
	printf("\n %c","abcdefg"[4]);//output e.
return 0;
}*/

//output: Not Equal.

//Question 12
/*int main() {
	char str[7] = "Strings";
	printf("%s",str);
	printf("\\n"); // to print \n on screen
return 0;	
}*/

//output: Strings

//Question 13
/*int main() {
	char ch='A';
	printf("\n%d %d",sizeof(ch),sizeof('A'));
return 0;
}*/

//output: 2 4

//Question 14
/*int main() {
	char *str1=(char *)malloc(sizeof(char)*20);
	str1="United";
	char *str2="Front";
	/*char string1[20];
  	char string2[20];
	char *str3;
  	strcpy(string1, "Hello");
  	strcpy(string2, "Hellooo");
	  printf("Returned String : %s\n", strcat( string1, string2 ));
  printf("Concatenated String : %s\n", string1 );*/
/**
	str3=strcat(str1,str2);
	printf("\n%s",strcat(str1,str2));
return 0;
}*/

//Output: seg fault.

//Question: 15
/*int main() {
	char *str[]={"test12","Frog","Newt","right"};
	printf("\n%d %d",sizeof(str),sizeof(str[0]));
return 0;
}*/

//output: 16 4
