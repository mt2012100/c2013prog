#include<stdio.h>
#include<string.h>

//Question 1
/*int main() {
    char *s = "Alice";
    int len = strlen(s);
    int i=0;
    for(;i<= len;i++) {
        
        printf("%s ",s);
        s++;
        
    }
    
    return 0;
}*/

//output: Alice lice ice ce c

//Question 2.
/*

int main() {
    char *s = "%d\n";
    int i=9;
    s++;
    s++;
    printf(s-2,i);
    
return 0;
}
*/

//output: 9

//Question 3

/*
int main() {
    char *s = "%d\nRST";
    int i=9;
    s++;
    s++;
    printf(s);
    
return 0;
}
*/
//output: RST

//Question 4
/*
int main() {
  char t='a';
  printf("%d %d %d %d\n",sizeof(""),sizeof("A"),sizeof('a'),sizeof(t));
  return 0;
}
*/
//output: 1 2 4 1 reason: '' is treated as string so sizeof operator return pointer size. where as "" treated as array of character
//including \0 so "A" return 2 byte. 

/*
# include<stdio.h>
int main(){
 int arr[] = {97, 98, 99, 100, 101, 102, 103, 104};
int *ptr = arr+1;
print(++ptr, ptr--, ptr, ptr++, ++ptr);
return 0;
}

print(int *a, int *b, int *c, int *d, int *e)
{
printf("%d %d %d %d %d\n", *a, *b, *c, *d, *e);
}
*/
//output: 100 100 100 99 100 , no reasion
