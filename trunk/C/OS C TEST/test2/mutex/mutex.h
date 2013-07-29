/* File: mutex.h
      Description: A very primitive implementation of mutual exclusion API
*/

/* Locks the given file descriptor.  	
     Return 0 on success, 1 on failure (in case of invalid file descriptor or mode)
*/
int mutex_lock( char *file_name );

/* Releases the lock on the given file descriptor     Return 0 on success, 1 on failure
*/
int mutex_unlock( char *file_name );

/* Finds the type of lock that is existing on the given file */
/* 	Returns process id of the process that has established the lock.
	Returns -1 if there is no active lock
*/
int mutex_check_lock( char *file_name );

/* Read with mutex semantics */
/* A wrapper around fread */
/* Will always read from the beginning of the file only */
int mread( void *ptr, size_t size, size_t count, char* file_name );

/* Write with mutex semantics */
/* A wrapper around fwrite */
/* Will always write at the end of the file (append) only */
size_t mwrite ( const void * ptr, size_t size, size_t count, char* file_name );
