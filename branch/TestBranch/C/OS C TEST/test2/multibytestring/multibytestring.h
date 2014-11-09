/*
 * Implementation of Two-byte character strings (DBCS).
 *
 * Each char will be represented as a 2-byte data. If the 
 * character needs only a single byte then it is represented
 * as the first byte, and the second byte is '\0'. It will be 
 * assumed that any input string that has to be converted to 
 * multibyte string does not contain characters that occupy 
 * more than 2 bytes.
 */


#define CHARSIZE 2

struct multibytestring {
  char *data ;  /* Expanded string with CHARSIZE bytes for each character */
  size_t size ; /* Total number of 2-bytes including the null-termination */
} ;

/* Helper functions */
/* Create a new multibyte from a byte character */
char* create_multibyte(char c) ;

/* Bytewise comparison of 2 strings */
int bytewise_equal(char *c1, char *c2, int ssize) ;

/* Print buffer in hex */
void print_mbs_hex(struct multibytestring *mbs) ;

/* Create/conversion functions */
/* Initialize multibyte string */
struct multibytestring* initialize_mbs(void) ;

/* Create a new multibytestring */
struct multibytestring* create_mbs(char *istr) ;

/* Convert to ascii */
char* mbstoascii(struct multibytestring *mbs) ;

/* String functions */
/* Copy function */
struct multibytestring* mbstrcpy(struct multibytestring *s1, 
				 const struct multibytestring *s2) ;

/* Concatenate function */
struct multibytestring* mbstrcat(struct multibytestring *s1, 
				 const struct multibytestring *s2) ;

/* Compare function */
int mbstrcmp(struct multibytestring *s1,
	     struct multibytestring *s2) ;

/* Compare functions by number of characters */
int mbstrncmp(struct multibytestring *s1,
	      struct multibytestring *s2, 
	      int n) ;

/* EOF */
