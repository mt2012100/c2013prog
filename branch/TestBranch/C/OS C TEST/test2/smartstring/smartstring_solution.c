/*
 * File: smartstring.c
 * Description: Contains the code for smart string implementation in C language
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<string.h>
#include<assert.h>

#include "smartstring.h"

/*************************************************************************/
/* Some useful functions */
/*************************************************************************/

/* Free the string and assign the hidden pointer to NULL */
void str_free( struct SString input )
{
	if( input.hidden_string != '\0' ){
		free( input.hidden_string );
		input.hidden_string = '\0';
		input.arr_size = 0;
	}
}

/* Programs should never access hidden_string directly; instead they must call this 
  * for accessing the string for printing , etc.
     Returns a non-modifiable string */
const char *str_get( struct SString input )
{
	return input.hidden_string;
}

/*************************************************************************/
/* Programs would never use malloc() function. */
/* In additon, programs would never call strcpy directly 
  * Instead, they will call this different variations of str_copy function
 */
/*************************************************************************/

/* Create a string by copying from another character array */
struct SString str_copy_01( char *charstr )
{
	struct SString sstr;
	int strsize;
	
	if( charstr == '\0' ){
		sstr.hidden_string = '\0';
		sstr.arr_size = 0;
		return sstr;
	}
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
		sstr.hidden_string = '\0';
		sstr.arr_size = 0;
		return sstr;
	}
		
	sstr = str_copy_01( inputstr.hidden_string );
	
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
	
	strsize = 0 ;
	
	sstr.hidden_string = (char *) malloc(sizeof(char)*(strlen(str1)+strlen(str2)+1));

	if( str1 != '\0' ){
		strsize += strlen( str1 );
		strcpy( sstr.hidden_string, str1 );
	}
	
	if( str2 != '\0' ){
		strsize += strlen( str2 );
		strcat( sstr.hidden_string, str2 );
	}
	sstr.arr_size = strsize + 1;
	
	return sstr;
}

/* Append source SString into target SString and return the new string */
struct SString str_join_02( struct SString sstr1, struct SString sstr2 )
{
	struct SString sstr;

	sstr = str_join_01( sstr1, sstr2.hidden_string );
	
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
	
	strsize = end_ndx - start_ndx + 1;
	sstr.hidden_string = (char *) malloc(sizeof(char)*(strsize+1));
	sstr.arr_size = strsize + 1;
	
	for( i = start_ndx, j = 0; i <= end_ndx; i++, j++ ){
		sstr.hidden_string[j] = input.hidden_string[i];
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
		
	end_ndx = start_ndx + num_chars - 1;
	sstr = str_substring_01( input, start_ndx, end_ndx );
	
	return sstr;
}
