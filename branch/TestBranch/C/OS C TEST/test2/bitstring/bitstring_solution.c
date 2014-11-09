 /*

  * File: bitstring.c
  * Description: This is a simple implementation of bitstrings of arbitrary length in C
  */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "bitstring.h"

#define DEBUG_INT(msg, value) fprintf(stderr, "%s %d\n", msg, value)
#define DEBUG_STR(msg, value) fprintf(stderr, "%s %s\n", msg, value)

struct bitstring create_bitstring( int size, char *istr )
{
	int str_ndx, bit_ndx, arr_size;
	struct bitstring bstr;

	assert( strlen(istr) <= size );
 
	arr_size = (size-1) / 8 + 1;

	DEBUG_INT( "arr_size = ", arr_size );

	bstr.size = size;
	DEBUG_INT ( "size = ", size ) ;

	bstr.buffer = (unsigned char*) malloc( sizeof(unsigned char)*arr_size );
	
	/* Start from the last bit */
	for( bit_ndx = 0, str_ndx = strlen(istr)-1; str_ndx >= 0; str_ndx--, bit_ndx++ ){
		set_bit( bstr, bit_ndx, istr[str_ndx] );
	}
	return bstr;
}

struct bitstring copy_bitstring( struct bitstring bstr )
{
	int arr_size, ndx;
	struct bitstring newbstr;

	arr_size = (bstr.size-1) / 8 + 1;

	newbstr.size = bstr.size;
	newbstr.buffer = (unsigned char*) malloc( sizeof(unsigned char)*arr_size );

	for( ndx = 0; ndx < arr_size; ndx++ )
		newbstr.buffer[ndx] = bstr.buffer[ndx];

	return newbstr;
}

char* print_byte( unsigned char x )
{
	static char b[8] = {0};
	int y, z;

	for( z=128,y=0; z > 0; z>>=1,y++ ){
		b[y] = ( ((x & z) == z) ? '1' : '0');
	}
	return b;
}

char *print_bitstring( struct bitstring bstr, char *output )
{
	int bndx, ondx, bit, arr_size;
	char *b;

	arr_size = (bstr.size-1) / 8 + 1;

	ondx = 0;
	for( bndx = arr_size-1; bndx >= 0; bndx-- ){
		b = print_byte( bstr.buffer[bndx]);	
		for( bit = 0; bit < 8; bit++ )
			output[ondx++] = b[bit];
	};
	output[ondx] = '\0';
	return output;
}

unsigned char get_bit( struct bitstring str, int pos )
{
	unsigned char bit;
	int arr_ndx = pos / 8;
	int bit_ndx =  pos % 8;

	assert(pos < str.size);

	bit = str.buffer[arr_ndx] & (1 << bit_ndx);

	return bit>>bit_ndx;
}

struct bitstring set_bit( struct bitstring str, int pos,
			  unsigned char bitvalue )
{
	int arr_ndx = pos / 8;
	int bit_ndx =  pos % 8;
	char output[100];

	assert(pos <= str.size);

	if( bitvalue == '0' ){
		str.buffer[arr_ndx] &= ~(1 << bit_ndx);
	}
	else if( bitvalue == '1' ){
		str.buffer[arr_ndx] |= (1 << bit_ndx);
	}
	else
		DEBUG_INT("Error: Invalid bitvalue encountered", bitvalue);
	
	DEBUG_STR("After setbit ", print_bitstring(str, output));
	return str ;
}

