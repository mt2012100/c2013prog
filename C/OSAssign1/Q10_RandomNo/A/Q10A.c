/*
	Filename 		:	Q10A.c
	Description	:	Generate a random number using getpid() and gettimeofday().
	Author		:	Pratibind Jha
	Date			:	9 Jan 2012
*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<signal.h>

int GenerateRandomNum() {
	
	struct timeval tv;
	int time_s,time_us;
	int pid,randomNum,j;
    
	for(j=0;j<1000000;++j){}
	gettimeofday(&tv, NULL);
	//Here is that the seed will repeat every 24 days or so.
	srand((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	pid = (int)getpid();
	//printf("pid id %d\n",pid);
	time_s = (int) (tv.tv_sec);

	time_us = (int)(tv.tv_usec);

	randomNum = (time_us)%pid;
	//kill(pid,SIGQUIT);
	
return randomNum;
	
}
	 
int main(){

	int index,N,random;
	FILE *fptr;
	 
	N=50;
	
	fptr = fopen("data.txt","w");
	
	if(fptr == NULL) {
	 	printf("Error occurs in file open");
	 	return 0;
	}
	 
	for(index=0;index<N;index++){
	
		//sleep(1);
		
		random = GenerateRandomNum();

		fprintf(fptr,"%d ",random);
	}
	 
	fclose(fptr);
return 1;
}
	
	
