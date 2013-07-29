/* File: mutex.c
      Description: A very primitive implementation of mutual exclusion API
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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

	dot_location = strstr(file_name, ".");
	
	if( dot_location == NULL ){
		strcpy( base_name, file_name );
		return 0;
	}
	else{
		while( *file_name != '\0' && file_name != dot_location ){
				*base_name++ = *file_name++;
		}
	}
	*base_name = '\0';
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

	strcat( lock_file_name, ".lock" );
	fp = fopen( lock_file_name, "w" );
	if( fp == NULL ){
		perror("Unable to create lock file");
		status = 1;
	}
	else{
		fprintf(fp, "%d\n", PID);
		status = 0;
		fclose(fp);
	}
	return status;
}

/* Removes the lock file only if the lock file is owned by the current process */

int remove_lock_file( char *file_name )
{
	int status;
	char lock_file_name[100];
	int lock_PID;

	lock_PID = mutex_check_lock( file_name );
	
	/* Remove the lock on if the lock is owned by the current process */
	/* Have to compare the PID present in the lock file with the PID of the current process */
	/* If they are the same, then just remove the lock file using the remove(filename) function */
	if( lock_PID >= 0 && lock_PID == getpid() ){
		status = get_basename( file_name, lock_file_name );
		if( status != 0 ){
			perror("Unable to extract basename\n");
			return 1;
		}
		strcat( lock_file_name, ".lock" );
		status = remove( lock_file_name );
		if( status == -1 ){
			perror("Unable to remove lock file");
			return 1;
		}
		return 0;
	}
	else
		return 1;
}

/* Return 0 on SUCCESS and 1 on FAILURE  */

int mutex_lock( char *file_name )
{
	int done = 0;
	int status;
	int lock_PID;
	
	while( !done ){
		printf("Trying to acquire lock....\n");
		lock_PID = mutex_check_lock( file_name );
	
		if( lock_PID == -1){
			/*  No lock exists... so create lock */
			status = create_lock_file( file_name );
			done = 1;
		}
		else if( lock_PID == getpid() ){
			/* Lock already exists and is owned by the current process */
			/* Nothing to do since the current process already owns the lock */
			done = 1;
		}
		else{
			/* Some other process has the lock... need to wait */
			printf("Waiting to lock....going to sleep for %d seconds\n", SLEEP_TIME);
			sleep(SLEEP_TIME);
			done = 0;
		}
	}
	return 0;
}


/* Releases the lock on the given file      Return 0 on success, 1 on failure
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
	int lock_PID;
	FILE *fp;
	
	lock_PID = mutex_check_lock( file_name );

	/* Read function should proceed only if the current process owns the lock on the file */
	if( lock_PID == getpid() ){
		fp = fopen(file_name, "r");
		if( fp == NULL ){
			perror("Unable to read data from file\n");
			return -1;
		}
		else{
			return fread( ptr, size, count, fp );
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
	int lock_PID;
	FILE *fp;
	
	lock_PID = mutex_check_lock( file_name );

	/* Read function should proceed only if the current process owns the lock on the file */
	if( lock_PID == getpid() ){
		fp = fopen(file_name, "a");
		if( fp == NULL ){
			perror("Unable to write data to file\n");
			return -1;
		}
		else{
			return fwrite( ptr, size, count, fp );
		}
	}
	else{
		perror("Current process does not own the lock");
		return -1;
	}
}
