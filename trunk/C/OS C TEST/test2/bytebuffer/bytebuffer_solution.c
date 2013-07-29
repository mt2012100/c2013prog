/*
 * File : bytebuffer.c
 * Implementation of buffer of bytes of arbitrary size similar to Java ByteBuffer.
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "bytebuffer.h"

/* Allocate a new bytebuffer of given size. */
struct bytebuffer allocate_bytebuffer( int bsize ) {
	struct bytebuffer new_bb ;
	new_bb.buffersize = bsize ;
	new_bb.buffer = (unsigned char*) malloc (sizeof(unsigned char)*bsize) ;
	
	return new_bb ;
}

/* Create a new bytebuffer of the given size and initialize with the values given in the input string */
struct bytebuffer create_bytebuffer( int bsize, unsigned char *istr ) {
	struct bytebuffer new_bb ;
	assert (sizeof(istr) <= bsize) ;

	new_bb = allocate_bytebuffer(bsize) ;
	put_bytes_bulk_relative(new_bb, istr, 0, 0, bsize) ;

	return new_bb ;
}

/* Wraps existing byte array into a buffer.
 * Changes in the buffer will be reflected in the array and vice-versa.
 */
struct bytebuffer wrap_bytebuffer( int bsize, unsigned char arr[] ) {
	struct bytebuffer new_bb ;
	new_bb.buffer = &arr[0] ;
	new_bb.buffersize = bsize ;
	return new_bb ;
}

/* Delete existing bytebuffer.
 * Simple delete function which need not update the bytebuffers sharing the buffer.
 */
void delete_bytebuffer( struct bytebuffer *bbuff ) {
	assert(bbuff->buffer != NULL) ;
	free(bbuff->buffer) ;
	bbuff->buffer = NULL ;
	bbuff->buffersize = 0 ;
	return ; 
}

/* Duplicates the input bytebuffer into another bytebuffer, changes in former will be seen 
 * in latter. Output: A bytebuffer.
 */
struct bytebuffer duplicate_bytebuffer( struct bytebuffer bbuff ) {
	struct bytebuffer new_bb ;

	new_bb.buffer = bbuff.buffer ;
	new_bb.buffersize = bbuff.buffersize ;

	return new_bb ;
}

/* Extracts the byte at the given position in the given bytebuffer
 * Output is a byte
 */
unsigned char get_byte( struct bytebuffer str, int pos ) {
	assert(str.buffer != NULL) ; 
	assert(pos < str.buffersize) ;
	return str.buffer[pos] ;
}

/* Extracts bytes from a byte buffer to an array.
 * Output is a byte array.
 */
unsigned char* get_bytes_bulk( struct bytebuffer str ) {
	int idx ;
	unsigned char *output ;

	assert(str.buffer != NULL) ;
	output = (unsigned char*) malloc (sizeof(unsigned char)*str.buffersize) ;
	for (idx = 0 ; idx < str.buffersize ; idx++)
		output[idx] = str.buffer[idx] ;

	return output ;
}

/* Extracts bytes at a given position for a given length.
 * Output is a byte array.
 */
unsigned char* get_bytes_bulk_relative( struct bytebuffer str, int offset, int length ) {
	int idx, didx ;
	unsigned char *output ;

	assert(str.buffer != NULL) ;
	assert(offset < str.buffersize && offset+length <= str.buffersize) ;

	output = (unsigned char*) malloc (sizeof(unsigned char)*length) ;
	for (idx = offset, didx = 0 ; didx < length ; didx++, idx++)
		output[didx] = str.buffer[idx] ;
	return output ;
}


/* Set a byte in a given position in the byte buffer */
void put_byte( struct bytebuffer str, int pos, unsigned char value) {
	assert(str.buffer != NULL) ;
	assert(pos < str.buffersize) ;
	str.buffer[pos] = value ;
	return ;
}

/* Set bytes from given position in bytebuffer from a given array */
void put_bytes_bulk( struct bytebuffer str, int pos, int value_size, unsigned char *value ) {
	int idx, v_idx, idx_limit ;

	assert(str.buffer != NULL) ;
	assert(pos < str.buffersize) ;
	
	/* Maximum limit for index for copying into buffer */
	idx_limit = (pos+value_size > str.buffersize) ? str.buffersize : pos+value_size ;
	for (v_idx = 0, idx = pos; idx < idx_limit ; idx++, v_idx++)
		str.buffer[idx] = value[v_idx] ;

	return ;
}


/* Sets the bytes from given position in bytebuffer for given number of bytes from 
 * a given position in a given string.
 */
void put_bytes_bulk_relative( struct bytebuffer str, unsigned char *value, 
			      int bstart_pos, int vstart_pos, int strsize) {
	int idx, vidx ;
	int bstart = bstart_pos, bend = bstart_pos+strsize ;
	int vstart = vstart_pos, vend = vstart_pos+strsize ;

	assert(str.buffer != NULL) ;
	assert(bstart < str.buffersize && bend <= str.buffersize) ;

	for (idx = bstart, vidx = vstart ; vidx < vend ; idx++, vidx++)
		str.buffer[idx] = value[vidx] ;
	return ;
}

