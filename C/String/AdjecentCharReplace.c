
//replace the adjecent character of string if both are same.
#include<stdio.h>
#include<string.h>

int main() {
	char ch[] = "ABCCBCBA";
	/*
	char buf[155],str[255];
	printf("enter the string");
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%s",str);
	*/
	int len;
	len = strlen(ch);
	display(ch);
	RemoveAdjecentPair(ch,0,len);
	display(ch);
return 0;
} 

void RemoveAdjecentPair(char *str, int start, int end) {
	
	int i,j=0;
	for(i=1;i<end;i++) {
		
		while(str[j] == str[i] && j>=0) {
			i++;
			j--;
		}
		
		str[++j] = str[i];
	}
	str[++j]='\0';
}

void display(char *str) {

	printf("%s\n", str);

}
