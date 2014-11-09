 /*
  * File: bitstring.h
  * Description: This is a simple implementation of bitstrings of arbitrary 
  * length in C
  */

/* Data structure */
struct bitstring{
  unsigned char *buffer; /* Data of the bitstring in chars */
  int size;              /* Desired length of bitstring */
};

/* Create a new bitstring of the given size and initialize with the values 
 * given in the input string 
 */
struct bitstring create_bitstring( int size, char *istr );

/* Copies the input bitstring into another bitstring and returns the same */
struct bitstring copy_bitstring( struct bitstring bstr );

/* Prints the given bitstring in c string form which is 
 * human-readable 
 */
char * print_bitstring( struct bitstring str, char *output );

/* Extracts the bit at the given position in the given bitstring
 * Output is a binary value (0 or 1)
 */
unsigned char get_bit( struct bitstring str, int pos );

/* Sets the bit at the given position with the given bitvalue
 * bitvalue is binary
 */
struct bitstring set_bit( struct bitstring str, int pos, 
			  unsigned char bitvalue );

