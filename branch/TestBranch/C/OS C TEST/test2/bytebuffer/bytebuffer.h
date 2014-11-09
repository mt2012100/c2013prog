/* File: bytebuffer.h
 * Implementation of buffer of bytes of arbitrary size similar to Java ByteBuffer.
 */

struct bytebuffer {
  unsigned char *buffer ; /* Buffer for data */
  int buffersize ;        /* Size of the buffer */
} ;

/* Allocate a new bytebuffer of given size. */
struct bytebuffer allocate_bytebuffer( int bsize ) ;

/* Create a new bytebuffer of the given size and initialize with the values given in the input string. */
struct bytebuffer create_bytebuffer( int bsize, unsigned char *istr );

/* Wraps existing byte array into a buffer.
 * Changes in the buffer will be reflected in the array and vice-versa.
 */
struct bytebuffer wrap_bytebuffer( int bsize, unsigned char arr[] ) ;

/* Delete existing bytebuffer.
 * Simple delete function which need not update the bytebuffers sharing the buffer.
 */
void delete_bytebuffer( struct bytebuffer *bbuff ) ;

/* Duplicates the input bytebuffer into another bytebuffer, changes in former will be seen 
 * in latter. Output: A bytebuffer.
 */
struct bytebuffer duplicate_bytebuffer( struct bytebuffer bbuff ) ;

/* Extracts the byte at the given position in the given bytebuffer.
 * Output is a byte.
 */
unsigned char get_byte( struct bytebuffer str, int pos );

/* Copy all the bytes from buffer to an array.
 * Output is a byte array.
 */
unsigned char* get_bytes_bulk( struct bytebuffer str ) ;

/* Extracts bytes at a given position for a given length.
 * Output is a byte array.
 */
unsigned char* get_bytes_bulk_relative( struct bytebuffer str, int offset, int length ) ;

/* Set a byte in a given position */
void put_byte( struct bytebuffer str, int pos, unsigned char value ) ;

/* Set bytes from given position in bytebuffer from a given array */
void put_bytes_bulk( struct bytebuffer str, int pos, int value_size, unsigned char *value ) ;

/* Sets the bytes from given position in bytebuffer for a given number of bytes from 
 * a given position in a given string. 
 */
void put_bytes_bulk_relative( struct bytebuffer str, unsigned char *value, 
			      int bstart_pos, int vstart_pos, int strsize) ;

