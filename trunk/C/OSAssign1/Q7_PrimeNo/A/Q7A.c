/*
	Filename		:	Q7A.c
	Description	:	Generate a prime no. up to 10^9.
	Author		:	Pratibind Jha
*/
 //This prog. will store the 0 or 1 in array , 
 //we will access the number by index without storing number.
 //if at particular index values is 1, means that number is eligible 
 //for prime number.
/*Execution time for 10^8 numbers 15.98sec(aprox.).
output.txt file  size=444.4MB*/
//for 10^9 it's giving core dump error in my machine .
//but in some other machine with RAM 2GB or more it's working.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000000

int main(int argc,char *argv[])
{
	FILE *fptr;
	char *Array;
	int 	num;
	int 	index=0;
	int 	i;
	int	positionNumber;

	clock_t start, End;
	double ExecutionTime;
	
	start = clock();

	if((fptr=fopen("output.txt","w")) == NULL) {
		printf("Error occured in file open\n");
		return 0;
	}

	//Checking for if max number is even than descard the all 
	//even number.
	if(MAX%2==0)
		num=(MAX/2)-1;
	else
		num=(MAX-1)/2;
		
	//create a character array 
	Array = (char*)malloc(sizeof(char)*num); 
	
	//store the char 1 in Array.
	for(index=0;index<num;index++) {
		Array[index]='1';
	}
	//sieve Algorithm.
	do {
		//checking for index which is set to 1.
		while(Array[index]!='1'&&index<num) {
			index++;
		}
		//if reach at last index come out from loop.
		if(index == num-1)
			break;
		else 
			i=index;
		
		//constructing the position number from index.
		positionNumber=(2*i)+3;
		
		//printf("pos num %d\n",positionNumber);
		//filter the all index which is multiple of any nuumber.
		//Eg. set index 0 to all number which is multiple of 2,
		//similarly for 3. and so on. 
		for(index=i+positionNumber;index<num;index+=positionNumber) {
			Array[index]='0';
		}

		index=i+1;
	}while(i<num);

	//writing all number which index is 1. 
	for(index=0;index<num;index++) {
		if(Array[index]=='1')
		fprintf(fptr,"%d\n",(index*2)+3);
	}
	free(Array);
	fclose(fptr);

	ExecutionTime = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Execution time=%lf",ExecutionTime);

}
