#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "smartstring.h"

#define IAMHERE printf("At %s:%d\n", __FILE__, __LINE__)

int main()
{
	struct SString str1, str2, str3, str4;
	
	str2 = str_copy_01("Hello world");
	assert( strcmp( str_get(str2), "Hello world" ) == 0 );
	IAMHERE;
	
	str3 = str_copy_02(str2);
	assert( strcmp( str_get(str3), "Hello world" ) == 0 );
	IAMHERE;
	
	str4 = str_join_02( str2, str3 );
	assert( strcmp( str_get(str4), "Hello worldHello world" ) == 0 );
	IAMHERE;
	
	str_free( str2 );
	IAMHERE;

	str2 = str_join_01( str4, "Hello world" );
	assert( strcmp( str_get(str2), "Hello worldHello worldHello world" ) == 0 );
	IAMHERE;
	
	str1 = str_substring_01( str2, 0, 100 );
	assert( strcmp( str_get(str1), "Hello worldHello worldHello world" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_01( str2, -1, 100 );
	assert( strcmp( str_get(str1), "Hello worldHello worldHello world" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_01( str2, 0, -1 );
	assert( strcmp( str_get(str1), "H" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_01( str2, 11, 15 );
	assert( strcmp( str_get(str1), "Hello" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_02( str2, 0, 100 );
	assert( strcmp( str_get(str1), "Hello worldHello worldHello world" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_02( str2, -1, 100 );
	assert( strcmp( str_get(str1), "Hello worldHello worldHello world" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_02( str2, 0, -1 );
	assert( strcmp( str_get(str1), "H" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	str1 = str_substring_02( str2, 11, 5 );
	assert( strcmp( str_get(str1), "Hello" ) == 0 );
	str_free( str1 );
	IAMHERE;
	
	printf("Completed executing the test cases\n");
	return 0 ;
}
 
/* Create an empty string */
struct SString str_create_01();

/* Create a string of given size (excluding '\0')  */
struct SString str_create_02( int max_size );

/*************************************************************************/
/* Programs would never call strcpy directly 
  * Instead, they will call this different variations of str_copy function
 */
/*************************************************************************/

/* Create a string by copying from another character array */
struct SString str_copy_01( char *charstr );

/* Create a string by copyiing from another SString */
struct SString str_copy_02( struct SString sstr );

/*************************************************************************/
/* Programs would never call strcat directly 
  * Instead, they will call this different variations of str_append function
 */
/*************************************************************************/

/* Append source character array into target SString and return the new string */
struct SString str_append_01( struct SString target, char *source );

/* Append source SString into target SString and return the new string */
struct SString str_append_02( struct SString target, struct SString source );

/*************************************************************************/
/* Substring functions  */
/*************************************************************************/

/* Returns a substring starting from start_ndx position and ending at end_ndx */
/* If start_ndx or end_ndx is less than zero, they are treated as zero */
/* If end_ndx is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_01( struct SString input, int start_ndx, int end_ndx );

/* Returns a substring having num_chars starting from start_ndx position */
/* If start_ndx or num_chars is less than zero, they are treated as zero */
/* If num_chars is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_02( struct SString input, int start_ndx, int num_chars );
