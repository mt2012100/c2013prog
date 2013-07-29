/*
	filename		:	Q5A.c
	Description	:	create a get time function by passing resolution
	Athour		:	Pratibind Jha
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <math.h>

/*
observation : resolution less than -6 is not giving the accurate result 
		because as resolution -n gives the decimal values upto n digit
		like resolution -5 gives decimal values upto 5 digit. 
		as n decrease to -6 the loss of precesion. so it support only upto 
		-6 ie microsecond.
*/
double getTime(int resolution) {
   
    	long double digit,sec;
    	
    	//structure contain sec and usec.
	struct timeval tv;
 	
    if (resolution < 0){
        gettimeofday(&tv, NULL);
 		
 		printf("tv in sec %ld\n",tv.tv_sec);
 		printf("tv in micro sec %ld\n",tv.tv_usec);
 		
 		//sec = tv.tv_sec * pow(10,-resolution);
        
        digit = (int)((double)tv.tv_usec / pow(10,6+resolution));
        digit = digit * pow(10,resolution);
 
        return tv.tv_sec+digit;
 
    } 
    else {
      
        gettimeofday(&tv, NULL);
        
        printf("tv in sec %ld\n",tv.tv_sec);
 	   printf("tv in micro sec %ld\n",tv.tv_usec);
       
       return (long double)tv.tv_sec / pow(10,resolution);
    }
}

int main() {

	double sec,usec;
	int index;
	for(index=1;index<10;index++) {
		usec = getTime(-index);
	printf("For resolution -%d values is %f\n",index,usec);
	}
	
return 0;
}
