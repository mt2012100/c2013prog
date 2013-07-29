/*
 * Implementation of Two-byte character strings (DBCS).
 * Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "multibytestring.h"

/* Helper functions */
/* Create a new multibyte from a byte character */
char* create_multibyte(char c) {
  
  int idx ;

  /* ADD MISSING CODE HERE */
  /* Allocate memory for dest for a string of size CHARSIZE
   * Assign value for string represented by dest, such that 
   * c occupies the first byte in dest; and other bytes
   * are assigned to NULL
   */
  char *dest = ;

  return dest ;
}

/* Bytewise comparison of 2 strings */
int bytewise_equal(char *c1, char *c2, int ssize) {
  int idx ;
  /* ADD MISSING CODE HERE */
  /* Return 0 if corresponding bytes of given 
   * strings do not match; if all bytes from first
   * byte to ssize-th byte match, return 1
   */
}

/* Print buffer in hex */
void print_mbs_hex(struct multibytestring *mbs) {
  
  int nbytes = CHARSIZE*mbs->size, idx ;
  printf("Size %d : ", mbs->size) ;
  if (mbs->data)
    for (idx = 0 ; idx < nbytes ; idx++)
      printf("%x ", mbs->data[idx]) ;
  printf("\n") ;

  return ;
}

/* Create/Conversion functions */
/* Initialize multibyte string */
struct multibytestring* initialize_mbs(void) {
  struct multibytestring *dest = (struct multibytestring*)
    malloc (sizeof(struct multibytestring*)) ;
  
  dest->size = 0 ;
  dest->data = NULL ;

  return dest ;
}

/* Create a new multibytestring */
struct multibytestring* create_mbs(char *istr) {

  struct multibytestring *dest = NULL ;
  int idx = 0, midx ;
  int ssize = strlen(istr), mbsize = 0, nbytes ;
  char *mbyte, *final = NULL, *tmp ;

  while (idx < ssize) {
    mbyte = NULL ;

    /* Check if the current byte is a character */
    if (/* ADD MISSING CODE HERE */) {
      mbyte = create_multibyte(istr[idx++]) ;

    } else if (idx < ssize-1) {
      /* ADD MISSING CODE HERE */
      /* Assign mbyte to be a string of size CHARSIZE 
       * excluding the null-termination, which will be
       * a substring starting from the current character 
       * in istr
       */
    }

    if (mbyte) {
      /* ADD MISSING CODE HERE */
      /* Append mbyte to final and assign the concatenated string 
       * to final
       */

      free(mbyte) ;
      mbsize++ ;
    }
  }

  if (mbsize) {
    dest = (struct multibytestring*) malloc(sizeof(struct multibytestring)) ;
    dest->size = mbsize+1 ;
    nbytes = CHARSIZE*mbsize ;

    /* Adding CHARSIZE number of null-terminated characters for
     * the usual null-termination in a string
     */
    dest->data = (char*)malloc(sizeof(char)*(nbytes+CHARSIZE)) ;
    for (idx = 0 ; idx < nbytes ; idx++)
      dest->data[idx] = final[idx] ;
    for (idx = 0 ; idx < CHARSIZE ; idx++)
      dest->data[idx+nbytes] = '\0' ;

    free(final) ;      
  }
  return dest ;
}

/* Convert to ascii */
char* mbstoascii(struct multibytestring *mbs) {

  int idx, cidx, nbytes ;
  char *substr ;
  char *dest = (mbs->size==0) ? NULL : (char*) malloc(sizeof(char)*mbs->size) ;

  if (mbs->size == 0) return NULL ;
  substr = (char*) malloc(sizeof(char)*(CHARSIZE+1)) ;
  
  /* ADD MISSING CODE HERE */
  /* Extract CHARSIZE block of bytes from mbs->data,
   * convert them to respective ASCII characters,
   * and append to dest
   */

  free(substr) ;
  return dest ;
}


/* String functions */
/* Copy function */
struct multibytestring* mbstrcpy(struct multibytestring *s1, const struct multibytestring *s2) {

  int nbytes, idx ;

  if (s1->size) 
    free(s1->data) ;

  s1->size = s2->size ;
  /* ADD MISSING CODE HERE */
  /* Copy values from s2->data to s1->data bytewise */

  return s1 ;
}

/* Concatenate function */
struct multibytestring* mbstrcat(struct multibytestring *s1, 
				 const struct multibytestring *s2) {

  int n1bytes, n2bytes, idx, bidx ;
  char *temp_s1_data ;

  /* ADD MISSING CODE HERE */
  /* Append s2->data to s1->data; reassign s1->data to be the 
   * concatenated string, update s1->size
   */

  return s1 ;
}

/* Compare functions */
int mbstrcmp(struct multibytestring *s1,
	     struct multibytestring *s2) {

  if (s1->size != s2->size) return 0 ;
  return (bytewise_equal(s1->data, s2->data, CHARSIZE*s1->size)) ;
}

/* Compare functions by number of characters */
int mbstrncmp(struct multibytestring *s1,
	      struct multibytestring *s2, 
	      int n) {

  int nbytes ;
  if (s1->size != s2->size) return 0 ;
  nbytes = (n <= s1->size) ? CHARSIZE*n : CHARSIZE*s1->size ;
  return (bytewise_equal(s1->data, s2->data, nbytes)) ;
}

/* EOF */
