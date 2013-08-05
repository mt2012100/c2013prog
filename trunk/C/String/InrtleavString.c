// All interleaved string which can be formed from two string.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//print all interleaved String.
void InterleavedString(char *s1, char *s2, char *str, int s1Len, int s2Len, int i) {
	
	if(s1Len==0 && s2Len==0) {
		printf("%s\n",str);
	}
	
	if(s1Len) {
		str[i] = s1[0];
		InterleavedString(s1+1,s2,str,s1Len-1,s2Len,i+1);
	}
	
	if(s2Len) {
		str[i] = s2[0];
		InterleavedString(s1,s2+1,str,s1Len,s2Len-1,i+1);
	}
}

//combination of the string
void combination(int depth, char *str, int start, char *ComArray) {
	
	int length = srelen(str);
	int i;
	for(i=start; i<length; i++) {
		ComArray[depth++] = str[i];
		ComArray[depth] = '\0';
		printf("%c ",combination);		
	}
	if(i<length-1)
		combination(depth+1,combination,start+1,ComArray);
}

int main() {
	char *str1 = "ABE";
	char *str2 = "CD";
	char *str,*comStr;
	int len1,len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	str = (char *)malloc((len1+len2+1)*sizeof(char));
	comStr = (char *)malloc(pow(2,len1)*sizeof(char));
	InterleavedString(str1,str2,str,len1,len2,0);
	printf("\nCombination od String\n");
	combination(0,str1,0,comStr);
return 0;
}
