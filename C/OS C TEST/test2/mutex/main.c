#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#include "mutex.h"

int main()
{
	char *filename = "testfile.txt";
	char sample_data[50];
	int count, status;
	int lock_status;
	
	srand( time(NULL) );

	sprintf(sample_data, 
		"This is a sample line written by process with PID %d\n",
		getpid());
	
	lock_status = 0;
	
	for( count = 0; count < 10; count++ ){
		/* Randomly lock and unlock file */
		if( rand() % 100 > 50 ){
			if( lock_status == 0 ){
				printf("Locking the file...\n");
				mutex_lock( filename );
				lock_status = 1;
			}
			else{
				printf("Unocking the file...\n");
				mutex_unlock( filename );
				lock_status = 0;
			}
		}
		/* Write the test string */
		status = mwrite( sample_data, sizeof(sample_data), 1, filename );
		if( status > 0 )
			printf("Write succeeded\n");
		else
			printf("Write failed\n");
		
		/* Sleep for a random period of time */
		
		sleep( rand() % 10 );
	}
	return 0 ;
}
