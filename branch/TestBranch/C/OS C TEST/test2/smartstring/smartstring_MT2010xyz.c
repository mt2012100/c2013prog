/*
 * File: smartstring.c
 * Description: Contains the code for smart string implementation in C language
  * Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
*/

#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<assert.h>

#include "smartstring.h"

/* A useful macro for debugging that will print the current line number */

#define IAMHERE printf("At %s:%d\n", __FILE__, __LINE__)

/*************************************************************************/
/* Programs would never use malloc() and free() functions.
 * Instead, they create a new pointer using different variations of str_create by passing relevant arguments 
 * See sample main program for examples
 */
/*************************************************************************/

/* Free the string and assign the hidden pointer to NULL */
void str_free( struct SString input )
{
	/* The if statement guards against freeing a null pointer */
       if( /* ADD MISSING CODE HERE */ input.hidden_string !='\0'){
		free( input.hidden_string );
		input.hidden_string = '\0';
		input.arr_size = 0;
	}
}

/* Programs should never access hidden_string directly; instead they must call this 
 * for accessing the string for printing , etc.
 * Returns a non-modifiable string 
 */
const char *str_get( struct SString input )
{
	/*ADD MISSING CODE HERE */
}

/*************************************************************************/
/* Programs would never call strcpy directly 
 * Instead, they will call this different variations of str_copy function
 */
/*************************************************************************/

/* Create a string by copying from another character array */
struct SString str_copy_01( char *charstr )
{
	struct SString sstr;
	int strsize;
	
	if( charstr == '\0' ){
                              sstr.hidden_string='\0';
                              sstr.arr_size=0;  
                             
			/* ADD MISSING CODE HERE */
			/* Initialize sstr properly before returning */
			
			
			return sstr;
	}
		
	/* ADD MISSING CODE HERE */
	/* Allocate memory properly to sstr and copy the data from charstr */
	strsize = strlen( charstr );
	sstr.hidden_string = (char *) malloc(sizeof(char)*(strsize+1));
	strcpy( sstr.hidden_string, charstr );
	sstr.arr_size = strsize + 1;
	
	assert( sstr.arr_size == strlen(charstr)+1 );
	
	return sstr;
}

/* Create a string by copying from another SString */
struct SString str_copy_02( struct SString inputstr )
{
	struct SString sstr;

	if( inputstr.hidden_string == '\0' ){
			/* ADD MISSING CODE HERE */
			/* Initialize sstr properly before returning */
			sstr.hidden_string='\0';
                        sstr.arr_size=0; 
			return sstr;
	}
		
	/* ADD MISSING CODE HERE */
	/* Simply make a call to str_copy_01 with appropriate arguments here! */
	
          sstr=str_copy_01(inputstr.hidden_string);   
	
	assert( sstr.arr_size == strlen( sstr.hidden_string ) + 1 );
	
	return sstr;
}

/*************************************************************************/
/* Programs would never call strcat directly 
  * Instead, they will call this different variations of str_join function
 */
/*************************************************************************/

/* Combine the input strings and return the new string */
struct SString str_join_01( struct SString sstr1, char *sstr2 )
{
	struct SString sstr;
	int strsize;
	char *str1, *str2;
	
	str1 = sstr1.hidden_string;
	str2 = sstr2;
	
	strsize = 0;
	
	/* ADD MISSING CODE HERE */
	/* Add approrpiate error handling for null pointer values of str1 and str2 */
	/* Allocate right amount of memory, join the strings and return the new string */
	
	
	
	
	
	return sstr;
}

/* Append source SString into target SString and return the new string */
struct SString str_join_02( struct SString sstr1, struct SString sstr2 )
{
	struct SString sstr;
        sstr=str_join_01(sstr1,sstr2.hidden_string)

	/* ADD MISSING CODE HERE */
	/* Simply make a call to str_join_01 with appropriate arguments here! */
	
	return sstr;
}

/* Returns a substring starting from start_ndx position and ending at end_ndx */
/* If start_ndx or end_ndx is less than zero, they are treated as zero */
/* If end_ndx is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_01( struct SString input, int start_ndx, int end_ndx )
{
	struct SString sstr;
	int strsize;
	int i, j;
	
	sstr.hidden_string = '\0';
	
	if( input.hidden_string == '\0' )
		return sstr;
		
	if( start_ndx < 0 )
		start_ndx = 0;
	
	if( end_ndx < 0 )
		end_ndx = 0;
		
	if( end_ndx >= input.arr_size )
		end_ndx = input.arr_size - 1;
	
	strsize =end_ndx-start_ndx+1; //ADD MISSING CODE HERE"
	
	sstr.hidden_string = (char *) malloc(sizeof(char)*(strsize+1));
	sstr.arr_size = strsize + 1;
	
	for( i = start_ndx/*ADD MISSING CODE HERE*/, j = 0; i <= end_ndx/*ADD MISSING CODE HERE*/; i++, j++ ){
	  /*ADD MISSING CODE HERE */
           sstr.hidden_string[j]=sstr.hidden_string[i];
	  /* Assign values for sstr.hidden_string */
	}
	sstr.hidden_string[j] = '\0';
	
	return sstr;
}

/* Returns a substring having num_chars starting from start_ndx position */
/* If start_ndx or num_chars is less than zero, they are treated as zero */
/* If num_chars is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_02( struct SString input, int start_ndx, int num_chars )
{
	struct SString sstr;
	int end_ndx;
	
	if( start_ndx < 0 )
		start_ndx = 0;
	
	if( num_chars < 0 )
		end_ndx = 0;
		
	end_ndx = ADD MISSING CODE HERE;
        sstr=str_substring_01(input,start_ndx,end_ndx)
	
	/* ADD MISSING CODE HERE */
	/* Simply make a call to str_substring_01 with appropriate arguments here! */

	
	return sstr;
}
