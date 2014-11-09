//convert Binary no to hexadecimal no

 #include<stdio.h>
void BinrayToHex(){
   
    long int binaryNumber,hexadecimalNumber=0,j=1,remainder;
   
    printf("Enter any number any binary number: ");
    scanf("%ld",&binaryNumber);
   
    while(binaryNumber!=0){
    remainder=binaryNumber%10;
    hexadecimalNumber=hexadecimalNumber+remainder*j;
        j=j*2;
        binaryNumber=binaryNumber/10;
      }
   
    printf("Equivalent hexadecimal value: %lX",hexadecimalNumber);

    
}

//Sample output:

//Enter any number any binary number: 1101
//Equivalent hexadecimal value: D

// convert large binary number to hexadecimal

#include<stdio.h>
#define MAX 1000

int main(){

   char binaryNumber[MAX],hexaDecimal[MAX];
   int temp;
   long int i=0,j=0;
  
   printf("Enter any number any binary number: ");
   scanf("%s",binaryNumber);

   while(binaryNumber[i]){
      binaryNumber[i] = binaryNumber[i] -48;
      ++i;
   }

   --i;
   while(i-2>=0){
       temp =  binaryNumber[i-3] *8 + binaryNumber[i-2] *4 +  binaryNumber[i-1] *2 + binaryNumber[i] ;
       if(temp > 9)
            hexaDecimal[j++] = temp + 55;
       else
            hexaDecimal[j++] = temp + 48;
       i=i-4;
   }

   if(i ==1)
      hexaDecimal[j] = binaryNumber[i-1] *2 + binaryNumber[i] + 48 ;
   else if(i==0)
      hexaDecimal[j] =  binaryNumber[i] + 48 ;
    else
      --j;

   printf("Equivalent hexadecimal value: ");
   while(j>=0){
      printf("%c",hexaDecimal[j--]);
   }

	//BinaryToHex();

   return 0;
}

/*
 Sample output:

Enter any number any binary number: 1010011011100011110
001001111011110001000100011101110111011110
Equivalent hexadecimal value: 14DC789EF111DDDE
*/
