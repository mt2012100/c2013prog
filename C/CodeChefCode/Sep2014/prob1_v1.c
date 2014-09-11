#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//calculate power
float power(float x, int y)
{
float temp;
if( y == 0)
return 1;
temp = power(x, y/2);
if (y%2 == 0)
return temp*temp;
else
{
if(y > 0)
return x*temp*temp;
else
return (temp*temp)/x;
}
}

//get final lable of node
void getLabel(char str[],int len)
{
	int array_index=0;
	int i = 0;
	int j = 0;
	for(i=1;i<=len;i++)
	{
	if(str[j++] == 'l')
		array_index = 2*array_index+1;
	else
		array_index = 2*array_index+2;
	}
	
	int val = array_index;
	//find n such that 1+2^1 + 2^2....+2^n > val
	int sum=0;
	j = 0;
	float exp; 
	while(sum <= val)
	{
	exp = power(2.0,j);
	sum += exp;
	j++;
	}
	
	int N = j-1;
	
	int offset = val - (sum-exp)+1;
	
	int a;
	int num_element=0;
	int count=0;
	int final_label = 0;
	//if length is even than we consider final label lies in odd level.
	if(len%2 == 0)
	{
	//iseven = 0;
	//so index of element lies in odd row
	a = 1;
	
	for(i=0;i<len;i=i+2)
	{
		count++;
	//num_element += power(2,i);
	}
	//a(r^n+1 - 1)/(r-1)
	num_element = (a * (power(4,count)-1))/(3);
	num_element += offset;
	final_label = a+(num_element-1)*2;
	}
	else
	{
	a = 2;
	count = 0;
	for(i=1;i<len;i=i+2)
	{
		count++;
//	num_element += power(2,i);
	}
	num_element = (a * (power(4,count)-1))/(3);
	num_element += offset;
	final_label = a+(num_element-1)*2;
	}
	
	printf("%d\n",final_label);
	
}

int main(void) {
// your code goes here
char *str;

int T;
scanf("%d",&T);
int i=0;
int len = 0;
for(i=0;i<T;i++)
{
	//fgets(str, 100000, stdin);
	str = (char*)malloc(sizeof(char)*100000);
	scanf("%s",str);
	len = strlen(str);	
	getLabel(str,len);
	free(str);
}

return 0;
}


