/* File: mutex.c
      Description: A very primitive implementation of mutual exclusion API
* Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
 */

#include <stdio.h>
#include "mutex.h"

#define SLEEP_TIME 5

/* Locks the given file descriptor.
     Return 0 on success, 1 on failure (in case of invalid file descriptor or mode)
*/

/* A helper function to extract the basename of the given file name */
/* Basename is that part of the name that excludes the file extension */
/* If there is no extension in the name, then the basename is same as the file name */
/* This will work only if there is no path included in the file name */

int get_basename( char *file_name, char *base_name )
{
	char *dot_location;
	
	/* Add error handling */
	if( file_name == NULL || base_name == NULL )
		return 1;

	char* pos=strstr(file_name,".");
     if(pos==NULL)
{      strcpy(base_name,file_name);
	return 0;
}	/* ADD MISSING CODE HERE */
	/* Store the initial part of the file_name string upto 
	 * the first dot(.) base_name string 
	 */
else{
      while(*file_name!='\0' && file_name!=pos)
       {
        *base_name++=*file_name++;
        }
}
*base_name='\0';
	return 0;
}

/* Finds the type of lock that is existing on the given file */
/* 	Returns process id of the process that has established the lock
	Returns -1 if there is no lock on the file
*/
int mutex_check_lock( char *file_name )
{
	char lock_file_name[100];
	int lock_PID;
	int status;
	FILE *fp;
	
	status = get_basename( file_name, lock_file_name );
	if( status != 0 )
		return -1;

	strcat( lock_file_name, ".lock" );
	
	fp = fopen(lock_file_name, "r");
	if( fp == NULL ){
		return -1;
	}
	else{
		fscanf( fp, "%d", &lock_PID );
		fclose(fp);
		return lock_PID;
	}
}

/* A local helper function to create a lock file with the current process ID
	Returns 0 on success and 1 on failure
*/

int create_lock_file( char *file_name )
{
	FILE *fp;
	int status;
	char lock_file_name[100];
	int PID;
	
	PID = getpid();
	
	status = get_basename( file_name, lock_file_name );
	if( status != 0 )
		return 1;

	/* ADD MISSING CODE HERE */
	/* Create the lock file and store the PID of the process 
	 * inside the lock file using fprintf 
	 */


	
	return status;
}

/* Removes the lock file only if the lock file is owned by the current process */
/* Returns 0 on SUCCESS and 1 on FAILURE */

int remove_lock_file( char *file_name )
{
	FILE *fp;
	int status;
	char lock_file_name[100];
	int lock_PID;

	lock_PID = mutex_check_lock( file_name );
	
	/* ADD MISSING CODE HERE */
	/* Remove the lock on if the lock is owned by the current process */
	/* Have to compare the PID present in the lock file with 
	 *  the PID of the current process 
	 * If they are the same, then just remove the lock file using 
	 * the remove(filename) function 
	 */

	
	
	
	
}

/* Return 0 on SUCCESS and 1 on FAILURE  */

int mutex_lock( char *file_name )
{
	char lock_file_name[100];
	/* Status of acquiring lock */
	int done = 0;
	int status;
	int lock_PID, lock_condition;
	
	while( !done ){
		printf("Trying to acquire lock....\n");
		lock_PID = mutex_check_lock( file_name );
	
		/* ADD MISSING CODE HERE */
		/* Find value of lock_condition: it should be 
		 * 0 if no lock exists; 
		 * 1 if lock is owned by a process, check using value of Process ID
		 * 2, otherwise.
		 */
		lock_condition = ;
		if( lock_condition == 0 ){
			/* ADD MISSING CODE HERE */
			/*  No lock exists... so create lock */
		        /* Set status and assign value for done */

		}
		else if( lock_condition == 1 ){
			/* Lock already exists and is owned by the current process */
			/* Nothing to do since the current process already owns the lock */
		  done = 1 ;

		}
		else{
			/* ADD MISSING CODE HERE */
			/* Some other process has the lock... need to wait */
		        /* Set the process to wait and assign value of done */

			printf("Waiting to lock....going to sleep for %d seconds\n", 
			       SLEEP_TIME);
		}
	}
	return 0;
}


/* Releases the lock on the given file      
 * Return 0 on success, 1 on failure
*/
int mutex_unlock( char *file_name )
{
	return remove_lock_file( file_name );
}

/* Read with mutex semantics */
/* Will always read from the beginning of the file only */
/* A wrapper around fread */
int mread( void *ptr, size_t size, size_t count, char* file_name )
{
	int status;
	int lock_PID;
	FILE *fp;
	
	lock_PID = mutex_check_lock( file_name );

	/* Read function should proceed only if the current process owns the lock on the file */
	if( /* ADD MISSING CODE HERE */ ){
		fp = fopen(file_name, "r");
		if( fp == NULL ){
			perror("Unable to read data from file\n");
			return -1;
		}
		else{
		  return fread( /* ADD MISSING CODE HERE */ );
		}
	}
	else{
		perror("Current process does not own the lock");
		return -1;
	}
}

/* Write with mutex semantics */
/* A wrapper around fwrite */
/* Will always write at the end of the file (append) only */

size_t mwrite ( const void * ptr, size_t size, size_t count, char* file_name )
{
	int status;
	int lock_PID;
	FILE *fp;
	
	lock_PID = mutex_check_lock( file_name );

	/* Read function should proceed only if the current process owns the lock on the file */
	if( /* ADD MISSING CODE HERE */ ){
		/* Will always write at the end of the file (append) only */
		/* ADD MISSING CODE HERE */
	        /* Assign value for fp */
	        fp = ;
		if( fp == NULL ){
			perror("Unable to write data to file\n");
			return -1;
		}
		else{
		        return fwrite( /* ADD MISSING CODE HERE */ );
		}
	}
	else{
		perror("Current process does not own the lock");
		return -1;
	}
}
