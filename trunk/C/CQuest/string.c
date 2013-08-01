#include<string.h>
#include<stdio.h>

//Ques 1

int main()
{
	char *p="delhi \"mumbai" "kolkata \\\"channai";
	printf("%s\n",p);
	char *q="jaipur \\\ \"jammu";
	printf("%s",q);
return 0;
}

//output: delhi "mumbaikolkata \"channai
//			jaipur \ "jammu
