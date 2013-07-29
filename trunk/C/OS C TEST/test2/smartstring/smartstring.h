/*
 * File: sstring.h
 * Description: Contains the header declarations for smart string implementation in C language
 */
 
/* Structure declaration for the smart string abstraction */
struct SString{
	char *hidden_string; /* Internal representation as a character array */
	int arr_size; /* Current size of the character array. */
};

/*************************************************************************/
/* Some useful functions                                                 */
/*************************************************************************/

/* Programs should never access hidden_string directly; instead they must call this 
 * for accessing the string for printing , etc.
 * Returns a non-modifiable string */
const char *str_get( struct SString input );

/* Frees the memory allocated to a smart string and assign the hidden pointer to NULL */
void str_free( struct SString input );

/* Create a string by copying from another character array */
struct SString str_copy_01( char *charstr );

/* Create a string by copyiing from another SString */
struct SString str_copy_02( struct SString sstr );

/*************************************************************************/
/* Programs would never call strcat directly 
 * Instead, they will call this different variations of str_join function
 */
/*************************************************************************/

/* Combine the input strings and return the new string */
struct SString str_join_01( struct SString sstr1, char *sstr2 );

/* Combine the input strings and return the new string */
struct SString str_join_02( struct SString sstr1, struct SString sstr2 );

/*************************************************************************/
/* Substring functions                                                   */
/*************************************************************************/

/* Returns a substring starting from start_ndx position and ending at end_ndx */
/* If start_ndx or end_ndx is less than zero, they are treated as zero */
/* If end_ndx is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_01( struct SString input, int start_ndx, int end_ndx );

/* Returns a substring having num_chars starting from start_ndx position */
/* If start_ndx or num_chars is less than zero, they are treated as zero */
/* If num_chars is beyond the end of the string, it is treated as the index of end of the string */

struct SString str_substring_02( struct SString input, int start_ndx, int num_chars );
