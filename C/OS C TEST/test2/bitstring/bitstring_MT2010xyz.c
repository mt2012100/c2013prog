/*
 * File: bitstring.c
 * Description: This is a simple implementation of bitstrings of arbitrary 
 * length in C. A given string "1010" for a bitstring of size 5 will give a 
 * bitstring "00001010".
 * Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "bitstring.h"

#define DEBUG_INT(msg, value) fprintf(stderr, "%s %d\n", msg, value)
#define DEBUG_STR(msg, value) fprintf(stderr, "%s %s\n", msg, value)

/* Create a new bitstring of the given size and initialize with the values 
 * given in the input string 
 */
struct bitstring create_bitstring( int size, char *istr )
{
	int arr_ndx, str_ndx, bit_ndx, arr_size;
	struct bitstring bstr;
	char output[100];

	assert( strlen(istr) <= size );

	/* ADD MISSING CODE HERE */ 
	/* How many bytes will be occupied by a bitstring of given size? */
	arr_size = 

	DEBUG_INT( "arr_size = ", arr_size );

	/* ADD MISSING CODE HERE */ 
	/* Allocate memory to the bstr.buffer */

	bstr.size = size;

	/* Assign values to bits, starting from the last bit in the 
	 * given string.
	 */
	/* bit_ndx is the location of the bit in the bitstring;
	 * for instance second bit in second byte will have bit_ndx=9.
	 */
	for( bit_ndx = 0, str_ndx = strlen(istr)-1; str_ndx >= 0; 
	     str_ndx--, bit_ndx++ ){
	  /* ADD MISSING CODE HERE */ 
	  /* Call set_bit here with appropriate arguments */
	}
	return bstr;
}

/* Copies the input bitstring into another bitstring and returns the same */
struct bitstring copy_bitstring( struct bitstring bstr )
{
	int arr_size, ndx;
	struct bitstring newbstr;

	arr_size = (bstr.size-1) / 8 + 1;
	newbstr.size = bstr.size;

	/* ADD MISSING CODE HERE */ 
	/* Allocate memory to newbstr.buffer */

	/* ADD MISSING CODE HERE */ 
	/* Copy each byte one by one in a for-loop */

	return newbstr;
}

/* Prints one byte of data in human-readable form */
char* print_byte( unsigned char x )
{
	static char b[8] = {0};
	int y, z;

	for( z=128,y=0; z > 0; z>>=1,y++ ){
		b[y] = ( ((x & z) == z) ? '1' : '0');
	}
	return b;
}

/* Prints the given bitstring in c string form which is 
 * human-readable 
 */
char *print_bitstring( struct bitstring bstr, char *output )
{
	int bndx, ondx, bit, arr_size;
	char *b;

	/* Find number of bytes */
	arr_size = (bstr.size-1) / 8 + 1;

	/* Write to output one byte at a time, 
	 * starting from the last byte
	 */
	ondx = 0;
	for( bndx = arr_size-1; bndx >= 0; bndx-- ){
		b = print_byte( bstr.buffer[bndx]);	
		for( bit = 0; bit < 8; bit++ )
			output[ondx++] = b[bit];
	};
	output[ondx] = '\0';
	return output;
}

/* Extracts the bit at the given position in the given bitstring
 * Output is a binary value (0 or 1)
 */
unsigned char get_bit( struct bitstring str, int pos )
{
	unsigned char bit;

	/* ADD MISSING CODE HERE */ 
	/* Find the location of byte in the bit array */
	int arr_ndx = 
	/* Find location of bit in a byte */
	int bit_ndx =

	assert(pos < str.size);

	/* ADD MISSING CODE HERE */ 
	/* Extract the bit from the approrpiate byte indicate by arr_ndx */

	return bit;
}

/* Sets the bit at the given position with the given bitvalue 
 * bitvalue is binary 
 */
struct bitstring set_bit( struct bitstring str, int pos, unsigned char bitvalue )
{
        /* ADD MISSING CODE HERE */ 
        /* Find the location of byte in the bit array */
        int arr_ndx = 
        /* Find location of bit in a byte */
	int bit_ndx =
	
	char output[100];

	assert(pos <= str.size);
	assert(bitvalue == 0 || bitvalue == 1);

	if( bitvalue == '0' ){
		str.buffer[arr_ndx] &= ~(1 << bit_ndx);
	}
	else if( bitvalue == '1' ){
		/* ADD MISSING CODE HERE */ 
		/* How to set a specific bit in the byte indicated by arr_ndx? */
	}
	else
		DEBUG_INT("Error: Invalid bitvalue encountered", bitvalue);
	
	DEBUG_STR("After setbit ", print_bitstring(str, output));
}

